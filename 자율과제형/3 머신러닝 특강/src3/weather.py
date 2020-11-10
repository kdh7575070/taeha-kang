import sys
import urllib.request as req
import urllib.parse as parse


if len(sys.argv) <= 1:
    print("USAGE:download-forecast-argv<Region Number>")
    sys.exit()
regionNumber=sys.argv[1]

savename = "../data/textt.txt"

API = "https://www.weather.go.kr/weather/forecast/mid-term-rss3.jsp"
values = {'stdIo': regionNumber}
params = parse.urlencode(values)

url = API + "?" + params
print("url=", url)

#res = req.urlopen(url)
#data = res.read()
data = req.urlopen(url).read()
textt = data.decode("utf-8")

with open(savename, mode="w") as f:
    f.write(textt)
    print('저장되었습니다!')

print(textt)