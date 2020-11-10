# 모듈 로딩 -----------------------------------------------
import cv2

# 데이터 변수 선언 -----------------------------------------
IMG_NAME = "../DATA/IMAGE/test.jpg"
IMG_SAVE = "../DATA/IMAGE/copy_test.jpg"
DEBUG = True

# (1) 이미지 읽어오기 --------------------------------------
img=cv2.imread(IMG_NAME)
if DEBUG:
    print('type(img) = {}'.format(type(img)))
    print('img.shape = {}'.format(img.shape))
    print('img ====== \n{}\n'.format(img))

# (2) 이미지 저장 ------------------------------------------
ret = cv2.imwrite(IMG_SAVE, img)
if DEBUG:
    print('ret = {}'.format(ret))

print('Image Save OK!') if ret else print('--FAIL')