# 라이브러리 로딩 -----------------------------
from bs4 import BeautifulSoup
import urllib.request as req

# 데이터 변수 선언 ------------------------------------
url="https://finance.naver.com/marketindex/?tabSel=exchange#tab_section"

# 데이터 가져오기 urlopen() ----------------------------
res = req.urlopen(url)
print(type(res))

# 데이터 분석하기 -------------------------------------
soup = BeautifulSoup(res, "html.parser")

# 원하는 데이터 추출 ---------------------------------
#copy selector해서 바로 원하는 데이터 가져오기
#exchangeList > li.on > a.head.usd > div > span.value
#exchangeList > li.on > a.head.jpy > div > span.value
usddata=soup.select_one("#exchangeList > li:nth-child(1) > a.head.usd > div > span.value")
print("usddata= ", usddata)
print("usd/krw= ", usddata.string)

jpy=soup.select_one("#exchangeList >  li:nth-child(2) > a.head.jpy > div > span.value")
print("jpy = ", jpy)
print("jpy/krw= ", jpy.string)

#/html/body/table/tbody/tr[3]/td[2]/a