# 이미지 파일 다운로드하기 ---------------------------------
import urllib.request

# URL과 저장 경로 지정 ------------------------------------
URL = "http://uta.pw/shodou/img/28/214.png"
SAVENAME = "../data/img_data.png"
DEBUG   = True

# HTTPResponse 객체 반환 -> byte 데이터 --------------------
resObj  =   urllib.request.urlopen(URL)
header  = resObj.getheaders()
data    = resObj.read()

if DEBUG:
    print('type(resObj) = ',type(resObj))
    print('resObj.headers() => \n', header)
    print('resObj.read() => \n', data)

# 바이너리 모드로 파일 저장
with open(SAVENAME, mode='wb') as file:
    file.write(data)
    print("저장되었습니다...!")
