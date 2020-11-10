# 모듈로딩 --------------------------------------------
import struct
import os

DEBUG = False

# CSV 변환 메소드 -------------------------------------
def to_csv(name, maxdata):
    # (1) CSV 저장할 데이터 준비
    # 레이블 파일과 이미지 파일 열기
    lbl_f = open("./mnist/"+name+"-labels-idx1-ubyte", "rb")
    img_f = open("./mnist/"+name+"-images-idx3-ubyte", "rb")

    # CSV 파일 생성
    csv_f = open("./mnist/"+name+".csv", "w", encoding="utf-8")

    # 헤더 정보 읽기
    mag, lbl_count = struct.unpack(">II", lbl_f.read(8)) # 매직 코드 + 레이블 갯수
    mag, img_count = struct.unpack(">II", img_f.read(8)) # 매직 코드 + 이미지 갯수
    rows, cols = struct.unpack(">II", img_f.read(8))     # 행, 열 갯수
    pixels = rows * cols
    if DEBUG:
        print('lbl_count {}, img_count {}'.format(lbl_count, img_count))
        print('rows {}, cols {}'.format(rows, cols))

    # (2) 이미지 데이터를 읽고 CSV로 저장
    res = []
    for idx in range(lbl_count):
        if idx > maxdata: break

        # 숫자이미디 데이터가 의미하는 숫자값 읽기
        label = struct.unpack("B", lbl_f.read(1))[0]  # 튜플타입 리던 ->1개 데이터 (value,)
        if DEBUG: print(' label = >{}'.format(label))

        # 이미지 데이터 읽기
        bdata = img_f.read(pixels)
        sdata = list(map(lambda n: str(n), bdata))  # 문자열로 변환
        if DEBUG: print('sdata => {}'.format(sdata))

        # CSV 파일에 쓰기
        csv_f.write(str(label)+",")                 # 숫자 라벨 쓰기
        csv_f.write(','.join(sdata) + "\r\n")       # 리스트 이미지 데이터 -> 문자열 변환 후 쓰기

        # 잘 저장됐는지 이미지 파일로 저장해서 테스트
        # PGM(Portable GrayMap) 형식, 회색조이미지 의미
        # id => P2, P5 , binary file
        # 헤더 id, w, h max_value
        if idx < 10:
            s = "P2 28 28 255\n"            # PGM 헤더 쓰기
            s += " ".join(sdata)            # 색상 데이터 공백으로 구분하여 하나의 문자열로 합치기
            iname = "./mnist/PGM/{0}-{1}-{2}.pgm".format(name,idx,label)
            with open(iname, "w", encoding="utf-8") as f:
                f.write(s)
    csv_f.close()
    lbl_f.close()
    img_f.close()

# MNIST DATA 파일 SCV 변환 ----------------------------
PGM_PATH='./mnist/PGM'
if not os.path.exists(PGM_PATH): os.makedirs(PGM_PATH)

#to_csv("train", 60000)    # 1000개 학습용 CSV 변환
#to_csv("t10k",  10000)    # 500개 학습용 CSV 변환

to_csv("train", 1000)    # 1000개 학습용 CSV 변환
to_csv("t10k", 500)      # 500개 학습용 CSV 변환