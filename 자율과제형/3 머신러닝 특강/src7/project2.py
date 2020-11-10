import struct #바이너리데이터 처리해서 풀어내기
import os

DEBUG = False

def to_csv(name, maxdata):

    #레이블 파일과 이미지 파일 열기
    lbl_f = open("./mnist/"+name+"-labels-idx1-ubyte", "rb")
    img_f = open("./mnist/"+name+"-images-idx3-ubyte", "rb")
    if DEBUG:
        print('====> lbl_f\n{}\n'.format(lbl_f))
        print('====> lbl_f.read(1) = \n{}\n'.format(lbl_f.read(1)))

    #CSV파일 생성
    csv_f = open("./mnist/"+name+".csv","w",encoding="utf-8")

    #헤더정보읽기
    mag, lbl_count = struct.unpack(">II", lbl_f.read(8)) #매직코드 4 + 레이블 갯수 4 #이미지 데이타는 보통 II 즉 unsigned int로 넣는다
    mag, img_count = struct.unpack(">II", img_f.read(8)) #매직코드 4 + 이미지 갯수 4 ##튜플타입!!
    rows, cols = struct.unpack(">II", img_f.read(8)) #이미지 행열정보 4 + 4
    if DEBUG:
        print('rows {}, cols {}'.format(rows, cols))
    pixels = rows * cols

    #이미지 데이터를 읽고 CSV로 저장하기
    res = []
    for idx in range(lbl_count):
        if idx > maxdata: break

        #숫자이미지 데이터가 의미하는 숫자값 읽기
        label = struct.unpack("B", lbl_f.read(1))[0] #튜픑타입리턴 ->1개 데이터넘어감
        if DEBUG: print('label = >{}'.format(label))

        #이미지 데이터 읽기
        bdata = img_f.read(pixels) #앞서계산한 픽셀 하나씩의 데이터넘어감
        sdata = list(map(lambda n:str(n), bdata)) #문자열로 변환
        if DEBUG: print('sdata =>\n{}'.format(sdata))

        #CSV 파일에 쓰기
        csv_f.write(str(label)+",") # 숫자라벨 쓰기
        csv_f.write(','.join(sdata)+"\r\n") # 리스트 이미지 데이터 -> 문자열 변환 후 쓰기

        #그렇게 한줄 쓰고나면 그줄을 없어지고 다음줄 읽어들어온다!!!

        #잘 저장됐는지 이미지  파일로 저장해서 테스트하기
        if idx<10:
            s="P2 28 28 255\n"
            s += " ".join(sdata)
            iname = "./mnist/{0}-{1}-{2}.pgm".format(name,idx,label)
            with open(iname, "w", encoding="utf-8") as f:
                f.write(s)

    csv_f.close()
    lbl_f.close()
    img_f.close()

#결과를 파일로 출력하기
to_csv("train", 1000)
to_csv("t10k", 5000)