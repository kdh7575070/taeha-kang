# 모듈로딩--------------------------------------------
import json

# 번수 선언 -------------------------------------------
datafile = "../DATA/jdata.json"

# JSON 파일 분석 ---------------------------------------
items = json.load(open(datafile, "r", encoding="utf-8"))
price = items['price']

# JSON 파일 출력 --------------------------------------
for name, value in price.items():
    print('%s - %d' %(name, value))