from selenium.webdriver import Firefox, FirefoxOptions

# 변수 선언 ---------------------------------------------
FIRE_DRIVER =   r'D:\WebDriver\geckodriver.exe'
url         =   'http://www.daum.net/'
CAP_IMG     =   '../../data/daum.png'

# 브라우저 드라이버 객체 생성 ------------------------------
options=FirefoxOptions()
options.add_argument('-headless')
browser=Firefox(executable_path=FIRE_DRIVER, options=options)

# 브라우저 원격 제어 --------------------------------------
browser.implicitly_wait(3)                           # 3초 대기
browser.get(url)                                     # URL 읽기
browser.save_screenshot(CAP_IMG)                     # 화면 캡처 & 저장
browser.quit()                                       # 브라우저 종료
print("SEL-FIRE END")