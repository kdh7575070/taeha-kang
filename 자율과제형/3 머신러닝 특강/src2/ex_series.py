# 모듈로딩 ------------------------------------------------------------------------
import pandas as pd

print('Series 객체 생성 + List 데이터 =============')
# 시퀀스 타입 => Series 타입
list_data=[ '2020-02-04', 3.14, 'Hello', 100, 'True']        # 리스트 데이터
sdata=pd.Series(list_data)                                  # index, Value형태의 1차원 배열 변환
print('type(sdata)=>', type(sdata))
print('sdata DATA =>\n', sdata)
print('sdata.index => ', sdata.index)
print('sdata.values => ', sdata.values)
print('sdata.shape => ', sdata.shape)                       # 형태 확인 => 튜플리턴

print('\nSeries 데이터 요소 출력=============')
print('sdata[0] =', sdata[0])
print('sdata[2] =', sdata[2])
print('sdata[2:-1] =', sdata[2:-1])

print('\nSeries 데이터 index 설정=============')
sdata.index=['date','value','msg','id','man']
print('sdata.index => ', sdata.index)
print('sdata["value"] =', sdata['value'])
print('sdata[["id", "man"]] =', sdata[["id", "man"]])
print('sdata[0] =', sdata[0])
print('sdata[[1,2]] =', sdata[[1,2]])
print('sdata[0:1] =', sdata[0:1])
print('sdata["date":"value"] =', sdata[["date", "value"]])