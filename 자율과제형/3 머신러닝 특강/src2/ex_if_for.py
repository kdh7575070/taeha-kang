data=['one', 'two','three']
for i in data:
    print(i)

#딕셔너리읽어오기
data=[('A', 90), ('B', 80), ('C',70)]
for first, second in data:
    print(first, second)

data=[1,2,3,4,5,6]
result =[num*3 for num in data]
print('result =>', type(result))

data=[1,2,3,4,5,6]
result =[num*3 for num in data if num%2==0]
print('result =>', type(result))

result = [x*y for x in range(2,10) for y in range(1,10)]
print('result =>', result)