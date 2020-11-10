# 모듈 로딩 ------------------------------------
import cgi

# WEB 페이지 <Form> -> <INPUT> 리스트 가져오기
form = cgi.FieldStorage()

# <Form> -> <INPUT> 값 읽어오기
math_flag    = "ON" if form.getvalue('maths')   else "OFF"
physics_flag = "ON" if form.getvalue('physics') else "OFF"

# URL : http://localhost:8080/cgi-bin/ex_cgi_02.py
print ("Content-type:text/html\r\n\r\n")
print ("<html>")
print ("<head>")
print ("<title>Hello - Second MYSERVER Program</title>")
print ("</head>")
print ("<body>")
print ("<h2> CheckBox Maths is : %s</h2>" % math_flag )
print ("<h2> CheckBox Physics is : %s</h2>" % physics_flag )
print ("""
<form>
   <input type = "radio" name = "maths"   value = "maths" /> Maths
   <input type = "radio" name = "physics" value = "physics" /> Physics
   <input type = "submit" value = "Select Subject" />
</form>""")
print ("</body>")
print ("</html>")