# 라이브러리 로딩 -----------------------------
from bs4 import BeautifulSoup
import urllib.request as req

# 데이터 변수 선언 ------------------------------------
url="https://movie.naver.com/movie/sdb/rank/rmovie.nhn"

# 데이터 가져오기 urlopen() ----------------------------
res = req.urlopen(url)
print(type(res))

# 데이터 분석하기 -------------------------------------
soup = BeautifulSoup(res, "html.parser")

# 원하는 데이터 추출 ---------------------------------
# 1개 추출
movie=soup.select_one("#old_content > table > tbody > tr:nth-child(2) > td.title > div > a")
print("movie = ", movie.attrs['title'])
print("movie = ", movie.string)

# 여러개 추출
#old_content > table > tbody > tr:nth-child(2) > td.title > div > a
#old_content > table > tbody > tr:nth-child(3) > td.title > div > a
movies=soup.select("#old_content > table > tbody > tr > td.title > div > a")
print("movies = {}, \nlen={}".format(movies, len(movies)))
number=1
for move in movies:
    print(number, move.string)
    if number>=10: break;
    number +=1