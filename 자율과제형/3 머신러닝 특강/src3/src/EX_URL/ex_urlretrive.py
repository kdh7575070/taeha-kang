# 이미지 파일 다운로드하기 ------------------------------------------
import urllib.request

# URL과 저장 경로 지정
url = "http://uta.pw/shodou/img/28/214.png"
savename = "../data/test.png"

# 파일 형태로 다운로드
urllib.request.urlretrieve( url, savename )

print("저장되었습니다...!")
