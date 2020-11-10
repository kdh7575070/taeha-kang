# str과 byte ---------------------------------
msg='hello'         # 일반 문자열
bmsg=b'hello'       # b'문자열' => 문자 해당 ASCII code 변환한 값 즉 바이트 형식

# 각 데이터 요소 출력
print('\n===== 데이터 요소 출력 =====')
for i in msg: print(i, end='\t')
print('\n')

for i in bmsg:  print(i, end='\t')
for i in bmsg:  print('0x%x'%i, end='\t')

print('\n\n===== str타입 => bytes타입 변경 : encode() =====')
strData='Good Luck'
byteData = strData.encode()
print('byteData =>', byteData)
print('strData =>',  strData)

print('\n===== bytes타입 => str타입 변경 : decode() =====')
strData2=byteData.decode()
print('byteData =>',  byteData)
print('strData2 =>',  strData2)