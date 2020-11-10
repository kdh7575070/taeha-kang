#인덱싱과 슬라이싱
msg = 'hello'
print( "e" == msg[1])
msg_slice1 = msg[1:3]
print( "el" == msg_slice1)
msg_slice2 = msg[-4:-2] #[-2:-4]가 아님
msg_slice3 = msg[1:-3]
print( "e" == msg_slice2[0] == msg_slice3)
#exit() 적으면 뒤에는 실행안함
print( "e" == msg_slice2[0] == msg_slice3)

#문자열내부변경
# msg[1:3] = 'a' 이렇게 안된다 문자열수정불가
msg = msg[0]+'a'+msg[3:5]
print(msg)
#또는 특정문자열치환으로해서
msg = msg.replace('a','o')
print(msg)

#Join 과 split (쪼개고 붙이기)
data = 'Happy New Year'
datas = data.split(' ')
print('type(datas) = {}, datas = {}'.format(type(datas),datas))
for d in datas : print(d)

data=' '.join(datas)
print('type(data) = {1}, data = {0}'.format(data,type(data))) #순서지정하기도한다
print('type(data) = {y}, data = {z}'.format(z=data,y=type(data))) #이름달수도있다

#Bytes와 Bytearry(변형가능)
b0 = bytes(4) #숫자하나만 들어가면 4가 들어가는게 아니라 0짜리의개수
print('b0 =', b0, type(b0))
b1 = bytes(4, ) #마찬가지
print('b1 =', b1, type(b1))
b2 = bytes([1]) #리스트로 넣어주면 돼지
print('b2 =', b2, type(b2)) #b2[0]=2 불가
b3 = bytes(b'Happy') #바이트객체저장 - 문자를바이트로넣는거
print('b3 =', b3, type(b3)) #b3[4]=ord('Y') 불가 - ord는 아스키코드값변환함수

b4 = bytearray() #빈객체생성 - 나중에변형시키면됨
print('b4 =', b4, type(b4))
b5 = bytearray([200]) #숫자는리스트로넣어야한다
print('b5 =', b5, type(b5))
b6 = bytearray([1,3])
print('b6 =', b6, type(b6))
b6[0]=2
print('b6 =', b6, type(b6))
b7 = bytearray(b'Happy')
print('b7 =', b7, type(b7))
b7[4]=ord('Y')
print('b7 =', b7, type(b7))

# 문자열 => 바이트때는 인코딩