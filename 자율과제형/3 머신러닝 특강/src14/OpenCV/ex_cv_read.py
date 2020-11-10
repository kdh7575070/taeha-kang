"""
FILENAME    :
DES         :
DATE        :
"""
# 모듈 로딩 -------------------------------------------
import urllib.request as req
import cv2
import os

# 데이터 변수 선언 -------------------------------------
IMG_NAME = "../DATA/IMAGE/test.jpg"
IMG_URL  = "http://uta.pw/shodou/img/28/214.png"
DEBUG = True

# (1) 이미지 다운로드 --------------------------------------
# 이미지 저장 폴더 존재여부 체크 후 없을 경우 폴더 생성
if not os.path.exists( os.path.dirname(IMG_NAME) ):
    os.makedirs(IMG_NAME)

# 지정된 URL에서 다운받은 이미지 지정된 경로 & 이름으로 저장
req.urlretrieve(IMG_URL, IMG_NAME)

# (2) 이미지 읽기 & 보기 -----------------------------------
img=cv2.imread(IMG_NAME)
if DEBUG:
    print('type(img) = {}'.format(type(img)))
    print('img.shape = {}'.format(img.shape))
print('img ====== \n{}\n'.format(img))