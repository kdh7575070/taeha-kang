# 모듈 로딩 -------------------------------------------------
import yaml

# 데이터 변수 ------------------------------------------------
# 사용자 정보 리트스 데이터
customer = [
    { "name": "InSeong", "age": "24", "gender": "man" },
    { "name": "Akatsuki", "age": "22", "gender": "woman" },
    { "name": "Harin", "age": "23", "gender": "man" },
    { "name": "Yuu", "age": "31", "gender": "woman" }
]

# YAML 데이터 생성 --------------------------------------
yaml_str = yaml.dump(customer)
print(" Python LIST => YAML DATA")
print(yaml_str)

# YAML 데이터를 Python 데이터 변환
data = yaml.load(yaml_str, Loader=yaml.FullLoader)
print(" Python LIST => YAML DATA")
print('type(DATA) => ', type(data))

for p in data: print(p)