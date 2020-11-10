# 텍스트기반 파일 다운로드하기 -------------------------
# 라이브러리 로딩
import urllib.request

# 데이터 변수 선언
URL = 'http://api.aoikujira.com/ip/ini'

# WEB 데이터 가져오기
res = urllib.request.urlopen(URL)
data = res.read()

# 바이트 데이터 읽기
print('type(data) =', type(data))      # 타입 체크
print(data)

# 바이트 데이터 => 문자열 변환
text = data.decode("utf-8")
print('\ntype(text) =', type(text))      # 타입 체크
print(text)
