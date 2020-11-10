import urllib.request as req
import os
import zipfile

# 데이터 변수 선언 --------------------------------------------------
HAAR_URL='https://github.com/opencv/opencv/tree/master/data/haarcascades'
CV_DATA='../DATA/CV_DATA/'

# 다운로드 경로 폴더 체크 및 다운로드 파일명 설정 -----------------------
if not os.path.exists(CV_DATA):
    os.makedirs(CV_DATA)

CV_DATA += 'haar-cascade-files.git'

# URL에서 다운로드 ---------------------------------------------------
ret = req.urlretrieve(HAAR_URL, CV_DATA)
if not ret :
    print('Download Fail')
    os.exit(0)
else:
    print('Download OK')

# 압축해제 -----------------------------------------------------------
