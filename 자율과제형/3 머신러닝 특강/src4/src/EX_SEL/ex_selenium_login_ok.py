# 모듈 로딩 ---------------------------------------------
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# 변수 선언 ---------------------------------------------
CHROME_DRIVER =  r'D:\WebDriver\chromedriver.exe'
LOGIN_URL     = 'https://nid.naver.com/nidlogin.login?mode=form&url=https%3A%2F%2Fwww.naver.com'
PAY_URL       = 'https://order.pay.naver.com/home?frm=s_logo'
USER          = '아이디입력'
PASS          = '비밀번호입력'
script = "                                      \
(function execute(){                            \
    document.querySelector('#id').value = '" + USER + "'; \
    document.querySelector('#pw').value = '" + PASS + "'; \
})();"

# 브라우저 드라이버 객체 생성 ------------------------------
driver=webdriver.Chrome(CHROME_DRIVER)
driver.implicitly_wait(3)

# 로그인 페이지에 접근 ------------------------------------
driver.get(LOGIN_URL)
print("로그인 페이지에 접근합니다.")
driver.implicitly_wait(1)                   # 1초 대기
driver.save_screenshot("login_01.png")      # 화면을 캡처 & 저장

# 텍스트 박스에 아이디와 비밀번호 입력 JavaScript 실행
driver.execute_script(script)

#화면 로딩이 될때까지 대기후 버튼 입력 처리
element = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.CSS_SELECTOR, "input.btn_global"))
)
element.click()

# 쇼핑 페이지 이동 ------------------------------------------------------
time.sleep(3)
driver.get(PAY_URL)
time.sleep(3)



