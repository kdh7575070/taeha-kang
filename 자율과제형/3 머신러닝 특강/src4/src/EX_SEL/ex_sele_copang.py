# 모듈 로딩 ---------------------------------------------
from selenium import webdriver

# 변수 선언 ---------------------------------------------
# webdriver
CHROME_DRIVER   = r'D:\WebDriver\chromedriver.exe'

# web url
LOGIN_URL = "https://login.coupang.com/login/login.pang"
LIST_URL  = "https://my.coupang.com/purchase/list"
CART_URL  = "https://cart.coupang.com/cartView.pang"

# login info
USER     = "아이디입력"
PASS     = "비밀번호입력"

# 브라우저 드라이버 객체 생성 ------------------------------
driver=webdriver.Chrome(CHROME_DRIVER)
driver.implicitly_wait(3)

# 로그인 페이지에 접근
driver.get(LOGIN_URL)
print("로그인 페이지에 접근합니다.")
driver.implicitly_wait(1)               # 3초 대기
driver.save_screenshot("login_01.png")  # 화면을 캡처 & 저장

# 텍스트 박스에 아이디와 비밀번호 입력
e = driver.find_element_by_id("login-email-input")
e.clear()
e.send_keys(USER)

e = driver.find_element_by_id("login-password-input")
e.clear()
e.send_keys(PASS)
driver.implicitly_wait(1)                # 3초 대기
driver.save_screenshot("login_02.png")   # 화면을 캡처 & 저장

# 입력 양식 전송해서 로그인
form = driver.find_element_by_css_selector("body > div.member-wrapper.member-wrapper--flex > div > div > form > div.login__content.login__content--trigger > button")
form.submit()
print("로그인 버튼을 클릭합니다.")

# 쇼핑 페이지의 데이터 가져오기
driver.get(LIST_URL)
driver.implicitly_wait(3)                # 3초 대기

driver.get(CART_URL)
driver.implicitly_wait(3)                # 3초 대기

# 쇼핑 목록 출력하기 ---------------------------------------------------------
products = driver.find_elements_by_css_selector(" td.product-box > div.product-name-part > a")
print(products)
for product in products:
    print("-", product.text)


