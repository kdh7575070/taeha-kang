# IT교육센터 파이썬 기반 인공지능 수업
## 수업을 들으며 한줄 한줄 기록했던 내용에다가 이번 제출을 위해 복습하며 주석을 추가하여 정리했습니다. 클릭하여 꼭 확인해주시기 바랍니다.
Pycharm을 이용하여 정리했습니다.\
python version == 3.8.6\
pycharm edition version == 2019.3.3\
tensorflow version == 1.11 \
keras version == 2.2.2

### src2-5. 1주차에 해당하는 내용입니다.
python와 matplotlib, pandas와 numpy에 관한 내용을 전반적으로 학습했고, 웹에서 데이터를 크롤링, 스크레이핑 하여 데이터를 가져오는 기술에 대해서도 학습했습니다.
#### 코드리뷰
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

    //BeautifulSoup이라는 package를 통해 영화정보를 크롤링 하는 함수입니다. 서버에 url 요청을 위해 urllib이라는 패키지도 사용합니다.
[src4/movie.py]https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/3%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%ED%8A%B9%EA%B0%95/src4/movie.py

    from selenium import webdriver

    # 크롬 브라우저 제어 드라이버 생성
    driver=webdriver.Chrome('C:\Program Files/WebDriver/chromedriver.exe')

    # 크롬 브라우저 드라이버를 활용한 원격 웹 페이지 제어
    # URL 열기
    driver.get("https://www.naver.com")

    # WEB 페이지의 특정 요소에 접근
    # //*[@id="query"]
    driver.find_element_by_xpath('//*[@id="query"]').send_keys('안녕하세요.')
    
    //scraping을 위해 selenium의 webdriver package를 이용합니다.
[src4/scraping.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/3%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%ED%8A%B9%EA%B0%95/src4/scraping.py)

### src6-10. 2주차에 해당하는 내용입니다.
[](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/2%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EB%B6%84%EC%84%9D%20%ED%8A%B9%EA%B0%95/Untitled1.ipynb)
#### 코드리뷰
[](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/2%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EB%B6%84%EC%84%9D%20%ED%8A%B9%EA%B0%95/Untitled.ipynb)

### src11-15. 3주차에 해당하는 내용입니다.
[]()
#### 코드리뷰
[](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/2%20%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EB%B6%84%EC%84%9D%20%ED%8A%B9%EA%B0%95/Untitled.ipynb)

### 수료증입니다.
<img src="https://user-images.githubusercontent.com/67677983/99956337-340ee580-2dc9-11eb-97aa-eb3048168cb5.png" width="400">
