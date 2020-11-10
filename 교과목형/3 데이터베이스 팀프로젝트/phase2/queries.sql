--Q1 가입한 고객은 몇 명인가?
SELECT COUNT(*) FROM ACCOUNT;

--Q2 관리자의 이름과 주소는 무엇인가?
SELECT CONCAT(first_name, ' ', last_name) AS name, address FROM ACCOUNT WHERE is_admin=TRUE;

--Q3 평가를 5 개이상 한 고객은 몇 명인가?
select COUNT(*) FROM account where account_id in (select account_id from rating GROUP BY account_id HAVING COUNT(*) > 4);

--Q4 2020 년에 상영한 ‘Romance’ 장르의 영상물은 몇 개인가?
SELECT COUNT(*) FROM MOVIE, MOVIE_GENRE WHERE (start_year between date '2020-01-01' and '2020-12-31')  and genre_name='Romance' AND MOVIE.movie_id = MOVIE_GENRE.movie_id;

--Q5 2018/10/07 로부터 2 년동안 상영된 영상물은 몇 개인가?
SELECT COUNT(*) FROM MOVIE WHERE ( start_year BETWEEN date '2018-10-07' AND '2020-10-07' );

--Q6 2020/10/07 을 기준으로 지난 5 년간 상영된 영상물의 평균 평점은 몇점인가?
SELECT MAX(Ratings),MIN(Ratings),AVG(Ratings),count(*) FROM MOVIE, RATING WHERE (start_year BETWEEN date '2015-10-07' AND '2020-10-07' ) AND MOVIE.movie_id = Rating.Movie_id;

--Q7 모든 영상물을 대상으로 재생시간이 100 분 이상인 영상물은 몇개인가?
SELECT COUNT(*) FROM MOVIE WHERE runtime >= 100;

--Q8 모든 영상물을 대상으로 장르가 ‘Action’ 또는 ‘Comedy’인 영상물중에 평점이 가장 높은 영상물의 제목은 무엇인가?
-- select ratings from rating where rating.movie_id in (select distinct movie_id from movie_genre where genre_name = 'Action' or genre_name = 'Comedy');
create view action_comedy as (select * from rating where movie_id in (select distinct movie_id from movie_genre where genre_name = 'Action' or genre_name = 'Comedy'));
-- select * from action_comedy_avg;
create view action_comedy_avg as (select movie_id, avg(ratings) from action_comedy group by movie_id);
SELECT DISTINCT movie.movie_id, movie_title FROM movie, action_comedy_avg WHERE movie.movie_id = action_comedy_avg.movie_id AND avg IN
(SELECT MAX(avg) FROM action_comedy_avg ) ;

--Q9 상영된 ‘TV Series’를 대상으로 Episode 가 10 개 이상인 TV Series 는 몇개인가?
select count(*) from movie where movie_id in (select movie_id from episode group by movie_id having count(*) > 9);

--Q10 평가를 한 번도 하지 않은 고객 중 가장 나이가 많은 고객의 이름과 나이는 무엇인가?
create view no_rate_account1 as (select * from account where account_id in (select account_id from account except select DISTINCT account_id from rating));
select CONCAT(first_name,' ', last_name) AS name, (CAST(REPLACE(CAST(CURRENT_DATE AS TEXT),'-','') AS INTEGER) - CAST(REPLACE(CAST(birthday AS TEXT),'-','') AS INTEGER)) / 10000 as age from no_rate_account1 A1 where not exists (select * from no_rate_account1 A2 where A2.birthday < A1.birthday);

--Q11 평가 내역이 1 건만 있는 고객 중에 직업 정보를 입력한 고객은 몇 명인가?
create view one_rate_account as (select * FROM account where account_id in (select account_id from rating GROUP BY account_id HAVING COUNT(*) = 1));
select count(*) from one_rate_account where job like '%';

--Q12 모든 배우를 대상으로 작업한 모든 영상물의 평균 평점이 8 점이상인 배우의 이름은 무엇인가?
create view movie_avg_rate as (select  movie_id, avg(ratings) from rating group by movie_id);
create view movie_actor_with_avg8 as (select starred_by.movie_id,actor_id,avg from (starred_by join movie_avg_rate on (starred_by.movie_id = movie_avg_rate.movie_id and avg >= 8)));
select concat(real_first_name, ' ', real_last_name) from actor where actor_id in (select distinct actor_id from movie_actor_with_avg8);

