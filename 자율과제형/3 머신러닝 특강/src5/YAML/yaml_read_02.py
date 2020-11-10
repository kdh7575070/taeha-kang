# 모듈 로딩 -------------------------------------------
import yaml

# 데이터 변수 선언 -------------------------------------
# 문자열로 YAML 정의
yaml_str = """
# 정의
color_def:
  - &color1 "#FF0000"
  - &color2 "#00FF00"
  - &color3 "#0000FF"
# 별칭
color:
  title: *color1
  body: *color2
  link: *color3
"""

# YAML 데이터 읽기 및 추출---------------------------------
data = yaml.load(yaml_str, Loader=yaml.FullLoader)

# 별칭이 전개됐는지 테스트하기
print("title=", data["color"]["title"])
print("body=", data["color"]["body"])
print("link=", data["color"]["link"])