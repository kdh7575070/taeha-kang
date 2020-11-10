import requests
from bs4 import BeautifulSoup

#데이터 변수
USER = "hellohello"
PASS = "hello12345"

login_info = {"m_id": USER, "m_passwd": PASS} #필드 아이디
url_login = "https://www.hanbit.co.kr/member/login_proc.php" #network창에서 php따오기
url_mypage = "http://www.hanbit.co.kr/myhanbit/myhanbit.html"

#모듈 객체 생성 및 선언
#세션 시작
session = requests.session()

#로그인 페이지 접근
res = session.post(url_login, data=login_info) #로그인인포 넘겨주기
res.raise_for_status()

#마이페이지 접근
res = session.get(url_mypage)
res.raise_for_status()

#web에서 데이터추출
soup = BeautifulSoup(res.text, "html.parser")
#print(soup)
#container > div > div.sm_mymileage > dl.mileage_section1 > dd > span
mileage = soup.select_one("#container > div > div.sm_mymileage > dl.mileage_section1 > dd > span").string #혹은 get_gext()
ecoin = soup.select_one("#container > div > div.sm_mymileage > dl.mileage_section2 > dd > span").string

print(mileage, ecoin)
