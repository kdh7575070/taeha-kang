#File I/O

FILE_NAME='../data/test_my.html'

try:
    file=open(FILE_NAME, mode='w', encoding='utf-8') #잘안씀
    for i in range(1,10):
        data = 'ti amo\n'
        file.write(data)

finally:
    file.close()