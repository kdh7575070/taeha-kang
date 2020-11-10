#File I/O 변형

FILE_NAME='../data/test_my.html'

with open(FILE_NAME,mode='r',encoding='utf-8') as file :
    while True:
        line = file.readline()
        if not line: break
        print(type(line),line)

print("END")