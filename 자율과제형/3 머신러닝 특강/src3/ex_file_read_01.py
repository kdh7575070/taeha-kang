#File I/O 기본형태 - 매번 파일을 열고 클로즈 해야하기 때문에 바꿔보자

FILE_NAME='../data/test_my.html'
# 파이썬 파일이랑 똑같은 경로 일 경우 FILE_NAME='test_my.html'

try: #예외처리
    file=open(FILE_NAME,mode='r',encoding='utf-8')
    while True:
        line = file.readline()
        if not line: break
        print(type(line),line)
finally:
    file.close()