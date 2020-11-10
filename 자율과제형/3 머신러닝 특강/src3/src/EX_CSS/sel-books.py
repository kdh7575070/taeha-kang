# 라이브러리 로딩 -------------------------------------
from bs4 import BeautifulSoup

# 데이터 변수 선언  ----------------------------------
HTML_FILE = '../../data/books.html'

# 분석 데이터 객체 생성 -------------------------------
fp = open(HTML_FILE, encoding="utf-8")
soup = BeautifulSoup(fp, "html.parser")

# CSS 선택자 방식 검색 -------------------------------
sel = lambda q : print(soup.select_one(q).string)

sel("#nu")
sel("li#nu")
sel("ul > li#nu")
sel("#bible #nu")
sel("#bible > #nu")
sel("ul#bible > li#nu")
sel("li[id='nu']")
sel("li:nth-of-type(4)")

# 여러 개 중 한개 요소 인덱스 지정하여 검출
print(soup.select("li")[3].string)
print(soup.find_all("li")[3].string)