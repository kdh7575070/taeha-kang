package lab6; // package name 

// 2015112806 강태하

import java.sql.*; // import JDBC package
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Lab6JDBC{
	
	public static final String URL = "jdbc:oracle:thin:@localhost:1521:orcl";
	public static final String USER_UNIVERSITY ="university"; //계정로그인
	public static final String USER_PASSWD ="comp322";
			
	public static void main(String[] args) {
		
		Connection conn = null; // Connection object
		Statement stmt = null;	// Statement object
		String sql = ""; // an SQL statement
		
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
		
		try{
			conn.setAutoCommit(false);

			stmt = conn.createStatement();
		
			int res = stmt.executeUpdate("DROP TABLE DEPARTMENT CASCADE CONSTRAINT");
			if(res == 0)
				System.out.println("Table DEPARTMENT was successfully dropped.");

			res = stmt.executeUpdate("DROP TABLE EMPLOYEE CASCADE CONSTRAINT");
			if(res == 0)
				System.out.println("Table EMPLOYEE was successfully dropped.");

			res = stmt.executeUpdate("DROP TABLE PROJECT CASCADE CONSTRAINT");
			if(res == 0)
				System.out.println("Table PROJECT was successfully dropped.");

			res = stmt.executeUpdate("DROP TABLE WORKS_ON CASCADE CONSTRAINT");
			if(res == 0)
				System.out.println("Table WORKS_ON was successfully dropped.");

			res = stmt.executeUpdate("DROP TABLE DEPT_LOCATIONS CASCADE CONSTRAINT");
			if(res == 0)
				System.out.println("Table DEPT_LOCATIONS was successfully dropped.");
			
			res = stmt.executeUpdate("DROP TABLE DEPENDENT CASCADE CONSTRAINT");
			if(res == 0)
				System.out.println("Table DEPENDENT was successfully dropped.");

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

			sb = new StringBuffer();
			sb.append("CREATE TABLE EMPLOYEE(Fname VARCHAR(15) NOT NULL,");
			sb.append("		  Minit CHAR,");
			sb.append("		  Lname VARCHAR(15),");
			sb.append("		  Ssn CHAR(9) NOT NULL,");
			sb.append("		  Bdate DATE,");
			sb.append("		  Address VARCHAR(30),");
			sb.append("		  Sex CHAR,");
			sb.append("		  Salary NUMBER(10,2),");
			sb.append("		  Super_ssn CHAR(9),");
			sb.append("		  Dno NUMBER DEFAULT 1 NOT NULL,");
			sb.append("		  PRIMARY KEY(Ssn))");
			sql = sb.toString();
			res = stmt.executeUpdate(sql);
			if(res ==0)
				System.out.println("Table EMPLOYEE was successfully created.");
			
			sb = new StringBuffer();
			sb.append("CREATE TABLE PROJECT(Pname VARCHAR(15) NOT NULL,");
			sb.append("		  Pnumber NUMBER NOT NULL,");
			sb.append("		  Plocation VARCHAR(15),");
			sb.append("		  Dnum NUMBER NOT NULL,");
			sb.append("		  PRIMARY KEY(Pnumber),");
			sb.append("		  UNIQUE(Pname))");
			sql = sb.toString();
			res = stmt.executeUpdate(sql);
			if(res ==0)
				System.out.println("Table PROJECT was successfully created.");
			
			sb = new StringBuffer();
			sb.append("CREATE TABLE DEPT_LOCATIONS(Dnumber NUMBER NOT NULL,");
			sb.append("		  Dlocation VARCHAR(15) NOT NULL,");
			sb.append("		  PRIMARY KEY(Dnumber, Dlocation))");
			sql = sb.toString();
			res = stmt.executeUpdate(sql);
			if(res ==0)
				System.out.println("Table DEPT_LOCATIONS was successfully created.");
			
			sb = new StringBuffer();
			sb.append("CREATE TABLE WORKS_ON(Essn CHAR(9) NOT NULL,");
			sb.append("		  Pno NUMBER NOT NULL,");
			sb.append("		  Hours DECIMAL(3,1),");
			sb.append("		  PRIMARY KEY(Essn, Pno))");
			sql = sb.toString();
			res = stmt.executeUpdate(sql);
			if(res ==0)
				System.out.println("Table WORKS_ON was successfully created.");
			
			sb = new StringBuffer();
			sb.append("CREATE TABLE DEPENDENT(Essn CHAR(9) NOT NULL,");
			sb.append("		  Dependent_name VARCHAR(15) NOT NULL,");
			sb.append("		  Sex CHAR,");
			sb.append("		  Bdate DATE,");
			sb.append("		  Relationship VARCHAR(8),");
			sb.append("		  PRIMARY KEY(Essn, Dependent_name))");
			sql = sb.toString();
			res = stmt.executeUpdate(sql);
			if(res ==0)
				System.out.println("Table DEPENDENT was successfully created.");
			
			conn.commit();
			System.out.println("--------------------COMPLETE CREATE--------------------");
		}
		catch (SQLException ex2) {
			System.err.println("sql error1 = "+ex2.getMessage());
			System.exit(1);
		}
		
		try{
	        File file = new File("C:\\Users\\taeha\\Desktop\\company.txt"); //절대경로지정!
	        FileReader filereader = new FileReader(file); //입력스트림
	        BufferedReader bufReader = new BufferedReader(filereader); //입력버퍼
            String line = "";
            String table_name = "";
            
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
    	            	    case "EMPLOYEE": sql += "'"+array[0]+"', ";
	    	            	    sql += "'"+array[1]+"', ";
	    	            	    sql += "'"+array[2]+"', ";
	    	            	    sql += "'"+array[3]+"', ";
	    	            	    sql += "TO_DATE('"+array[4]+"', 'yyyy-mm-dd'), ";
	    	            	    sql += "'"+array[5]+"', ";
		            	    	sql += "'"+array[6]+"', ";
		            	    	sql += array[7]+", ";
		            	    	sql += "'"+array[8]+"', ";
		            	    	sql += array[9]+")";
		            	    	break;
    	            	    case "PROJECT": sql += "'"+array[0]+"', ";
		            	    	sql += array[1]+", ";
		            	    	sql += "'"+array[2]+"', ";
		            	    	sql += array[3]+")";
		            	        break;
    	            	    case "DEPT_LOCATIONS": sql += array[0]+", ";
		            	    	sql += "'"+array[1]+"')";
		            	    	break;
    	            	    case "WORKS_ON": sql += "'"+array[0]+"', ";
		            	    	sql += array[1]+", ";
		            	    	sql += array[2]+")";
		            	        break;
    	            	    case "DEPENDENT": sql += "'"+array[0]+"', ";
	    	            	    sql += "'"+array[1]+"', ";
	    	            	    sql += "'"+array[2]+"', ";
	    	            	    sql += "TO_DATE('"+array[3]+"', 'yyyy-mm-dd'), ";
	    	            	    sql += "'"+array[4]+"')";
	    	            	    break;
                		}
            			int res = stmt.executeUpdate(sql);
            			System.out.println(res + " row inserted.");
            			
            			conn.commit();
            			System.out.println("--------------------COMPLETE INSERT--------------------");
            		}
            		catch (SQLException ex2) {
            			System.err.println("sql error2 = "+ex2.getMessage());
            			System.exit(1);
            		}
            	}
            }
            //.readLine()은 끝에 개행문자를 읽지 않는다.    
            bufReader.close();
		}
		catch (FileNotFoundException e) {
	        // TODO: handle exception
	    }
		catch(IOException e){
	        System.out.println(e);
	    }
        try {
			sql = "(select MIN(Salary) from EMPLOYEE E, DEPENDENT where E.Sex = 'M' and  Relationship = 'Spouse' and Essn = Ssn) union (select MIN(Salary) from EMPLOYEE E, DEPENDENT where E.Sex = 'F' and Relationship = 'Spouse' and Essn = Ssn)";
			ResultSet rs = stmt.executeQuery(sql);
			while(rs.next()){
				int salary 	    = rs.getInt(1);
				System.out.println("Salary = " + salary);
			}
			sql = "select E.FName, E.LName, E.Salary from EMPLOYEE E where not exists ( (select P.Pnumber from project P where Dnum = 1 ) minus (select W.Pno from Works_on W where E.ssn = W.Essn) )";
			rs = stmt.executeQuery(sql);
			while(rs.next()){
				String efname 	    = rs.getString(1);
				String elname 	    = rs.getString(2);
				int salary 	    	= rs.getInt(3);
				System.out.println("E.FName = " + efname
									+ ", E.LName = " + elname
									+ ", Salary = " + salary);
			}
			sql = "select Pname, Plocation, Lname, Dname from ( (EMPLOYEE full outer join DEPARTMENT on Dno = Dnumber) full outer join PROJECT on Dnum = Dnumber) where Plocation = 'Bellaire' order by Dname DESC";
			rs = stmt.executeQuery(sql);
			while(rs.next()){
				String pname 	    = rs.getString(1);
				String plocation    = rs.getString(2);
				String lname 	    = rs.getString(3);
				String dname 	    = rs.getString(4);
				System.out.println("Pname = " + pname
									+ ", Plocation = " + plocation
									+ ", LName = " + lname
									+ ", Dname = " + dname);
			}
			rs.close();
			conn.commit();
			System.out.println("--------------------COMPLETE QUERY--------------------");
		}
		catch (SQLException ex2) {
			System.err.println("sql error3 = "+ex2.getMessage());
			System.exit(1);
		}
	}
}