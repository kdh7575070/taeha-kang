#  프로젝트에 대한 간단한 소개

-OS : ubuntu 18.04\
-DBMS : PostgreSQL 13.0

## phase 1.
KNUmovieDB라고 하는 IMDB를 표방한 영화 데이터 사이트를 만들기 위해서, 필요한 conceptual model을 완성합니다.\
erwin이라는 전문 프로그램을 통해 er model을 그렸습니다.\
<img src="https://user-images.githubusercontent.com/67677983/99939675-f51f6680-2dad-11eb-8679-20103621a040.jpg" width="300">

## phase 2.
완성된 er model을 relational model으로 매핑시킨 뒤에 SQL를 사용하여 물리적 데이터베이스를 정의, 정의된  데이터베이스에  실제  데이터를 적재합니다. \
DMBS는 Postgrads를 썼고 임의의 대량 데이터를 생성한 뒤 sql파일에 dml형식으로 짜두고, 전체 파일을 실행시킴으로써 데이터를 일괄적으로 데이터베이스에 삽입했습니다. \
이후 교수님이 요구하신 20개 정도의 매우 심화된 query문을 짰고 queries 파일에 저장해두었습니다.
<img src="https://user-images.githubusercontent.com/67677983/99939700-fe103800-2dad-11eb-885d-fe05c7c323f0.png" width="500">

