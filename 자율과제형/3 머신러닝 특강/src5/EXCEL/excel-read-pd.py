"""
FileName: excel_read_pd.py
"""
# 모듈로딩 ----------------------------------------------
import pandas as pd

# 데이터 변수 선언 --------------------------------------
filename = "../DATA/stats_100701.xlsx"
sheet_name = "stats_100701"

# 엑셀 파일 읽고 분석 -----------------------------------
book = pd.read_excel(filename, sheet_name=sheet_name, header=1)
print('type(book) =>', type(book))

# 2015년 인구로 정렬
book = book.sort_values(by=2015, ascending=False)
print(book)