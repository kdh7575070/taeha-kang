# 모듈 로딩 -----------------------------------------------
import matplotlib.pyplot as plt
import cv2

# 데이터 변수 선언 -----------------------------------------
IMG_NAME = "../DATA/IMAGE/test.jpg"
DEBUG = True

# (1) 이미지 읽기 --------------------------------------
img=cv2.imread(IMG_NAME)
if DEBUG:
    print('type(img) = {}'.format(type(img)))
    print('img.shape = {}'.format(img.shape))
    print('img ====== \n{}\n'.format(img))

# (2) 이미지 읽고 보기--------------------------------------
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
