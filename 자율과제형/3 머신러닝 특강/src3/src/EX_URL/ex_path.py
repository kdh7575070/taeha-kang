# 라이브러리 로딩 -------------------------------------
from urllib.parse import urljoin

# 데이터 변수 선언  ----------------------------------
base = "http://example.com/html/a.html"   # 현재 html 폴더

# 절대 경로 변환 ------------------------------------
print( urljoin(base, "b.html") )            # html 폴더 안에 존재
print( urljoin(base, "sub/c.html") )        # html 폴더 안에 sub폴더 안에 존재
print( urljoin(base, "../index.html") )     # html 밖에 존재
print( urljoin(base, "../img/hoge.png") )   # html 밖 img 폴더 안에 존재
print( urljoin(base, "../css/hoge.css") )   # html 밖 css 폴더 안에 존재

print( urljoin(base, "//mytest/hoge.css") )
print( urljoin(base, "http://test.com/test.html") )