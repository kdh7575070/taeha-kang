# File I/O -----------------------------------------
FILE_NAME= '../../data/test.html'

try:
    file=open(FILE_NAME, mode='r', encoding='utf-8')

    while True:
        line = file.readline()
        if not line: break
        print(type(line), line)
finally:
    file.close()

