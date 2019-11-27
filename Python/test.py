import os
import numpy as np
import cv2


def aHash(image):
    image_new = image
    averange = np.mean(image_new)
    hash = []
    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            if(image[i, j] > averange):
                hash.append(1)
            else:
                hash.append(0)
    return hash


def Hamming_distance(hash1, hash2):
    num = 0
    for index in range(len(hash1)):
        if hash1[index] != hash2[index]:
            num += 1
    return num


if __name__ == "__main__":
    img1 = cv2.imread('image1.png')
    img2 = cv2.imread('image2.png')
    
    image1 = cv2.cvtColor(cv2.resize(
        img1, (8, 8), interpolation=cv2.INTER_CUBIC), cv2.COLOR_BGR2GRAY)
    image2 = cv2.cvtColor(cv2.resize(
        img2, (8, 8), interpolation=cv2.INTER_CUBIC), cv2.COLOR_BGR2GRAY)
    hash1 = aHash(image1)
    hash1 = aHash(image1)
    hash2 = aHash(image2)
    dist = Hamming_distance(hash1, hash2)
    simliarity = 1.0 - dist * 1.0 / 64
    print(hash1)
    print(hash2)
    print("dist is %d" % dist)
    print("Similarity is %f" % simliarity)
