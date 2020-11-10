from selenium import webdriver
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
import pyperclip
import time
from bs4 import BeautifulSoup

# 데이터변수 선언 -------------------------------------------------------------------------------
chrom_driver = 'C:\Program Files/WebDriver\chromedriver.exe'
LOGIN_URL    = 'https://nid.naver.com/nidlogin.login?mode=form&url=https%3A%2F%2Fwww.naver.com'
id           = 'scanf_dream'
pw           = 'rkdek%5078'


#클립보드에 input을 복사한 뒤 해당 내용을 actionChain을 이용해 로그인 폼에 붙여넣기 ---------------
def copy_input(xpath, input):
    pyperclip.copy(input)
    driver.find_element_by_xpath(xpath).click()
    ActionChains(driver).key_down(Keys.CONTROL).send_keys('v').key_up(Keys.CONTROL).perform()
    time.sleep(1)


# 드라이브 객체 생성 및 제어 -----------------------------------------------------------------
driver = webdriver.Chrome(chrom_driver)
driver.implicitly_wait(3)
driver.get(LOGIN_URL)
time.sleep(1)

# Login 기능 구현 ------------------------------------------------------------
copy_input('//*[@id="id"]', id)
time.sleep(1)
copy_input('//*[@id="pw"]', pw)
time.sleep(1)

driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/input').click()
time.sleep(3)

# 쇼핑 리스트 가져오기 -----------------------------------------------------------
driver.get("https://order.pay.naver.com/home?frm=s_logo")
with open('get.text', mode='w', encoding='utf-8') as file:
    file.write(driver.page_source)

soup = BeautifulSoup(driver.page_source, "html.parser")
div_list = soup.select('ul.goods_group_list >li > div.goods_item > div.goods_info p.name')
for div in div_list:
    print( div.get_text())