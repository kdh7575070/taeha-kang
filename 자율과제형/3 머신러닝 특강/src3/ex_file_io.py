#File I/O

FILE_NAME='../data/test.txt'
FILE_NAME2='../data/test_2.txt'

line = ''

with open(FILE_NAME, mode='r',encoding='utf-8') as file :
    line = file.read()

with open(FILE_NAME2, mode='w',encoding='utf-8') as file :
    file.write(line)

print('end')