# 파이썬 매뉴얼을 재귀적으로 다운받는 프로그램
# 모듈 로딩 -----------------------------------------------
from bs4 import BeautifulSoup
from urllib.request import *
from urllib.parse import *
from os import makedirs
import os.path, time, re

# 처리 여부 체크 -------------------------------------------------
proc_files = {}

# HTML 내부에 있는 링크 추출 함수 -------------------------
def enum_links(html, base):
    soup = BeautifulSoup(html, "html.parser")
    links = soup.select("link[rel='stylesheet']")   # CSS
    links += soup.select("a[href]")                 # 링크
    result = []
    # href 속성을 추출하고, 링크를 절대 경로로 변환
    for a in links:
        href = a.attrs['href']
        url  = urljoin(base, href)   # 절대경로로 변환
        result.append(url)
    return result

# 파일 다운 & 저장 함수 -----------------------------------------
def download_file(url):
    # url 파싱
    o = urlparse(url)
    print("download_file o => ", o)

    # 다운 파일 저장 폴더 생성
    savepath = "./" + o.netloc + o.path
    if re.search(r"/$", savepath): # 폴더라면 index.html
        savepath += "index.html"
    savedir = os.path.dirname(savepath)
    print("download_file savedir => ", savedir)
    print("download_file savepath => ", savepath)

    # 폴더 존재 여부 확인 후 리턴
    if os.path.exists(savepath): return savepath
    # 다운받을 폴더 생성
    if not os.path.exists(savedir):
        print("mkdir=", savedir)
        makedirs(savedir)

    # 파일 다운받기 -----------------
    try:
        print("download=", url)
        urlretrieve(url, savepath)
        time.sleep(1)           # 1초 일시정지
        return savepath
    except:
        print("다운 실패: ", url)
        return None


# HTML 분석 & 다운받는 함수 ------------------------------------
def analyze_html(url, root_url):
    savepath = download_file(url)

    if savepath is None:
        return
    if savepath in proc_files:
        return

    proc_files[savepath] = True
    print("analyze_html=", url)

    # index.html 파일에서 링크 추출 ------------------------------------
    html = open(savepath, "r", encoding="utf-8").read()
    links = enum_links(html, url)
    for link_url in links:
       print('link_url => ', link_url)
       # 링크가 루트 이외의 경로를 나타낸다면 무시
       if link_url.find(root_url) != 0:
            if not re.search(r".css$", link_url): continue
       # HTML이라면
       if re.search(r".(html|htm)$", link_url):
            # 재귀적으로 HTML 파일 분석하기
            analyze_html(link_url, root_url)
            continue
       # 기타 파일
       download_file(link_url)

if __name__ == "__main__":
    url = "https://docs.python.org/3.5/library/"
    analyze_html(url, url)