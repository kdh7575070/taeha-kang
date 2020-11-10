# 모듈 로딩 ---------------------------------------------
from selenium import webdriver

# 변수 선언 ---------------------------------------------
url             = 'http://www.naver.com/'
CHROME_DRIVER   = r'D:\WebDriver\chromedriver.exe'
CAP_IMG         = '../../data/website.png'

# 브라우저 드라이버 객체 생성 ------------------------------
driver=webdriver.Chrome(CHROME_DRIVER)

# 브라우저 원격 제어 --------------------------------------
driver.implicitly_wait(3)                          # 3초 대기
driver.get(url)                                    # URL 읽기
driver.save_screenshot(CAP_IMG)                     # 화면 캡처 & 저장
driver.quit()                                      # 브라우저 종료