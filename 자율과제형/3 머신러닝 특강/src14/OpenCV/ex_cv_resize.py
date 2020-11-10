# 모듈 로딩 -----------------------------------------------
import cv2
import matplotlib.pyplot as plt

# 데이터 변수 선언 -----------------------------------------
IMG_NAME = "../DATA/IMAGE/test.jpg"
IMG_SAVE = "../DATA/IMAGE/re_test.jpg"
DEBUG = True

# (1) 이미지 읽어오기 --------------------------------------
img=cv2.imread(IMG_NAME)

# (2) 이미지 저장-------------------------------------
im2=cv2.resize(img, (600, 300))
ret = cv2.imwrite(IMG_SAVE, im2)

if DEBUG: print('ret = {}'.format(ret))
if ret:
    plt.imshow(cv2.cvtColor(im2, cv2.COLOR_BGR2RGB))
    plt.show()
else:
    print('-- SAVE FAIL')