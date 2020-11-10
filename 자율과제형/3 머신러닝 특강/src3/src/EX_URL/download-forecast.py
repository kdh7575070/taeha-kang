import urllib.request
import urllib.parse

# 데이터변수 선언 ------------------------------------------------
API = "http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp"
values = { 'stnId': '108' }

# 매개변수 URL 인코딩 urlencode() ------------------------------
params = urllib.parse.urlencode(values)

# GET방식 요청 전용 URL 생성
url = API + "?" + params
print("url=", url)

# 다운로드 urlopen() -----------------------------------------
# HTTPResponse 객체 반환 -> byte타입 데이터
data = urllib.request.urlopen(url).read()

with open('../forecast.txt', 'wb') as file:
    file.write(data)
    print('../data/forecase2.txt 파일로 저장')

# 데이터 콘솔 창 출력 ----------------------------------------
text = data.decode("utf-8")
print(text)
