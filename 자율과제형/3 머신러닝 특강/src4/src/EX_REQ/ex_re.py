# 모듈 로딩 -------------------------------------------
import requests

# 데이터 변수 선언 -------------------------------------
URL = 'http://www.tistory.com'
FILE = '../../data/tistory.txt'
DEBUG = True

# 객체 변수 선언 ---------------------------------------
response = requests.get(URL)
if DEBUG:
    print('type(response)=>', type(response) )
    print('response.status_code =>', response.status_code )
    print('response.text =>', type(response.text))

# 데이터 파일로 저장
if int(response.status_code) == 200:
    with open(FILE, mode='w', encoding='utf-8') as file:
        file.write(response.text)

    print('File Save')
else:
    print('Fail : ', response.status_code)