## phase 3.
따로 [레포지토리](https://github.com/kdh7575070/comp322)가 있어서 링크합니다. 꼭 클릭하여 이동해주십시오. *위에 push된 파일은 무시해주셔도 됩니다.* \
DB에 새로운 데이터를 넣는 것을 jdbc를 이용해서 어플리케이션화 했습니다.

### 코드리뷰 [MAIN함수에 대해서]
    public class MAIN {
	  public static void main(String[] args) throws ClassNotFoundException, SQLException {

		// 회원객체생성
		Account a1 = new Account();
		a1.setUser_id("newadmin@newsvine.com");
		a1.setPassword("admin2010");
		a1.setFirst_name("Bill");
		a1.setLast_name("Gates");
		a1.setPhone_number("01022223333");
		a1.setIs_admin(true);
		
		// 1A 회원가입
		System.out.print("1A. User_id = " + a1.getUser_id() +
						   ", Name = " + a1.getFirst_name() + a1.getLast_name() +
						   ", Address = " + a1.getAddress() +
						   " / ");
		AccountService.create_account(a1);
		System.out.println();
		
		// 1D 로그인
		String try_userid = "newadmin@newsvine.com";
		String try_password = "admin2010";
		
		String loginuser = AccountService.login(try_userid, try_password);
		System.out.println();
		
		// 수정될 객체 생성
		String new_first_name = "Jongbin";
		String new_last_name = "Woo";
		String new_phone_number = "01012345678";
		Date new_birthday = java.sql.Date.valueOf("2000-01-01");
		String new_sex = "F";
		String new_address = "Daegu Bukgo Gyeongdaero";
		String new_job = "Student";
		Account new_user_info = new Account(loginuser,new_first_name,new_last_name,new_phone_number,new_birthday,new_sex,new_address,new_job);
		
		// 1B 회원 정보 수정
		if(!(loginuser.equals(""))) AccountService.update_user_info(new_user_info);
		System.out.println();
		
		// 1C 비밀 번호 수정
		if(!(loginuser.equals(""))) AccountService.update_user_pwd(loginuser, "admin2020");
		System.out.println();
		
    
		// 2A 전체 영상물 보기
		if(!(loginuser.equals(""))) MovieService.show_all_movies();
		System.out.println();
		
		// 2B 제목으로 영상물 검색 
		if(!(loginuser.equals(""))) MovieService.search_movie(loginuser, "Future-proofed maximized budgetary management");
		System.out.println();
		
		// 2C 특정 조건으로 영상물 검색 & 2.E 회원이 평가한 영상물은 이후 검색대상에서 제외 
		ArrayList<String> movie_list = new ArrayList<String>();
		if(!(loginuser.equals(""))) movie_list = MovieService.srch_movie(loginuser, "Movie", "Action", "");
		System.out.println();
		
		// 2D 영화 상제정보 & 3D 평균평점 확인  
		MovieService.movie_info("Future-proofed maximized budgetary management");
		System.out.println();

		// 2D 해당 영상물을 평가
		if(!(loginuser.equals(""))) {
			MovieService.movie_rate(loginuser, movie_list.get(0), false, 8);
			System.out.println(" : " + movie_list.get(0));
		}
		System.out.println();
		
		
		// 3B 자신의 평가 내역을 확인 
		if(!(loginuser.equals(""))) AccountService.check_my_ratinglist(loginuser);
		System.out.println();
		
		// 3C 관리자는 모든 평가 내역을 확인 가능 
		if(AccountService.Is_admin(loginuser)) AdminService.view_all_ratings();
		else System.out.println("3C. Only admin can approach this view");
		System.out.println();
		
    
		// 영화객체생성
		Movie m1 = new Movie();
		m1.setMovie_title("NEW MOVIE 2020");
		m1.setType("Movie");
		m1.setIs_adult(false);
		m1.setRuntime(111);
		
		// 4A 관리자는 새로운 영상물을 등록 가능  
		System.out.println("4A. Movie = " + m1.getMovie_title() +
						   ", Start year = " + m1.getStart_year());
		AdminService.create_movie(m1);
		System.out.println();
		
		// 수정될 객체 생성
		Movie new_movie_info = new Movie();
		new_movie_info.setMovie_title("NEW MOVIE 2021");
		new_movie_info.setType("Movie");
		new_movie_info.setIs_adult(true);
		new_movie_info.setStart_year(java.sql.Date.valueOf("2000-01-01"));
		
		// 4B 관리자는 등록된 영상물을 수정 가능
		AdminService.update_movie_info(301, new_movie_info);
		System.out.println();
		
		// 1E 회원탈퇴 
		if(!(loginuser.equals(""))) AccountService.delete_account(loginuser);
//각 함수의 기능에 관해서는 위 레포지토리의 README.md 파일에 상세히 기록해두었음.

### Phase 3에 대한 구체적 설명
#### 1. 회원 관련 기능 
  A. 회원 가입 : 필수 정보를 포함한 정보들을 입력하여 가입.\
  B. 회원 정보 수정 : 회원은 본인 계정의 정보 수정이 가능. 단, ID는 수정 불가능.\
  C. 비밀 번호 수정 : 회원은 본인 계정의 비밀번호 수정이 가능.\
  D. 로그인 : 회원은 아이디와 비밀번호를 입력하고 Application에서 로그인.\
  E. 회원 탈퇴\
  F. 관리자 계정은 최소 1개 이상 필수
#### 2. 영상물 관련 기능
  A. 회원은 로그인 이후 영상물 전체를 볼 수 있다.\
  B. 회원은 로그인 이후 제목으로 등록된 영상물을 검색하는 것이 가능하다.\
  C. 회원은 로그인 이후 특정 조건으로 영상물을 검색할 수 있다.\
     예를 들어, 'Movie(Type)' + 'Romance(Genre)' or 'Action(Genre)' + 'KR(Version)'등의 조합으로 검색이 가능해야 한다.\
  D. 검색한 영상물 목록에서 한 영상물을 선택하면 그 영상물의 정보(제목, 종류, 재생시간, 상영 년도, 장르 등)을 확인할 수 있으며, 해당 영상물을 평가할 수 있다.\
  E. 회원이 평가한 영상물은 이후 검색 대상에서 제외한다.
#### 3. 평가 관련 기능
  A. 모든 평가 내역은 로그아웃, Application 종료 등을 한 뒤에도 유지된다.\
  B. 회원은 자신의 평가 내역을 확인할 수 있다.\
  C. 관리자는 모든 평가 내역을 확인할 수 있다.\
  D. 회원은 2-D에서 평균 평점을 확인할 수 있다.
#### 4. 관리자 기능 – 관리자 계정으로 접속하였을 때만 사용이 가능한 기능.
  A. 새로운 영상물을 등록할 수 있다.\
  B. 등록된 영상물의 정보를 수정할 수 있다.

## phase 4.
이전 단계에서 구축한 JDBC Application을 기반으로 JSP를 사용하여 간단한 영상물 DB 사이트를 웹으로 구현해 본다. \
현재 진행중입니다.
