# 라이브러리 로딩 -------------------------------------
from bs4 import BeautifulSoup
import re

# 데이터 변수 선언  ----------------------------------
html = """
<ul>
  <li><a href="hoge.html">hoge</li>
  <li><a href="https://example.com/fuga">fuga*</li>
  <li><a href="https://example.com/foo">foo*</li>
  <li><a href="http://example.com/aaa">aaa</li>
</ul>
"""

# HTML 분석 ------------------------------------------
soup = BeautifulSoup(html, "html.parser")

# 속성으로 검색
li = soup.find_all(href=re.compile(r"^https://"))
for e in li: print(e.attrs['href'])