import cv2
from PIL import Image
import numpy as np
import scipy

# im1 = cv2.imread('2.jpg',cv2.IMREAD_COLOR)
# im2 = cv2.imread('1.png',cv2.IMREAD_GRAYSCALE)

# cv2.imshow("face",im1)

# cv2.imwrite('我不道啊.jpg',im1)

# cv2.waitKey(0)
# cv2.destoryAllWindows()

# cap = cv2.VideoCapture(0)

# while True:
#     ret,frame = cap.read()
#     cv2.imshow('Local Camera',frame)
#     if cv2.waitKey(1) & 0xFF == ord('q'):
#         break
    
# cap.release()
# cv2.destoryAllWindows()

# cat = cv2.imread('666.jpg')
# # 翻转图像
# flip_cat1 = cv2.flip(cat, flipCode=0)
# flip_cat2 = cv2.flip(cat, flipCode=1)
# flip_cat3 = cv2.flip(cat, flipCode=-1)
# combined = np.hstack((cat, flip_cat1, flip_cat2, flip_cat3))
# cv2.imshow('combined', combined)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

import tensorflow as tf
print(tf.__version__)
