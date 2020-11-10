# 라이브러리 로딩 -----------------------------------------
import sys
import urllib.request as req
import urllib.parse as parse

# 명령줄 매개변수 추출 -------------------------------------
if len(sys.argv) <= 1:
    print("USAGE: download-forecast-argv <Region Number>")
    sys.exit()

for i in sys.argv: print(i)
regionNumber = sys.argv[1]

# URL 인코딩 urlencode() --------------------------------
API = "http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp"
values = {'stnId': regionNumber }
params = parse.urlencode(values)
url = API + "?" + params
print("url=", url)

# 다운로드 urlopen() -----------------------------------------
data = req.urlopen(url).read()
text = data.decode("utf-8")
print(text)