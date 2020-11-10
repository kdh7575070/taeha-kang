# 라이브러리 로딩 -------------------------------------
from bs4 import BeautifulSoup

# 데이터 변수 선언  ----------------------------------
html = """
<html><body>
  <ul>
    <li><a href="http://www.naver.com">naver</a></li>
    <li><a href="http://www.daum.net">daum</a></li>
  </ul>
</body></html>
"""

# HTML 분석 ------------------------------------------
# (1) 분석할 HTMl 데이터 & 분석기 지정
#     => HTML 태그명으로 계층적 접근 및 추출 가능해짐
soup = BeautifulSoup(html, 'html.parser')

# ID 요소 검색 및 추출 find_all() ---------------------
links = soup.find_all("a")

# 링크 목록 출력
for a in links:
    href = a.attrs['href']
    text = a.string
    print(text, ">", href)