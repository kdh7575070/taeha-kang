# 모듈 로딩 -----------------------------------------
import csv, codecs

# 데이터 변수 ---------------------------------------
filename = "../DATA/list-euckr_02.csv"

# CSV 파일 열기 -------------------------------------
fp = codecs.open(filename, "r", "utf-8")

# 한 줄씩 읽어 들이기
reader = csv.reader(fp, delimiter=",", quotechar='"')
print(reader)
for cells in reader:
    print(cells)
    print(cells[1], cells[2])