--Q13 장르가 ‘Action’이 아니고 평점이 6 점 미만이며 상영 년도가 2010 년 이상인 영상물 중에 종류가 ‘Movie’에 출연한 배우의 이름과 영화의 제목은 무엇인가?
create view q13_1 as (select movie.movie_id, start_year from (movie_avg_rate join movie on movie.movie_id = movie_avg_rate.movie_id) where avg < 6 and start_year > '2010-01-01');
create view q13_2 as (select movie_id from q13_1 where movie_id in (select movie_id from movie_genre where genre_name = 'Action'));
select movie_title, concat(actor.Real_first_name, ' ', real_last_name) from (((q13_2 join movie on q13_2.movie_id = movie.movie_id) join starred_by on q13_2.movie_id = starred_by.movie_id)) join actor on starred_by.actor_id = actor.actor_id;

--Q14 멤버쉽이 ‘프라임’인 고객 중에 가장 젊은 고객을 대상으로 그 사람의 생년월일 중에 '년'과 일치하는 상영 년도를 가진 영상물은 몇 개 있는가?
create view q14 as (select m.movie_id from movie m where EXTRACT(YEAR FROM m.start_year::date) = (select EXTRACT(YEAR FROM max(birthday)::date ) from account a where a.membership_status = 'Prime'));
select count(*) from q14;

--Q15 평가를 10 개 이상 한 고객들 중에 멤버쉽이 ‘프리미엄’인 고객이 평가한 영상물의 종류가 ‘TV Series’가 아니고 평점이 8 점 미만인 영상물 중 가장 최신의 영상물의 상영 년도는 몇 년도인가?
create view q15 as (select movie_id from rating where account_id in ((select account_id from rating group by account_id having count(*) >= 10) intersect (select account_id from account where membership_status='Premium')));
select EXTRACT(YEAR FROM max(start_year)::date) from movie where (movie_id in (select movie_avg_rate.movie_id from (movie_avg_rate join q15 on movie_avg_rate.movie_id = q15.movie_id) where avg < 8)) and movie.type <> 'TV Series';

--Q16 가장 높은 평점을 가진 영상물을 평가한 고객들 중에 주소 정보를 입력한 고객들을 대상으로 그 주소의 길이가 가장 긴 고객의 전화번호는 무엇인가?
create view q16_1 as (select account_id from rating where rating.movie_id in (select m1.movie_id from movie_avg_rate m1 where (not exists (select * from movie_avg_rate m2 where m1.avg < m2.avg)) and m1.avg is not null));
create view q16_2 as select account.account_id, account.address, account.phone_number from (account join q16_1 on account.account_id = q16_1.account_id);
select A1.Phone_number from q16_2 A1 where (not exists (select * from q16_2 A2 where length(A1.address) < length(A2.address))) and A1.address is not null;

--Q17 영상물을 세 번째로 많이 촬영한 배우의 출연 영상물 중에 상영년도가 가장 오래된 영상물의 평점과 +1, -1 점 차이의 평점을 가진 영상물은 몇 개인가?
create view actor_starred_count as (select actor_id, count(*) from starred_by group by actor_id);
create view q17 as (select actor_id, movie_id from starred_by where actor_id in (select actor_id from actor_starred_count where count in (select distinct count from actor_starred_count order by count desc offset 2 limit 1)));
create view q17_1 as (select movie.movie_id, movie.start_year from (q17 join movie on q17.movie_id = movie.movie_id)); 
create view q17_2 as (select avg from movie_avg_rate where movie_id in (select A1.movie_id as name from q17_1 A1 where (not exists (select * from q17_1 A2 where A2.start_year < A1.start_year)) and A1.start_year is not null));
create view q17_3 as ((select * from movie_avg_rate where (select * from q17_2)-1 = avg) union (select * from movie_avg_rate where (select * from q17_2)+1 = avg));
select count(*) from q17_3;

