from selenium.webdriver import Firefox, FirefoxOptions

# 변수 선언 ---------------------------------------------
FIRE_DRIVER =   r'D:\WebDriver\geckodriver.exe'
url         =   'http://www.daum.net/'
CAP_IMG     =   '../../data/daum02.png'

# 브라우저 드라이버 객체 생성 ------------------------------
options=FirefoxOptions()
options.add_argument('-headless')
driver=Firefox(executable_path=FIRE_DRIVER, options=options)

# 브라우저 원격 제어 --------------------------------------
driver.get(url)
driver.find_element_by_xpath('//*[@id="q"]').send_keys('안녕하세요.')

driver.implicitly_wait(3)                                   # 3초 대기
driver.find_element_by_xpath('//*[@class="ico_pctop btn_search"]').click()
driver.save_screenshot(CAP_IMG)                             # 화면을 캡처 & 저장
driver.quit()                                               # 브라우저 종료

