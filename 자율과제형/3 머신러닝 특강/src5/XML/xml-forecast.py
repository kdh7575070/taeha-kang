#모듈 로딩--------------------------------------------------
from bs4 import BeautifulSoup
import urllib.request as req
import os.path

#변수선언 ---------------------------------------------------
url     = "http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=108"
savename = "../DATA/forecast.xml"
DEBUG = True

# WEB 데이터 다운로드 후 파일 저장 -----------------------------
if not os.path.exists(savename):
    req.urlretrieve(url, savename)

# WEB 데이터 분석 ----------------------------------------------
xml = open(savename, "r", encoding="utf-8").read()
soup = BeautifulSoup(xml, 'html.parser')
#if DEBUG: print('soup=>\n', soup, "="*20)

# WEB 데이터 정보 추출 ------------------------------------------
info = {}
for location in soup.find_all("location"):
    name = location.find('city').string             # 지역명
    weather = location.find('wf').string            # 맑음, 흐림 등 기상상태
    tmn = location.find('tmn').get_text()
    tmx = location.find('tmx').get_text()

    if not (weather in info): info[weather] = []    # 키 & 값 항목 생성
    #info[weather].append([name, tmn, tmx])         # 값 추가
    info[weather].append(name)                      # 값 추가


# 각 지역의 날씨를 구분해서 출력-------------------------------------
for weather in info.keys():
    print("+", weather)
    for name in info[weather]:
        print("| - ", name)