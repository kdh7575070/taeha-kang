# 모듈 로딩 ---------------------------
from bs4 import BeautifulSoup

# 데이터 변수 선언 -----------------------
str_html="""
<html>
    <body>
        <ul>
            <li>TEST</li>
            <li>TEST2</li>
        </ul>
    </body>
</html>
"""

# 데이터 분석 및 파싱 ------------------------------------
soup=BeautifulSoup(str_html, 'html.parser')
print(type(soup), soup)
#exchangeList > li.on > a.head.usd > div > span.value
# 파싱된 데이터에서 원하는 데이터 추출하기
items=soup.find_all('li')
print(type(items), items)
for item in items:
    print(item.string)