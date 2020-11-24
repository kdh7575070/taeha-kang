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
    <h2>Lab #9</h2>
    <h3>:: Oracle - Tomact Conjunction ::</h3>
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
	String query = "SELECT Dnumber, Dname, Mgr_Ssn, Mgr_start_date "
					+ "FROM DEPARTMENT ORDER BY Dnumber";
	System.out.println(query);
	pstmt = conn.prepareStatement(query);
	rs = pstmt.executeQuery();	
%>
    <h4> ---- A List of DEPARTMENT tuples ---- </h4>
<%
    out.println("<table border =\"1\">");
    ResultSetMetaData rsmd = rs.getMetaData();
    int cnt = rsmd.getColumnCount();
    for (int i=1; i <= cnt; i++){
    	out.println("<th>"+rsmd.getColumnName(i)+"</th>");
    }
    while(rs.next()){
    	out.println("<tr>");
    	out.println("<td>"+rs.getInt(1)+"</td>");
    	out.println("<td>"+rs.getString(2)+"</td>");
    	out.println("<td>"+rs.getString(3)+"</td>");
    	
    	SimpleDateFormat sdfDate = new SimpleDateFormat("yyyy-MM-dd");
    	Date mgrStartDate = rs.getDate(4);
    	String strMSDate = sdfDate.format(mgrStartDate);
    	out.println("<td>"+strMSDate+"</td>");
    	out.println("</tr>");
    }
    out.println("</table>");
    rs.close();
    pstmt.close();
    conn.close();
%>
</body>
</html>