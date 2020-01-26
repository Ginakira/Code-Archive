import cv2
img = cv2.imread("./pushu.jpg")
img2 = cv2.imread("./pmaru.png")
img = cv2.resize(img, (800, 600))
res = cv2.addWeighted(img, 0.4, img2, 0.6, 0)
cv2.imshow("OpenCV", res)
cv2.waitKey()
cv2.destroyAllWindows()
