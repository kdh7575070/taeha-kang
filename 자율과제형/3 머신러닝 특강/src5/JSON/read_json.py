# 모듈로딩--------------------------------------------
import urllib.request as req
import os.path
import json

# 번수 선언 -------------------------------------------
url = "https://api.github.com/repositories"
savename = "../DATA/repo.json"

# WEB 데이터 json 파일 다운로드 -------------------------
if not os.path.exists(savename):
    req.urlretrieve(url, savename)

# JSON 파일 분석 ---------------------------------------
s = open(savename, "r", encoding="utf-8").read()
items = json.loads(s)
print(type(items), '\nitmes =>', items)

# JSON 파일 출력 --------------------------------------
for item in items:
    print(type(item))
    print(item["name"] + " - " + item["owner"]["login"])