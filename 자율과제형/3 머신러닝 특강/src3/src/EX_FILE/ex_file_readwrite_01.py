# File I/O -----------------------------------------
R_FILE = '../../data/test.html'
W_FILE = '../../data/test.txt'

try:
    file=open(R_FILE, mode='r', encoding='utf-8')
    data = file.read()
    print('type(data) = {}\ndata  => {}'.format(type(data), data))
    wfile=open(W_FILE, mode='w', encoding='utf-8')
    wfile.write(data)
finally:
    file.close()
    wfile.close()

