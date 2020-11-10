# 리스트  선언 ------------------------------------------
print('\n리스트 선언 ====================')
alist=[]            # alist=list()
blist=list()
print('len(alist) = {}, len(blist) = {}'.format(len(alist), len(blist)))

alist=[1,2,3,['a','b','c',[111,222,333]]]
for i in alist: print(i)

for i in alist[3]: print(i)
for i in alist[3][3]: print(i)

# 리스트요소 변경 ------------------------------------------
print('\n', alist, '리스트 요소 변경 ====================')
alist[3][3] ='D'
print('alist => ', alist)

# 리스트요소 슬라이싱 ------------------------------------------
print('\n', alist, '리스트 슬라이싱 ====================')
alist[3][:] ='CHRISTMAS'
print('alist => ', alist)

alist[3][:] = '1'
print('alist => ', alist)


value= False
print('value = ', value)
value = not value
print('value = ', value)

for i in range(10):
    value = not value
    print('{} value = {}'.format(i, value))