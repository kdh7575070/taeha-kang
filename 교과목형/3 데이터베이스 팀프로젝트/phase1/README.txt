조건에서 주어진 7개의 Entity(Movie, Genre, Actor, Rating, Episode, Version, Account)만을 사용했습니다.
 
1. Movie
모든 영상물은 movie_id 라는 unique한 key attribute을 가집니다. 그외 attribute에는 movie_title은 제목을, type은 드라마,영화,다큐멘터리 와 같은 종류를, series_number은 만약 시리즈물의 경우 그 번호를, isAdult는 성인영화 여부를, start_year과 end_year은 각각 기준 실제 상영 시작 년도와 끝 년도를 기록합니다. 이외에도 multi-value attribute으로 directors을 저장하며, average_rating과 num_likes는 각각 Rated_by relationship의 rating, like attribute로 부터 계산되는 derived attibutes가 있습니다.

 
1-1. Series
Series는 Recursive Relationship으로서 Series물들의 관계를 나타내줍니다. 각 시리즈들마다 첫(ex-해리포터 마법사의 돌) 번째 시리즈를 Parent로, 나머지 2,3,4(ex-비밀의 방, 아즈카반의 죄수, 불의잔...)번째 시리즈를 Child로 설정하였습니다. 이때 시리즈들의 순서는 Movie의 series_number attitude에 저장되어있습니다.
 
2. Genre
코미디, 액션, 멜로와 같은 genre가 key attribute로서 존재하는 Entity입니다.
 
2-1. Is
Movie 와 Genre Entity사이의 Relationship으로서 하나의 영화는 여러 개의 장르를 가질 수 있고, 하나의 장르에는 여러 개의 영화가 포함될 수 있으므로 N:M관계로 연결했습니다. 이때 각각의 Genre는 Movie를 최소 하나씩 가지고, 각각의 Movie는 최소 한개의 Genre를 가지도록 두 Entity 모두 Is라는 Relationship에 Total Participation으로 설정했습니다.
 
3. Actor
배우들의 정보를 저장하고 있는 Entity로서 actor_id를 key attribute로 가지며 이름정보와 성별 정보를 저장하는 real name과 sex를 attribute로 가집니다.
 
3-1. Starred_by
Movie 와 Actor Entity사이의 Relationship으로서  하나의 Movie에는 여러 명의 Actor이 출연하고, 각 Actor도 여러 Movie에 출연하므로 N:M관계로 연결했습니다. 이때 각각의 Actor는 최소 한편의 Movie에 출연하고 모든 영화는 최소 한 명의 Actor를 가지도록 두 Entity를 Is라는 Relationship에 Total Participation으로 설정했습니다. 또한 Starred_by Relationship에는 배우의 해당 영화에서의 이름인 cast_name attribute와 배우의 해당 영화에서의 주연여부를 저장하는 is_main attribute이 Relationship에 연결되어 있습니다.
 
4. Rating
Movie와 Accounts라는 Entity가 있어야 존재할 수 있기 때문에 weak Entity입니다. 평가에 대한 정보를 가지고 있는 Entity로 때문에 각 Rating들의 unique한 정보를 지정할 rating_id를 partial key 로 가집니다.

4-1. Gets
Movie와 Rating사이의 identifying Relationship으로서 하나의 Movie가 여러개의 Rating을 가질 수 있으므로 1:N관계로 연결했습니다. Entity와 weak Entity간의 Relationship에서 weak Entity(Rating Entity)쪽은 반드시 Relationship에 Total Participation으로 설정되어야 합니다. 모든 Movie에 Rating이 달리는 것은 아니므로 Movie Entity는 Total Participation이 아닙니다.
 
5. Episode
Movie라는 Entity가 있어야 존재할 수 있기 때문에 weak Entity입니다. 주로 Episode가 나눠지는 다큐멘터리나 드라마에 대해서 Episode별 정보를 담고 있는 Entity입니다. 각 Episode의 순서인 episode number를 partial key 로 가지며, 그 제목인 episode title역시 attibute로 가집니다.

 
5-1. Has
Movie와 Episode사이의 identifying Relationship으로서 하나의 Movie(여기서는 드라마나 다큐멘터리가 해당됩니다)가 여러개의 Episode을 가질 수 있으므로 1:N관계로 연결했습니다. Entity와 weak Entity간의 Relationship에서 weak Entity(Episode Entity)쪽은 반드시 Relationship에 Total Participation으로 설정되어야 합니다. 모든 Movie(특히 영화)는 여러개의 Episode를 가질 필요가 없으므로 Movie Entity는 Total Participation이 아닙니다.
 
6. Version
Movie라는 Entity가 있어야 존재할 수 있기 때문에 weak Entity입니다. Movie는 상영되는 나라에 따라 언어나 제목이 다른데, 그 정보를 담고 있는 Entity입니다. 상영되는 나라 정보인 region을partial key 로 가지며, 번역된 언어를 language라는 attribute로, 번역된 제목을 local_title이라는 attribute로 가지며 또다른 attribute인 start_year과 end_year은 각각 기준 실제 상영 시작 년도와 끝 년도를 기록합니다. 여기에는 기존에 Movie Entity에 있는 original version에 대한 정보도 기록되므로 Is_original이라는 attribute은 그것을 체크해주기 위해 존재합니다.
 
6-1. Distributed_by
Movie와 Version사이의 identifying Relationship으로서 하나의 Movie(특히 영화)는 여러개의 Version을 가질 수 있으므로 1:N관계로 연결했습니다.  Entity와 weak Entity간의 Relationship에서 weak Entity(Version Entity)쪽은 반드시 Relationship에 Total Participation으로 설정되어야 합니다. Movie(특히 드라마나 다큐멘터리)는 다른 나라에서 취급되지 않는 경우도 있으므로 Movie Entity는 Total Participation이 아닙니다.
 
7. Account
사용자 정보를 담고 있는 Entity입니다. 사용자 아이디를 account_id라는 key attribute로, 비밀번호, 전화번호, 이름, 주소, 성별, 생년월일, 직업, 맴버쉽 상태를 각각 password, phone_number, name, address, sex, birthday, job, membership_status라는 attribute로 설정했습니다. 이때 name은 composite attribute으로 first_name (이름)과 last_name (성) 이라는 attribute의 결합입니다. 필수정보는 문자 뒤에*를 표시하여 구분하였습니다.
 
4-7. Rated_by
Account와 Rating사이의 identifying Relationship으로서 하나의 Account가 (특히 영화)는 여러개의 Rating을 남길 수 있으므로 1:N(편의상 M)관계로 연결했습니다. Account에 대해서도 Rating은 Weak Entity가 되는데, Entity와 weak Entity간의 Relationship에서 weak Entity(Rating Entity)쪽은 반드시 Relationship에 Total Participation으로 설정되어야 합니다. 유저가 반드시 평가를 남길 필요는 없으므로 Account Entity는 Total Participation이 아닙니다. 또한 Rated_by Relationship에는 유저가 Rating에 남기는 문자리뷰인 review, 평가 점수인 rating, 좋아요 여부인 like가 attribute으로써 해당 Relationship에 연결되어 있습니다.

