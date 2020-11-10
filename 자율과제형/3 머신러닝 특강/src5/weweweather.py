import requests
import json

apikey = "88c27aa309c070453ffa5e364d9eb576"

cities = ["Seoul,KR","Tokyo,JP","New York,US"]
api = "https://api.openweathermap.org/data/2.5/weather?q={city}&appid={key}"

for name in cities:
    url = api.format(city=name,key=apikey)
    r = requests.get(url)
    data = json.loads(r.text)
    print(data["name"], data["weather"][0]["main"], data["weather"][0]["description"], data["weather"][0]["icon"], int(data["main"]["temp"]-273.15))