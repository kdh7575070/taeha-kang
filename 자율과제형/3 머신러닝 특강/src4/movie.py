from bs4 import BeautifulSoup
import urllib.request as req

# urlopen()으로 데이터 수집
url = "https://movie.naver.com/movie/sdb/rank/rmovie.nhn"
res = req.urlopen(url)

# BeautifulSoup으로 분석
soup = BeautifulSoup(res, "html.parser")

movie = soup.select_one("#old_content > table > tbody > tr:nth-child(2) > td.title > div > a").string

movies = soup.select("#old_content > table > tbody > tr > td.title > div > a")
print ("movies =", movies, len(movies))
number = 1
for move in movies : #move는 자동으로 객체형으로 정해진다
    print(number, move.string) #string을 붙이면 앞뒤의 <> <>가 떨어져나간다
    if number >= len(movies)/10: break;
    number+=1

print()
for i in range(2,11):
    x = "#old_content > table > tbody > tr:nth-child("+str(i)+") > td.title > div > a"
    moviem = soup.select_one(x).string
    print(moviem)
