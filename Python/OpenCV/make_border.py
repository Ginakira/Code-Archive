import cv2
img = cv2.imread("./pushu.jpg")
top_size, bottom_size, left_size, right_size = (50, 50, 50, 50)

# 复制法 复制边缘像素
replicate = cv2.copyMakeBorder(
    img, top_size, bottom_size, left_size, right_size, borderType=cv2.BORDER_REPLICATE)

# 反射法复制
reflect = cv2.copyMakeBorder(
    img, top_size, bottom_size, left_size, right_size, borderType=cv2.BORDER_REFLECT)

# 边缘像素为轴反射
reflect101 = cv2.copyMakeBorder(
    img, top_size, bottom_size, left_size, right_size, borderType=cv2.BORDER_REFLECT_101)

# 外包装法
wrap = cv2.copyMakeBorder(img, top_size, bottom_size,
                          left_size, right_size, borderType=cv2.BORDER_WRAP)

# 常量法 常数值填充
constant = cv2.copyMakeBorder(img, top_size, bottom_size, left_size,
                              right_size, borderType=cv2.BORDER_CONSTANT, value=0)

cv2.imshow("OpenCV", wrap)
cv2.waitKey()
cv2.destroyAllWindows()
