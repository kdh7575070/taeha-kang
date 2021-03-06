# ER to Relational Model 설명

## 1.
7개의 Entity type은 각각 MOVIE, GENRE, ACTOR, RATING, EPISODE, VERSION, ACCOUNT 이렇게 7개의 Entity Relation이 되었다.

## 2.
1:N Relationship type 인  HAS Relationship은 MOVIE Relation(1)을 참조하여 EPISODE Relation(N)의 Primary Key를 생성한다. EPISODE가 Weak Entity이었으므로, 참조받은 Movie_id와 기존의 Partial Key인 Episode_number의 쌍이 합쳐진 (Movie_id, Episode_number)가 EPISODE Relation의 Primary Key가 된다. \
1:N Relationship type 인 DISTRIBUTED_BY Relationship은 MOVIE Relation(1)을 참조하여 VERSION Relation(N)의 Primary Key를 생성한다. VERSION이 Weak Entity이었으므로, 참조받은 Movie_id와 기존의 Partial Key인 Version_id의 쌍이 합쳐진 (Movie_id, Version_id)가 VERSION Relation의 Primary Key가 된다. \
1:N Relationship type 인 GETS Relationship은 MOVIE Relation(1)의 Primary Key인 Moive_id를 RATING Relation(N)의 Foreign Key로 받아온다. 또 1:N Relationship type 인 RATED_BY Relationship은 ACCOUNT Relation(1)의 Primary Key인 Account_id를 RATING Relation(N)의 Foreign Key로 받아온다. Account 한명은 각각의 Movie에 하나의 Rate 정보만 가져야 하므로 (Movie_id, Account_id)는 Uniqueness property를 부여받는다. Key attribute은 Rating_id 이며, RATED_BY Relationship에 있던 Attribute likes와 ratings은 RATING Relation의 Attribute가 된다.

## 3.
1:1 Relationship type인 SERIES는 MOVIE Relation 내부에서 Parent_id라는 속성이 되어 Movie Relation 자체를 참조한다.

## 4.
M:N Relationship type인 MOVIE_GENRE Relationship은 하나의 Relation이 되어, MOVIE Relation과 GENRE Relation을 참조하여 참조받은 Foriegn Key 둘을  합친 (Genre_name, Moive_id)를 Primary Key로 가진다. \
M:N Relationship type인 STARRED_BY Relationship은 하나의 Relation이 되어, MOVIE Relation과 ACTOR Relation을 참조하여 참조받은 Foreign Key 둘을 합친 (Moive_id, Actor_id)를 Primary Key로 가진다. 이때 STARRED_BY Relationship에 있던 Is_main, Cast_name은 ACTOR Relation의 Attribute가 된다.

## 5.
각 Entity의 Simple attribute 들은 Attribute가 되었고, Director, Real_name, Cast_name, Name에 해당하는 Composite Attribute들은 각각의 component인 First_name, Last_name이 Attribute이 되었다. 또한 각 Entity의 Key attribute는 Relation에서 Primary Key가 되었다.

## 6.
Moive_id, Account_id, Rating_id, Actor_id 는 Surrogate Key로 지정했다. 또한 User_id는 회원가입시 입력받는 id로, 중복되면 안되므로 Uniqueness property를 부여한다.

### 수정사항
- MOVIE와 EPISODE의 Entity에 상영 시간 정보를 분으로 저장하는 runtime attribute를 추가
- ACCOUNT Entity에 관리자 여부를 표시하는 is_admin attribute를 추가
- VERSION Entity에 version을 넘버링하는 version_id를 key attribute로 추가하고, 기존의 key attribute인 region은 일반 attribute로 변경
- ACCOUNT Entity의 Account_id를 사용자 식별번호로 설정하여 사용자 id를 받아오는 user_id라는 key attribute을 추가
- MOVIE Entity에 multivalue attribute director를 일반 attribute로 변경
- GENRE Entity에 genre attribute의 이름을 genre_name으로 변경
- real_name, cast_name, director를 각각 first_name과 last_name attribute를 받는 composite attribute로 변경
- 예약어 Like, Is, 테이블 Rating과의 충돌방지를 위해 Rating Entity의 like, rating attribute을 likes, ratings로, IS라는 Entity name을 MOVIE_GENRE로 변경
- MOVIE Entity에 end_year, RATED_BY Relationship에 review attribute를 제거
- not null attribute *로 표시
- RATING Entity를 weak Entity에서 일반 Entity로 변경(Rating_id를 각 rating별 식별번호를 담은  key attribute 지정하여 독립적으로 식별가능하게 함)
- 이에 GETS, RATED_BY Relationship 역시 Identifing relationship에서 일반 relationship으로 변경
