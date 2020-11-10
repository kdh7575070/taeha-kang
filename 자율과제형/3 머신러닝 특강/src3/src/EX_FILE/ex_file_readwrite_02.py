# File I/O -----------------------------------------
R_FILE_NAME= '../../data/test.html'
W_FILE_NAME= '../../data/test.txt'
RXDATA=''

with open(R_FILE_NAME, mode='r', encoding='utf-8') as file :
    RXDATA=file.read()

with open(W_FILE_NAME, mode='w', encoding='utf-8') as file :
    file.write(RXDATA)

print("END")

