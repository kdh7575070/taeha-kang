#  과제에 대한 간단한 소개
### 1. 오라클 db 설치
### 2. sqlplus 실습
<img src="https://user-images.githubusercontent.com/67677983/99945495-0ff6d880-2db8-11eb-81b6-975317201d13.PNG" width="600">

### 3. ER diagram 짜기
<img src="https://user-images.githubusercontent.com/67677983/99945522-1be29a80-2db8-11eb-8ebd-da00df132b60.png" width="400">

### 4. ER to Relational model 짜기
<img src="https://user-images.githubusercontent.com/67677983/99945536-2309a880-2db8-11eb-96ab-e0f023fa16dd.jpg" width="400">

### 5. sql plus를 통한 physical db 구축 [여기](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/3%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%20%EC%8B%A4%EC%8A%B5/lab5/lab5-2015112806.sql)
#### 코드리뷰
    CREATE TABLE DEPARTMENT(
        Dname VARCHAR(15) NOT NULL,
        Dnumber NUMBER NOT NULL,
        Mgr_ssn CHAR(9) DEFAULT '888665555' NOT NULL,
        Mgr_start_date DATE,
        PRIMARY KEY(Dnumber),
        UNIQUE(Dname)
     );
    --TABLE 만들기

    INSERT INTO EMPLOYEE VALUES ('John', 'B', 'Smith', '123456789', TO_DATE('1965-01-09', 'yyyy-mm-dd'), '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);
    INSERT INTO EMPLOYEE VALUES ('Franklin', 'T', 'Wong', '333445555', TO_DATE('1968-01-19', 'yyyy-mm-dd'), '368 Voss, Houstom, TX', 'F', 40000, '888665555', 5);
    INSERT INTO EMPLOYEE VALUES ('Alicia', 'J', 'Zelaya', '999887777', TO_DATE('1968-01-19', 'yyyy-mm-dd'), '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4);
    --DATA 삽입

    select Fname, Minit, Lname from Project, Works_on, Employee where DNO=5 and Salary >= 10000 and Pname = 'ProductZ' and Pno = Pnumber and Essn = ssn order by Lname ASC;
    select Dname, Ssn, Lname from Employee, Department where Address like '%Dallas%' and Dnumber = Dno and Super_ssn = '987654321';
    select Lname, Hours from Employee, Works_on, Project where Pname = 'ProductX' and Pno = Pnumber and Ssn = Essn order by Hours DESC;
    select Lname, Fname, Hours from Employee, Works_on, Project where Pname = 'Computerization' and Pno = Pnumber and Hours >= 10 and Ssn = Essn order by Hours ASC;
    select Fname, Relationship from Dependent, Employee where Essn = Ssn and Super_ssn = '333445555';
    --질의

    update Project p set p.Plocation = 'Houston' where Dnum = 5;
    select * from Project where Dnum = '5';
    update Employee e set e.Super_ssn = NULL where Ssn = '123456789';
    select * from Employee where Ssn = '123456789';
    --업데이트
    
### 6. jdbc를 통해 범용 어플리케이션 구축 [여기](https://github.com/kdh7575070/taeha-kang/blob/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/3%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%20%EC%8B%A4%EC%8A%B5/lab6/Lab6JDBC.java)
#### 코드리뷰
    try {
          Class.forName("oracle.jdbc.driver.OracleDriver"); // Load a JDBC driver for Oracle DBMS
          System.out.println("Success!"); //Get a Connection object
        }catch (ClassNotFoundException e) {
          System.err.println("error ="+e.getMessage());
          System.exit(1);
        }

        try {
          conn = DriverManager.getConnection(URL, USER_UNIVERSITY,USER_PASSWD);
        }catch (SQLException ex){
          ex.printStackTrace();
          System.err.println("Cannot get a connection: " + ex.getMessage());
          System.exit(1);
        }
    --드라이버연결

    conn.setAutoCommit(false);
    stmt = conn.createStatement();
    --Statement 객체 생성

    StringBuffer sb = new StringBuffer();
			sb.append("CREATE TABLE DEPARTMENT(Dname VARCHAR(15) NOT NULL,");
			sb.append("		  Dnumber NUMBER NOT NULL,");
			sb.append("		  Mgr_ssn CHAR(9) DEFAULT '888665555' NOT NULL,");
			sb.append("		  Mgr_start_date DATE,");
			sb.append("		  PRIMARY KEY(Dnumber),");
			sb.append("		  UNIQUE(Dname))");
			sql = sb.toString();
			res = stmt.executeUpdate(sql);
			if(res ==0)
				System.out.println("Table DEPARTMENT was successfully created.");
    --테이블 생성

    while((line = bufReader.readLine()) != null){
            	if(line.charAt(0)=='$'){
            		table_name = line.substring(1);
            	}
            	else{
            		String[] array = line.split("#");
            		sql = "INSERT INTO " + table_name + " VALUES(";
            		try {
            			switch(table_name) {
    	            	    case "DEPARTMENT": sql += "'"+array[0]+"', ";
    	            	    	sql += array[1]+", ";
    	            	    	sql += "'"+array[2]+"', ";
    	            	    	sql += "TO_DATE('"+array[3]+"', 'yyyy-mm-dd'))";
    	            	        break;
    --파일로부터 데이터 받아와서 INSERT

    sql = "(select MIN(Salary) from EMPLOYEE E, DEPENDENT where E.Sex = 'M' and  Relationship = 'Spouse' and Essn = Ssn) union (select MIN(Salary) from EMPLOYEE E, DEPENDENT where E.Sex = 'F' and Relationship = 'Spouse' and Essn = Ssn)";
			ResultSet rs = stmt.executeQuery(sql);
			while(rs.next()){
				int salary 	    = rs.getInt(1);
				System.out.println("Salary = " + salary);
			}
    --질의 날리기

### 7. 프로시져 생성 [여기](https://github.com/kdh7575070/taeha-kang/blob/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/3%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%20%EC%8B%A4%EC%8A%B5/lab7/lab7-1.sql)
#### 코드리뷰
    AS  
    BEGIN
      DECLARE
        CURSOR C1
        IS

          select Pnumber as Project_num, total_hours 
          from (select Pnumber from PROJECT where Dnum = department_num order by Pnumber) 
          natural join (select Pno as Pnumber, SUM(Hours) as total_hours FROM WORKS_ON group by pno);
      --nested begin 1  
      BEGIN
        DBMS_OUTPUT.PUT_LINE('1. receive a department number: ' || department_num);
        DBMS_OUTPUT.PUT_LINE('2. compute');
        DBMS_OUTPUT.PUT_LINE('department_num  | project_num |  total_hours');

        FOR records IN C1 LOOP
           EXIT WHEN C1%NOTFOUND;
           DBMS_OUTPUT.PUT_LINE(department_num || '                 ' || records.Project_num || '              ' ||records.total_hours);
        END LOOP;
    --Total hours를 구현하는 프로시져를 생성한다. 프로시져를 통해 일련의 쿼리를 함수화 할 수 있다.

### 8. jsp를 통해 웹 구현 연습
<img src="https://user-images.githubusercontent.com/67677983/99945688-67954400-2db8-11eb-95a6-5edd73d394ae.PNG" width="600">

#### 코드리뷰
    <h4>GET and POST Methods to Read Form Data</h4>
    <form action ="getData.jsp" method = "POST">
	<h4>Select which section you are taking</h4>
	<input type = "checkbox" name = "course" value="COMP322001"/> COMP322001
	<input type = "checkbox" name = "course" value="COMP322002"/> COMP322002
	<input type = "checkbox" name = "course" value="COMP322003"/> COMP322003
	    <input type = "checkbox" name = "course" value="COMP322004"/> COMP322004
	    <input type = "checkbox" name = "course" value="none" checked = "checked"/> Nothing
	    <input type = "submit" value="Submit"/>
    //POST방식을 통해 submit 버튼 클릭시 jsp 파일에 입력받은 데이터를 넘
[main.html](https://github.com/kdh7575070/taeha-kang/blob/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/3%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%20%EC%8B%A4%EC%8A%B5/lab8/WebContent/main.html)

    <h2>--Received from main.html the data shown below--</h2>
    <ul>
	<li><p>My name is
		<b><%= request.getParameter("first_name")%>
		<%= request.getParameter("last_name")%>.</b>
	</p></li>
	<li><p>My student ID is
		<b><%= request.getParameter("sID")%>.</b>
	</p></li>
	<li><p>I am taking
		<b><%= request.getParameter("course")%> this semester.</b>
	</p></li>
    //html에서 입력한 데이터를 넘겨받아서 화면에 출력
[getData.jsp](https://github.com/kdh7575070/taeha-kang/blob/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/3%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%20%EC%8B%A4%EC%8A%B5/lab8/WebContent/getData.jsp)

### 9. jsp를 통해 웹 구현 - DB와 연동
<img src="https://user-images.githubusercontent.com/67677983/99945692-69f79e00-2db8-11eb-96d2-9697a53e17c9.PNG" width="400">

#### 코드리뷰
    <form action ="response.jsp" method = "POST">
	    <h4>Q1 : Search for employees satisfying the following conditions:</h4>
	    Project name:
    	<select name="pName">
    		<option value = "ProductX" selected>ProductX</option>
    		<option value = "ProductY">ProductY</option>
    		<option value = "ProductZ">ProductZ</option>
    		<option value = "Computerization">Computerization</option>
    		<option value = "Reorganization">Reorganization</option>
    		<option value = "Newbenefits">Newbenefits</option>
    	</select>
    	Department number:
    	<select name="dNum">
    		<option value = "1" selected>1</option>
		<option value = "4">4</option>
		<option value = "5">5</option>
    	</select>
    //Q1 -> 어떤 프로덕트에 참여한 인원중에서 부서번호가 x번인 사람을 찾는 것
    //select-option tag를 이용해서 옵션중에 선택하는 view를 구현함
    //POST방식을 통해 submit 버튼 클릭시 jsp 파일에 입력받은 데이터를 넘겨줌
[view.html](https://github.com/kdh7575070/taeha-kang/blob/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/3%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%20%EC%8B%A4%EC%8A%B5/lab9/WebContent/view.html)

    <h4> ---- Q1 Result ---- </h4>
    <%
	String serverIP = "localhost";
	String strSID = "orcl";	
	String portNum = "1521";
	String user = "test";
	String pass = "test";
	String url = "jdbc:oracle:thin:@"+serverIP+":"+portNum+":"+strSID;
	
	Connection conn = null;
	PreparedStatement pstmt;
	ResultSet rs;
	Class.forName("oracle.jdbc.driver.OracleDriver");
	conn = DriverManager.getConnection(url,user,pass);
	String query = "SELECT Fname, Minit, Lname"
					+ " FROM Project, Works_on, Employee"
					+ " WHERE Dno = " + request.getParameter("dNum")
					+ " AND Salary >= " + request.getParameter("salary")
					+ " AND Pname = '" + request.getParameter("pName") + "'"
					+ " AND Pno = Pnumber AND Essn = ssn order by Lname ASC";
	System.out.println(query);
	pstmt = conn.prepareStatement(query);
	rs = pstmt.executeQuery();

        out.println("<table border =\"1\">");
        ResultSetMetaData rsmd = rs.getMetaData();
        int cnt = rsmd.getColumnCount();
        for (int i=1; i <= cnt; i++){
        	out.println("<th>"+rsmd.getColumnName(i)+"</th>");
        }
        while(rs.next()){
            out.println("<tr>");
    	    out.println("<td>"+rs.getString(1)+"</td>");
    	    out.println("<td>"+rs.getString(2)+"</td>");
    	    out.println("<td>"+rs.getString(3)+"</td>");
       	    out.println("</tr>");
        }
        out.println("</table>");
	//db와 연결해서 Post를 통해 넘겨받은 데이터를 토대로 db에 쿼리를 날리고 그결과를 getString을 통해 화면에 출력
[response.jsp](https://github.com/kdh7575070/taeha-kang/blob/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/3%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%20%EC%8B%A4%EC%8A%B5/lab9/WebContent/response.jsp)

