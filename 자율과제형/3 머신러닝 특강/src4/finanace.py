from bs4 import BeautifulSoup
import urllib.request as req

# urlopen()으로 데이터 수집
url = "https://finance.naver.com/marketindex"
res = req.urlopen(url)

# BeautifulSoup으로 분석
soup = BeautifulSoup(res, "html.parser")

money = soup.select_one("#exchangeList > li:nth-child(2) > a.head.jpy > div > span.value").string

print('jpy', money)