# 모듈 로딩 -------------------------------------------
import requests

# 데이터 변수 선언 -------------------------------------
URL = 'http://api.aoikujira.com/time/get.php'

# 데이터 가져오기 ------------------------------------
res = requests.get(URL)

if int(res.status_code) == 200:
    # 텍스트 형식으로 데이터 추출하기
    text = res.text
    print(text)

    # 바이너리 형식으로 데이터 추출하기
    bin = res.content
    print(bin)
else:
    print("ERROR : ", res.status_code)