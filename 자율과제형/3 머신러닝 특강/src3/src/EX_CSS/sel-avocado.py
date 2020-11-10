# 라이브러리 로딩 -------------------------------------
from bs4 import BeautifulSoup

# 데이터 변수 선언  ----------------------------------
HTML_FILE = '../../data/fruits-vege.html'

# HTML 데이터 수집 및 분석 객체 생성 -----------------
fp = open(HTML_FILE, encoding="utf-8")
soup = BeautifulSoup(fp, "html.parser")

# CSS 선택자 활용 데이터 분석 -----------------------
print(soup.select_one("li:nth-of-type(6)").string)
print(soup.select_one("#ve-list > li:nth-of-type(4)").string)
print(soup.select("#ve-list > li[data-lo='us']")[1].string)
print(soup.select("#ve-list > li.black")[1].string)

# 요소명 기반 조건으로 검색 ------------------------
cond = {"data-lo":"us", "class":"black"}
print(soup.find("li", cond).string)

# find 메서드를 연속적으로 사용하기
print(soup.find(id="ve-list").find("li", cond).string)