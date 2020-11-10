# 라이브러리 로딩 -------------------------------------
from bs4 import BeautifulSoup

# 데이터 변수 선언  ----------------------------------
html = """
<html><body>
  <h1 id="title">스크레이핑이란?</h1>
  <p id="body">웹 페이지를 분석하는 것</p>
  <p>원하는 부분을 추출하는 것</p>
</body></html>
"""

# HTML 분석 ------------------------------------------
# (1) 분석할 HTMl 데이터 & 분석기 지정
#     => HTML 태그명으로 계층적 접근 및 추출 가능해짐
soup = BeautifulSoup(html, 'html.parser')

# ID로 요소 검색 및 추출 => find() --------------------
title = soup.find(id="title")
body = soup.find(id="body")

# 텍스트 부분 출력 ----------------------------------
print("#title=" + title.string)
print("#body=" + body.string)
