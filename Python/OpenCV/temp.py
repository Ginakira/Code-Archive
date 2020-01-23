import cv2
img = cv2.imread("./timg.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# 创建级联分类器
face_cascade = cv2.CascadeClassifier("./haarcascade_frontalface_default.xml")
# 将numpy中数据与级联分类器数据匹配
# 参数：图像被缩小的比例 每一个目标至少要被检测到多少次
faces = face_cascade.detectMultiScale(gray, scaleFactor=1.05, minNeighbors=5)
# 标记人脸
for x, y, w, h in faces:
    img = cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
cv2.imshow("Pmaru", img)
cv2.waitKey()
cv2.destroyAllWindows()
