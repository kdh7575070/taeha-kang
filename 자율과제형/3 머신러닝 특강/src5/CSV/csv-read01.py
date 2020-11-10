# 모듈 로딩 -------------------------------------------
import codecs

# 데이터 변수 선언 -------------------------------------
filename = "../DATA/list-euckr.csv"

try:
    # CSV 파일 읽기 ---------------------------------------
    csv = codecs.open(filename, "r", "utf-8").read()

    # CSV 파이썬 리스트로 변환 -------------------------------
    data = []
    rows = csv.split("\r\n")
    for row in rows:
        if row == "": continue
        cells = row.split(",")
        data.append(cells)

    print('DATA =>', data)
    # 결과 출력하기 ---------------------------
    for c in data:
        print(c[1], c[2])
except FileNotFoundError:
    print("{} is not exist.".format(filename))
finally:
    print("Good-Bye~!")