<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!-- import JDBC package -->    
<%@ page language="java" import= "java.text.*, java.sql.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta charset="EUC-KR">
    <title>COMP322 : Databases</title>
</head>
<body>
    <h2>Lab #9: Repeating Lab #5-3 via JSP</h2>
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
%>
	<h4> ---- Q2 Result ---- </h4>
<%
	query = "SELECT Dname, Ssn, Lname"
			+ " FROM Employee, Department"
			+ " WHERE Address like " + "'%" + request.getParameter("address") + "%'"
			+ " AND Super_ssn = '" + request.getParameter("sssn") + "'"
			+ " AND Dnumber = Dno";

	System.out.println(query);
	pstmt = conn.prepareStatement(query);
	rs = pstmt.executeQuery();
	
    out.println("<table border =\"1\">");
    rsmd = rs.getMetaData();
    cnt = rsmd.getColumnCount();
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
%>
	<h4> ---- Q3 Result ---- </h4>
<%
	query = "SELECT Lname, Hours"
			+ " FROM Employee, Works_on, Project"
			+ " WHERE Pname = '" + request.getParameter("pName2") + "'"
			+ " AND Pno = Pnumber and Ssn = Essn order by Hours DESC";

	System.out.println(query);
	pstmt = conn.prepareStatement(query);
	rs = pstmt.executeQuery();
	
    out.println("<table border =\"1\">");
    rsmd = rs.getMetaData();
    cnt = rsmd.getColumnCount();
    for (int i=1; i <= cnt; i++){
    	out.println("<th>"+rsmd.getColumnName(i)+"</th>");
    }
    while(rs.next()){
    	out.println("<tr>");
    	out.println("<td>"+rs.getString(1)+"</td>");
    	out.println("<td>"+rs.getFloat(2)+"</td>");
    	out.println("</tr>");
    }
    out.println("</table>");
%>
<h4> ---- Q4 Result ---- </h4>
<%
	query = "SELECT Lname, Fname, Hours"
			+ " FROM Employee, Works_on, Project"
			+ " WHERE Pname = '" + request.getParameter("pName3") + "'"					
			+ " AND Hours >= " + request.getParameter("workinghours")
			+ " AND Pno = Pnumber and Ssn = Essn order by Hours ASC";

	System.out.println(query);
	pstmt = conn.prepareStatement(query);
	rs = pstmt.executeQuery();
	
    out.println("<table border =\"1\">");
    rsmd = rs.getMetaData();
    cnt = rsmd.getColumnCount();
    for (int i=1; i <= cnt; i++){
    	out.println("<th>"+rsmd.getColumnName(i)+"</th>");
    }
    while(rs.next()){
    	out.println("<tr>");
    	out.println("<td>"+rs.getString(1)+"</td>");
    	out.println("<td>"+rs.getString(2)+"</td>");
    	out.println("<td>"+rs.getFloat(3)+"</td>");
    	out.println("</tr>");
    }
    out.println("</table>");
%>
<h4> ---- Q5 Result ---- </h4>
<%
	query = "SELECT Fname, Relationship"
			+ " FROM Dependent, Employee"
			+ " WHERE Super_ssn = '" + request.getParameter("sssn2") + "'"
			+ " AND Essn = Ssn";

	System.out.println(query);
	pstmt = conn.prepareStatement(query);
	rs = pstmt.executeQuery();
	
    out.println("<table border =\"1\">");
    rsmd = rs.getMetaData();
    cnt = rsmd.getColumnCount();
    for (int i=1; i <= cnt; i++){
    	out.println("<th>"+rsmd.getColumnName(i)+"</th>");
    }
    while(rs.next()){
    	out.println("<tr>");
    	out.println("<td>"+rs.getString(1)+"</td>");
    	out.println("<td>"+rs.getString(2)+"</td>");
    	out.println("</tr>");
    }
    out.println("</table>");
%>
<%
    rs.close();
    pstmt.close();
    conn.close();
%>
</body>
</html>