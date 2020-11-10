# 라이브러리 로딩 -----------------------------
from bs4 import BeautifulSoup

# 데이터 변수 선언  ---------------------------
html = """
<html>
  <title>타이틀입니다.</title>
  <body>
  <h1>스크레이핑이란?</h1>
  <p>웹 페이지를 분석하는 것</p>
  <p align='center'>원하는 부분을 추출하는 것</p>
</body></html>
"""
DEBUG = True

# HTML 분석 -----------------------------------
# (1) 분석할 HTMl 데이터 & 분석기 지정
#     => HTML 태그명으로 계층적 접근 및 추출 가능해짐
soup = BeautifulSoup(html, 'html.parser')
if DEBUG: print(type(soup))

# HTML 요소 추출 -----------------------------------
# 태그명으로 원하는 부분 추출
title = soup.html.title
h1 = soup.html.body.h1
p1 = soup.html.body.p
p2 = p1.next_sibling.next_sibling

# 요소의 글자 출력
print("title = " + title.string)
print("h1 = " + h1.string)
print("p  = " + p1.string)
print("p  = " + p2.string)
print("p2.attrs['align'] = " + p2.attrs['align'])