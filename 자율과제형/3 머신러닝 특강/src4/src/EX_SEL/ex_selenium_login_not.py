# 모듈 로딩 ---------------------------------------------
from selenium import webdriver

# 변수 선언 ---------------------------------------------
CHROME_DRIVER   = r'D:\WebDriver\chromedriver.exe'
CAP_IMG         = '../../data/website.png'
LOGIN_URL       = 'https://nid.naver.com/nidlogin.login?mode=form&url=https%3A%2F%2Fwww.naver.com'
USER            = '아이디입력'
PASS            = '비밀번호입력'

# 브라우저 드라이버 객체 생성 ------------------------------
driver=webdriver.Chrome(CHROME_DRIVER)
driver.implicitly_wait(3)

# 로그인 페이지에 접근
driver.get(LOGIN_URL)
print("로그인 페이지에 접근합니다.")
driver.implicitly_wait(1)              # 3초 대기
driver.save_screenshot("login_01.png")  # 화면을 캡처 & 저장

# 텍스트 박스에 아이디와 비밀번호 입력
e = driver.find_element_by_id("id")
e.clear()
e.send_keys(USER)

e = driver.find_element_by_id("pw")
e.clear()
e.send_keys(PASS)
driver.implicitly_wait(1)                 # 3초 대기
driver.save_screenshot("login_02.png")    # 화면을 캡처 & 저장

driver.implicitly_wait(3)                # 잠시 대기

# 입력 양식 전송해서 로그인
form = driver.find_element_by_css_selector("input.btn_global[type=submit]")
form.submit()
print("로그인 버튼을 클릭합니다.")


