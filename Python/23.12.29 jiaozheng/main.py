import cv2
import glob
import numpy as np

objpoints_img = []  # 保存棋盘格上角点的三维坐标
obj_world_pts = []  # 三维世界坐标
images_points = []  # 保存所有角点

BOARDSIZE = (9, 6)  # 棋盘格每行每列角点个数

# 转世界坐标系
for i in range(BOARDSIZE[1]):
    for j in range(BOARDSIZE[0]):
        obj_world_pts.append((j, i, 0))

images_path = glob.glob("F:/Code/Python/23.12.29 jiaozheng/fix/*.jpg")  # 待处理图路径


for image_path in images_path:
    image = cv2.imread(image_path)

    if image is None:
        print(f"Failed to load image at {image_path}")
        continue

    img_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # 检测角点
    found_success, img_corner_points = cv2.findChessboardCorners(
        img_gray, BOARDSIZE, flags=cv2.CALIB_CB_ADAPTIVE_THRESH | cv2.CALIB_CB_FAST_CHECK | cv2.CALIB_CB_NORMALIZE_IMAGE
    )

    # 显示角点
    if found_success:
        criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)

        # 进一步提取亚像素角点
        cv2.cornerSubPix(img_gray, img_corner_points, (11, 11), (-1, -1), criteria)

        # 绘制角点
        cv2.drawChessboardCorners(image, BOARDSIZE, img_corner_points, found_success)

        objpoints_img.append(np.array(obj_world_pts, dtype=np.float32))
        images_points.append(img_corner_points)

    cv2.imshow("image", image)
    cv2.waitKey(200)

# 计算内参和畸变系数等
cameraMatrix = np.zeros((3, 3))
distCoeffs = np.zeros((5, 1))
rvecs = [np.zeros((3, 1)) for _ in range(len(images_path))]
tvecs = [np.zeros((3, 1)) for _ in range(len(images_path))]

_, cameraMatrix, distCoeffs, rvecs, tvecs = cv2.calibrateCamera(
    objpoints_img, images_points, img_gray.shape[::-1], cameraMatrix, distCoeffs, rvecs, tvecs
)

print("cameraMatrix:")
print(cameraMatrix)
print("*****************************")
print("distCoeffs:")
print(distCoeffs)
print("*****************************")
print("Rotation vectors:")
for rvec in rvecs:
    print(rvec)
print("*****************************")
print("Translation vectors:")
for tvec in tvecs:
    print(tvec)

# 畸变图像校准
src = cv2.imread("F:/Code/Python/23.12.29 jiaozheng/image3.jpg")
dst = cv2.undistort(src, cameraMatrix, distCoeffs)

cv2.imshow("image_dst", dst)
cv2.waitKey(100)
cv2.imwrite("F:/Code/Python/23.12.29 jiaozheng/fiximage3.jpg", dst)

cv2.destroyAllWindows()