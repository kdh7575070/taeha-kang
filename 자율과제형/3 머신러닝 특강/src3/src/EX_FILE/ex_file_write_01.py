# File I/O -----------------------------------------
FILE_NAME= '../../data/dataq.txt'

try:
    #file=open(FILE_NAME, mode='w', encoding='utf-8')   # 존재하지 않는 파일의 경우 파일 생성 / 덮어쓰기
    file = open(FILE_NAME, mode='a', encoding='utf-8')  # 존재하지 않는 파일의 경우 파일 생성 및 추가
    for i in range(1, 6):
        data = '%d째 줄 \n' %i
        file.write(data)
finally:
    file.close()

