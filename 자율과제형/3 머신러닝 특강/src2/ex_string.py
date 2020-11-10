# 변수 선언 ---------------------
msg='Hello'

# 문자열 데이터 출력
print('msg => %s' %msg)
print('msg => ', msg)
print('msg => '+ msg)


# 문자열 데이터 한 개씩 출력
for ch in msg:
    print(ch)

# 문자열 길이 구하기 => len() 내장함수
print( 'len(msg) => %d' %len(msg))

# 인덱싱 ---------------------------
print('\n%s 인덱싱 ===================='%msg)
print('msg[-1] => ' + msg[-1])
print('msg[-2] => ' + msg[-2])
print('msg[-3] => ' + msg[-3])
print('msg[-4] => ' + msg[-4])
print('msg[-5] => ' + msg[-5])

# 슬라이싱 -------------------------
print('\n%s 슬라이싱 ===================='%msg)
print('msg[0:2] => ' + msg[0:2])
print('msg[:2] => ' + msg[:2])
print('msg[2:] => ' + msg[2:])
print('msg[2:len(msg)] => ' + msg[2:len(msg)])
print('msg[-3:] => ' + msg[-3:])
print('msg[2:-1] => ' + msg[2:-1])
print('msg[-5:-1] => ' + msg[-5:-1])
print('msg[:] => ' + msg[:])


# 문자열 변경 -------------------------
print('\n%s 문자열 변경===================='%msg)
data = 'Hello'
#data[1]='E'

data=data[0]+'E'+data[2:]
print('data =>', data)


# 문자열 나누기-------------------------
data='Happy New Year'
print('\n%s 문자열 나누기===================='%data)
datas=data.split(' ')  # 공백으로 분리 후 리스트 리턴
print('type(datas) = {}, datas= {}'.format( type(datas), datas))
for d in datas: print(d)


# 문자열 합치기-------------------------
print('\n%s 문자열 합치기===================='%datas)
data=','.join(datas)
print('type(data) = {}, data= {}'.format( type(data), data))


# 문자열 합치기-------------------------
print('\n%s 특정 문자열 치환===================='%msg)
msg = msg.replace('e', 'EEE')
print('msg => ', msg)