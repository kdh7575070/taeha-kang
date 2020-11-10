# 모듈 로딩 ----------------------------------------
import yaml

# 데이터 변수 선언 ----------------------------------
yaml_str = """
Date: 2017-03-10
PriceList:
    -
        item_id: 1000
        name: Banana
        color: yellow
        price: 800
    -
        item_id: 1001
        name: Orange
        color: orange
        price: 1400
    -
        item_id: 1002
        name: Apple
        color: red
        price: 2400
"""

# YAML 분석 -------------------------------------------
data = yaml.load(yaml_str, Loader=yaml.FullLoader)
print(data)

print(" ------------------ ")
for data in yaml.load_all(yaml_str, Loader=yaml.FullLoader):
    print(data)

print(" ------------------ ")
# 이름, 가격 데이터 출력 --------------------------------
for item in data['PriceList']:
    print(item["name"], item["price"])

