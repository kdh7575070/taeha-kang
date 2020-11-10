# 모듈로딩--------------------------------------------
import json

# 번수 선언 -------------------------------------------
data={
    'date':'2020-01-01',
    'price':{
        'apple':500,
        'banana':2500,
        'Kiwii':5000
    }}

savename = "../DATA/jdata.json"

# JSON형식 저장 ---------------------------------------
jdata = json.dumps(data)
print(type(jdata), jdata)

# JSON 파일 생성 --------------------------------------
with open(savename,mode='w', encoding='utf-8') as file:
    file.write(jdata)
