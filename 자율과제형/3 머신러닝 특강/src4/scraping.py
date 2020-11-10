from selenium import webdriver

# 크롬 브라우저 제어 드라이버 생성
driver=webdriver.Chrome('C:\Program Files/WebDriver/chromedriver.exe')

# 크롬 브라우저 드라이버를 활용한 원격 웹 페이지 제어
# URL 열기
driver.get("https://www.naver.com")

# WEB 페이지의 특정 요소에 접근
# //*[@id="query"]
driver.find_element_by_xpath('//*[@id="query"]').send_keys('안녕하세요.')