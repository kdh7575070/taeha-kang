# 모듈 로딩 -------------------------------------------
import requests

# 데이터 변수 선언 -------------------------------------
URL = 'http://wikibook.co.kr/logo.png'
IMG_FILE = '../../data/test.png'

# 데이터 가져오기 ------------------------------------
res = requests.get(URL)

if int(res.status_code) == 200:
    # 바이너리 형식으로 데이터 저장
    with open(IMG_FILE, "wb") as f:
        f.write(res.content)
    print("saved")
else:
    print("ERROR : ", res.status_code)