--Q18 모든 영상물을 대상으로 버전이 5 개 이상 10 개 이하이고 종류가 ‘TV Series’ 또는 ‘Movie’이면서 출연한 배우의 수가 5 명 이하인 영상물의 평균 평점은 몇 점인가?
select AVG(ratings) from RATING where (movie_id, ratings) IN
  (select movie.movie_id, ratings FROM RATING, MOVIE where type = 'Movie' AND Movie.movie_id = rating.movie_id AND Movie.movie_id IN (select movie_id from version group by movie_id having count(*) between 4 and 10 )
                                                                          AND Movie.movie_id IN (select movie_id from starred_by group by movie_id having count(*) < 5 ) )
      OR (movie_id, ratings) IN
  (select movie.movie_id, ratings FROM RATING, MOVIE where type = 'Series' AND Movie.movie_id = rating.movie_id AND Movie.movie_id IN (select movie_id from version group by movie_id having count(*) between 4 and 10 )
                                                                          AND Movie.movie_id IN (select movie_id from starred_by group by movie_id having count(*) < 5 ) );

--Q19 가장 높은 평점을 가진 영상물에 출연한 배우들이 참여한 영상물중에 평점이 두 번째로 높은 영화의 재생 시간과 일치하는 재생시간을 가진 영상물의 제목은 무엇인가?
CREATE view participated_movies as ( select starred_by.movie_id, actor_id FROM movie_avg_rate, starred_by where (movie_avg_rate.movie_id, actor_id) IN(
      select movie_avg_rate.movie_id, actor_id from movie_avg_rate, starred_by where movie_avg_rate.movie_id = starred_by.movie_id and avg IN (SELECT MAX(avg) FROM movie_avg_rate )
    ) order by actor_id
);

-- 출연진들 영상물 모음 테이블 생성됨 --

select movie_id, runtime from movie where runtime IN
  (select runtime from movie, movie_avg_rate where movie.movie_id=movie_avg_rate.movie_id AND avg IN
    (SELECT MAX(movie_avg_rate.avg) from movie_avg_rate, participated_movies where movie_avg_rate.movie_id = participated_movies.movie_id and avg < (SELECT MAX(avg) FROM movie_avg_rate) ) )
EXCEPT
select movie_id, runtime from movie where (movie_id, runtime) IN
  (select movie.movie_id, runtime from movie, movie_avg_rate where movie.movie_id=movie_avg_rate.movie_id AND avg IN
    (SELECT MAX(movie_avg_rate.avg) from movie_avg_rate, participated_movies where movie_avg_rate.movie_id = participated_movies.movie_id and avg < (SELECT MAX(avg) FROM movie_avg_rate) ) );

--Q20 모든 영상물을 대상으로 여성 고객들에게 가장 많은 평가를 받은 영상물을 평가한 남성 고객들이 가장 평가를 많이 한 영상물의 장르를 포함하는 
--영상물 중 평가가 가장 적은 영상물의 상영 년도와 일치하는 생년을 가진 고객의 이름은 무엇인가?
create view q20_1 as (select movie_id, count(*) from (rating join account on rating.account_id = account.account_id) where account.sex = 'Female' group by movie_id);
create view q20_2 as select account_id from rating where movie_id in (select A1.movie_id from q20_1 A1 where not EXISTS (select * from q20_1 A2 where A1.count < A2.count)); 
create view q20_3 as (select * from movie_genre where movie_genre.movie_id in (select movie_id from rating where rating.account_id in (select account.account_id from (account join q20_2 on account.account_id = q20_2.account_id) where account.sex = 'Male')));
create view q20_4 as (select genre_name, count(*) from q20_3 GROUp by genre_name);
create view q20_5 as (select * from movie_genre where movie_genre.genre_name in (select A1.genre_name from q20_4 A1 where not EXISTS (select * from q20_4 A2 where A1.count < A2.count))); 
create view q20_6 as (select q20_5.movie_id, count(*) from (q20_5 join rating on q20_5.movie_id = rating.movie_id) group by q20_5.movie_id order by count(*));
select concat(first_name, ' ', last_name) from account where EXTRACT(YEAR FROM birthday::date) in (select EXTRACT(YEAR FROM start_year::date) from movie where movie_id in (select A1.movie_id from q20_6 A1 where not EXISTS (select * from q20_6 A2 where A1.count > A2.count)));