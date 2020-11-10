# 데이터 변수 선언 -------------------------------------
DATA_CSV  = "./data.csv"
TEMP_CSV  = "./tem10y.csv"

# ----------------------------------------------------
# 데이터 준비
# ----------------------------------------------------
# CSV 파일 읽기
with open(DATA_CSV, "rt") as fr: #텍스트일땐 rt해도 되고 r해도 되고
    lines = fr.readlines()

# 데이터 추출
lines = ["연,월,일,기온,품질,균질\n"] + lines[5:]    # 헤더 제거 및 새 헤더 추가
lines = map(lambda v: v.replace('/', ','), lines)  # 구분자 변경
result = "".join(lines).strip()                    #공백 제거
print('NEW DATA =>', result)

# 새로운 CSV 파일 생성
with open(TEMP_CSV, mode="wt", encoding="utf-8") as fw:
    fw.write(result)
    print("saved")