
import cv2
import numpy as np

# image = cv2.imread('.\pictures\lena.jpg', cv2.IMREAD_GRAYSCALE)
# # 平滑图像
# image_blur = cv2.GaussianBlur(image, (3, 3), sigmaX=1, sigmaY=0)
# # Sobel算子1，dx=1，dy=0
# sobel_x = cv2.Sobel(image_blur, cv2.CV_64F, dx=1, dy=0, ksize=3)
# # Sobel算子2，dx=0，dy=1
# sobel_y = cv2.Sobel(image_blur, cv2.CV_64F, dx=0, dy=1, ksize=3)
# # Sobel算子3，dx=1，dy=1
# sobel_xy = cv2.Sobel(image_blur, cv2.CV_64F, dx=1, dy=1, ksize=3)
#
# cv2.imshow('Sobel X', cv2.resize(sobel_x, None, fx=0.6, fy=0.6))
# cv2.waitKey(0)
#
# cv2.imshow('Sobel Y', cv2.resize(sobel_y, None, fx=0.6, fy=0.6))
# cv2.waitKey(0)
#
# cv2.imshow('Sobel XY', cv2.resize(sobel_xy, None, fx=0.6, fy=0.6))
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# import cv2
#
# apple = cv2.imread('.\pictures\pt.jpg')
# image = cv2.cvtColor(apple, cv2.COLOR_BGR2GRAY)
# image_copy = apple.copy()
#
# retval, dst = cv2.threshold(image, 100, 255, cv2.THRESH_BINARY)
# contours, hierarchy = cv2.findContours(dst, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
# cv2.drawContours(image=image_copy, contours=contours, contourIdx=-1, color=(0, 255, 0), thickness=2)
#
# cv2.imshow('111', image_copy)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# import cv2
#
# # 读取图像
# image = cv2.imread('.\pictures\pt.jpg')
#
# # 将图像转化为灰度图像
# gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#
# # 对图像进行二值化
# _, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
#
# # 定义内核大小
# kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
#
# # 执行腐蚀操作
# eroded = cv2.erode(thresh, kernel, iterations=2)
#
# # 执行膨胀操作
# dilated = cv2.dilate(eroded, kernel, iterations=2)
#
# # 查找轮廓
# contours, hierarchy = cv2.findContours(dilated, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
#
# # 遍历轮廓
# for contour in contours:
#     # 计算轮廓的外接矩形
#     x, y, w, h = cv2.boundingRect(contour)
#
#     # 绘制矩形
#     cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
#
#     # 计算物体尺寸
#     length = max(w, h)
#     width = min(w, h)
#     print(f"Length: {length}, Width: {width} pixels")
#
# # 显示结果图像
# cv2.imshow('Result', image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

import cv2
import numpy as np


def calculate_distance(image_path, obj_width):
    # Load the image
    image = cv2.imread(image_path)

    # Convert to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Apply Gaussian blur
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    # Perform edge detection
    edges = cv2.Canny(blurred, 50, 150)

    # Find contours in the edge map
    contours, _ = cv2.findContours(edges.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Sort the contours by area in descending order
    contours = sorted(contours, key=cv2.contourArea, reverse=True)

    # Assuming the largest contour corresponds to the object of interest
    for contour in contours:
        # Approximate the contour as a rectangle
        peri = cv2.arcLength(contour, True)
        approx = cv2.approxPolyDP(contour, 0.02 * peri, True)

        if len(approx) == 4:
            # Get the bounding box coordinates
            (x, y, w, h) = cv2.boundingRect(approx)

            # Calculate the focal length assuming known width of the object
            focal_length = (w * obj_width) / 2

            # Calculate the distance to the object
            distance = (focal_length * 10) / w  # Assuming 10 inches as the unit of width

            # Draw the bounding box and display the distance
            cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
            cv2.putText(image, f"Distance: {distance:.2f} inches", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6,
                        (0, 255, 0), 2)

            break

    # Display the image
    cv2.imshow("Image", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


# Example usage
image_path = ".\pictures\lp.png"
object_width = 3.5  # Width of the object in inches
calculate_distance(image_path, object_width)