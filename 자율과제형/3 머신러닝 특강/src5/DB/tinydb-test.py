# 모듈 로딩 ------------------------------------
from tinydb import TinyDB, Query

# 데이터 변수 선언 ------------------------------
DB_FILE = "test-tynydb.json"

# 데이터베이스 연결-------------------------------
db = TinyDB(DB_FILE)

# 데이블 생성 ------------------------------------
db.purge_table('fruits')
table = db.table('fruits')

# 테이블에 데이터 추가------------------------------
table.insert( {'name': 'Banana', 'price': 6000} )
table.insert( {'name': 'Orange', 'price': 12000} )
table.insert( {'name': 'Mango', 'price': 8400} )

# 모든 데이터 출력하기 ---------------------------
print(table.all())

# 특정 데이터 추출하기
# Orange 검색하기--------------------------------
Item = Query()
res = table.search(Item.name == 'Orange')
print('Orange is ', res[0]['price'])

# 가격이 8000원 이상인 것 추출---------------
print("8000원 이상인 것:")
res = table.search(Item.price >= 8000)
for it in res:
    print("-", it['name'])