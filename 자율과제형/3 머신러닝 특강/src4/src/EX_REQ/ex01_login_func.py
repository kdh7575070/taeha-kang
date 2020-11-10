# 모듈 로딩 -------------------------------------------
import requests
from bs4 import BeautifulSoup

# 변수 선언 ------------------------------------------
# 아이디와 비밀번호 지정
USER = "아이디입력"
PASS = "비밀번호입력"
login_info = { "m_id": USER,  "m_passwd": PASS}

# 모듈 객체 생성 및 선언 -------------------------------------------
def make_session(userid, userpw, url):
    login_info = {"m_id": userid, "m_passwd": userpw}
    # 세션 시작
    session = requests.session()
    url_login = "http://www.hanbit.co.kr/member/login_proc.php"
    res = session.post(url_login, data=login_info)
    res.raise_for_status()
    print(res)

    # 마이페이지에 접근
    url_mypage = "http://www.hanbit.co.kr/myhanbit/myhanbit.html"
    res = session.get(url_mypage)
    res.raise_for_status()
    print('res =', res)

    return res

# Web Page에서 데이터 추출 ----------------------------------------
def get_data(res):
    soup = BeautifulSoup(res.text, "html.parser")
    #print('SOUP=>', soup)

    mileage = soup.select_one(".mileage_section1 span").get_text()
    ecoin = soup.select_one(".mileage_section2 span").get_text()
    print("마일리지: " + mileage)
    print("이코인: " + ecoin)

# 로그인 후 데이터 추출 -------------------------------------------
def main():
    get_data(make_session('anece1111', 'so18051805!', 'url'))


# 스트립트 동작모드 시 실행 ----------------------------------------
if __name__ == '__main__':
    import sys
    main()