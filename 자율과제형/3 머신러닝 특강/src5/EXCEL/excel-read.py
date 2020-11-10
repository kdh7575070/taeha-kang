"""
FileName : excel_read.py
"""
# 모듈 로딩 ---------------------------------------------
import openpyxl

# 데이터 변수 선언 ----------------------------------------
filename = "../DATA/stats_100701.xlsx"

# 엑셀 파이 읽기 ----------------------------------------
book = openpyxl.load_workbook(filename)
sheet = book.worksheets[0]

# 엑셀에서 데이터만 추출
data = []
skip = 1
for row in sheet.rows:
    if skip > 4:
        data.append([
            row[0].value,
            row[sheet.max_column-2].value
        ])
    skip += 1

print(data)
print("="*10)
# 데이터를 인구 순서로 정렬
data = sorted(data, key=lambda x:x[1])
print(data)
print("="*10)

"""
# 데이터를 도시명 순서로 정렬
data = sorted(data, key=lambda x:x[0])
print(data)
print("="*10)
"""

# 하위 5위 출력
for i, a in enumerate(data):
    if (i >= 5): break
    print(i + 1, a)

print("="*10)
for i, a in enumerate(data, start=1):
    if (i > 5): break
    print(i , a)