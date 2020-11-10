import urllib.request

url = "http://api.aoikujira.com/ip/ini"
res = urllib.request.urlopen(url).read()
savename = "../data/test.txt"

text = res.decode("utf-8")
print(text)

with open(savename, mode="w") as f:
    f.write(text)
    print('저장되었습니다!')