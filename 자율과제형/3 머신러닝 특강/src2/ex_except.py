"""

a=10
b=0

print('{} / {} = {}'.format(a, b, a/b))




try:
    a=10
    b=0
    print('{} / {} = {}'.format(a, b, a/b))
except ZeroDivisionError as e:
    print('e : ', e)
except Exception as e:
    print('e : ', e)
finally:
    print('==END==')

"""

try:
    a=10
    b=0
    print('{} * {} = {}'.format(a, b, a*b))
except FileNotFoundError as e:
    print('e : ', e)
else:
    print('OK')
finally:
    print('==END==')