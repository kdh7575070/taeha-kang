# 가변인자 함수 ------------------------------
def get_sum(*args):

    print(type(args))
    sum=0
    for i in args: sum += i
    return sum

result=get_sum(1,2,3,4,5)
print(result)

result=get_sum(11,22,33,44,55,66,77,88)
print(result)

# 키워드인자 함수 -----------------------------
def printdata(**kwargs):
    print(type(kwargs))
    print(kwargs)

printdata(a=1)

printdata(name='hong', age=12, code='ko')

print('type(printdata) => ', type(printdata))


# map함수 ------------------------------------------
x, y = map(int, input('정수 2개를 입력하세요. ').split(' '))
print('x = {}, y = {}'.format(x, y))


total = 10

def get_total(*args):
    global total
    for data in args:
         total += data

get_total(10,20,30,40)

print('total = ', total)

