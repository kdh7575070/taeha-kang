# 모듈 로딩 -------------------------------------------
import requests
from bs4 import BeautifulSoup

# 데이터 변수 선언 ------------------------------------------
USER = "아이디입력"
PASS = "비밀번호입력"
login_info = { "m_id": USER,  "m_passwd": PASS }
url_login = "https://www.hanbit.co.kr/member/login_proc.php"
url_mypage = "http://www.hanbit.co.kr/myhanbit/myhanbit.html"


# 모듈 객체 생성 및 선언 --------------------------------
# 세션 시작
session = requests.session()

# 로그인 페이지 접근
res = session.post(url_login, data=login_info)
res.raise_for_status()

# 마이페이지 접근
res = session.get(url_mypage)
res.raise_for_status()

# Web Page에서 데이터 추출 ----------------------------------------
soup = BeautifulSoup(res.text, "html.parser")
print(soup)

mileage = soup.select_one("#container > div > div.sm_mymileage > dl.mileage_section1 > dd > span").get_text()
ecoin = soup.select_one(".mileage_section2 span").get_text()
print("마일리지: " + mileage)
print("이코인: " + ecoin)