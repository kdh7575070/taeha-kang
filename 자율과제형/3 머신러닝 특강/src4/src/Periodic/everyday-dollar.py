# 모듈 로딩 ---------------------------------------------
from bs4 import BeautifulSoup
import urllib.request as req
import datetime

# 데이터 변수 선언 -------------------------------------------
url         = "https://finance.naver.com/marketindex/"
usd_file    = "../../data/realtime_usd.txt"

# 데이터 가져오기 ---------------------------------------------
res = req.urlopen(url)

# 데이터 분석하기 ----------------------------------------------
soup = BeautifulSoup(res, "html.parser")
usd = soup.select_one("#exchangeList > li:nth-child(1) > a.head.usd > div > span.value").string
print("usd/krw", usd)

# 파일 저장 -----------------------------------------------------
t_name = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
print(t_name)

with open(usd_file, mode="a", encoding="utf-8") as f:
    f.write( t_name +"  usd/krw : " + usd +"\n")