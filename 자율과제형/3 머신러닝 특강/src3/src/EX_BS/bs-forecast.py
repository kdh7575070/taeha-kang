# 라이브러리 로딩 -----------------------------
from bs4 import BeautifulSoup
import urllib.request as req

# 데이터 변수 선언 ------------------------------------
url = "http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp"

# 데이터 가져오기 urlopen() ----------------------------
res = req.urlopen(url)

# 데이터 분석하기 -------------------------------------
soup = BeautifulSoup(res, "html.parser")

# 원하는 데이터 추출 ---------------------------------
title = soup.find("title").string
wf = soup.find("wf").string
print(title)
print(wf)