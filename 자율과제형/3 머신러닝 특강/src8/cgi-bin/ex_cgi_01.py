# 모듈 로딩 ------------------------------------
import cgi

# WEB 페이지 <Form> -> <INPUT> 리스트 가져오기
form = cgi.FieldStorage()

# <Form> -> <INPUT> 값 읽어오기
name = form.getvalue('name')
msg  = form.getvalue('msg')

# URL : http://localhost:8080/cgi-bin/ex_cgi_01.py?name=TOM&msg=JANE
print ("Content-type:text/html\r\n\r\n")
print ("<html>")
print ("<head>")
print ("<title>Hello - Second MYSERVER Program</title>")
print ("</head>")
print ("<body>")
print ("<h2>Hello %s %s</h2>" %(name, msg))
print ("</body>")
print ("</html>")