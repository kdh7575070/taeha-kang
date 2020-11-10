# 모듈로딩-------------------------
import MySQLdb

# MySQL 데이터베이스 제어 -----------------------
# (1) MySQL 연결
conn = MySQLdb.connect(
        user='root',
        passwd='test-password',
        host='localhost',
        db='test')

# (2) 데이터베이스 제어
# (2-1)데이터베이스 접근 커서 추출
cur = conn.cursor()
# (2-2) 테이블 생성
cur.execute('DROP TABLE items')
cur.execute('''
    CREATE TABLE items (
        item_id INTEGER PRIMARY KEY AUTO_INCREMENT,
        name TEXT,
        price INTEGER
    )
    ''')

# (2-3)데이터 추가
data = [('Banana', 300),('Mango', 640), ('Kiwi', 280)]
for i in data:
    cur.execute("INSERT INTO items(name,price) VALUES(%s,%s)", i)

# (2-4) 데이터 추출
cur.execute("SELECT * FROM items")
for row in cur.fetchall():
    print(row)