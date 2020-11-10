# bytes 생성 -------------------------------
print('\nbytes ====================')
b1=bytes(3)                         # 1byte 3개, 0초기화
print('b1 = ', b1, type(b1))

b2=bytes([1,2])                     # 1byte 2개, 값 초기화
print('b2 = ', b2, type(b2))

b3=bytes(b'Happy')                 # b'문자열'=> bytes 객체
print('b3 = ', b3, type(b3))

# bytearray 생성 -------------------------------
print('\nbytearray ====================')
b0=bytearray()                          # 빈 객체 생성
print('b0 = ', b0, type(b0))

b1=bytearray(3)                         # 1byte 3개, 0초기화
print('b1 = ', b1, type(b1))
b1[0]=2
print('b1 = ', b1, type(b1))

b2=bytearray([1,2])                     # 1byte 2개, 값 초기화
print('b2 = ', b2, type(b2))
b2[0]=255                               # 값 할당 시에는 정수
print('b2 = ', b2, type(b2))

b3=bytearray(b'Happy')                  # 문자열을 바이트로 저장
print('b3 = ', b3, type(b3))
b3[4]=ord('Y')                          # ord('문자')  문자의 ASCII 코드 반환
print('b3 = ', b3, type(b3))


# 바이트 & 문자열 자료형 변환 ------------------------------------
print('\n문자열 => 바이트 변환 ====================')
# 문자열 => 바이트
msg='Good'
msg=msg.encode()
print("'Good'.encode()' => ", type(msg), msg)

print("'Good'.encode(euc-kr)' => ", 'Good'.encode('euc-kr'))
print("'Good'.encode(utf-8)' => ",  'Good'.encode('utf-8'))

msg=bytes('Hello', encoding='utf-8')
print(msg)

msg=bytearray('Hello', encoding='utf-8')
print(msg)

print('\n바이트 => 문자열 변환 ====================')
msg = b'Hello'.decode()
print(type(msg), msg)