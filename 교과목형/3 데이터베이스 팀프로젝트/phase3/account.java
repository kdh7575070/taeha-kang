package phase3;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.sql.*;
import java.util.Properties;

public class account {
	
	public static void create_account(Connection conn, String User_id, String Password, String First_name, String Last_name, String Phone_number, String Birthday, String Sex, String Address, String Job, String Membership_status, boolean Is_admin ) {
		Statement stmt = null;  //Statement object
		try {
			stmt = conn.createStatement();
	        
	        // CREATE TABLE 
	        String sql = "";
	        StringBuffer sb = new StringBuffer();
            sb.append("insert into ACCOUNT (User_id, Password, First_name, Last_name, Phone_number, Birthday, Sex, Address, Job, Membership_status, Is_admin)");
            sb.append("values (");
	        sb.append("'" + User_id + "',");   
	        sb.append("'" + Password + "',");   
	        sb.append("'" + First_name + "',");   
	        sb.append("'" + Last_name + "',");   
	        sb.append("'" + Phone_number + "',");   
	        sb.append("'" + Birthday + "',");   
	        sb.append("'" + Sex + "',");
	        sb.append("'" + Address + "',");   
	        sb.append("'" + Job + "',");   
	        sb.append("'" + Membership_status + "',");   
	        sb.append(Is_admin);
	        sb.append(");");

            sql = sb.toString();
            System.out.println(sql);
 	        int res = stmt.executeUpdate(sql);
	        if(res == 0)
	            System.out.println("New account was successfully created.");
	         
	        sb.setLength(0);
	        
			conn.commit();
		}catch (SQLException ex2) {
			System.err.println("sql error = " + ex2.getMessage());
			System.exit(1);
		}
	}		
	public static void user_info(Connection conn, String User_id, String Password, String First_name, String Last_name, String Phone_number, String Birthday, String Sex, String Address, String Job, String Membership_status, boolean Is_admin ) {
		Statement stmt = null;  //Statement object
		try {
			stmt = conn.createStatement();
	        
	        // CREATE TABLE 
	        String sql = "";
	        StringBuffer sb = new StringBuffer();
            sb.append("insert into ACCOUNT (User_id, Password, First_name, Last_name, Phone_number, Birthday, Sex, Address, Job, Membership_status, Is_admin)");
            sb.append("values (");
	        sb.append("'" + User_id + "',");   
	        sb.append("'" + Password + "',");   
	        sb.append("'" + First_name + "',");   
	        sb.append("'" + Last_name + "',");   
	        sb.append("'" + Phone_number + "',");   
	        sb.append("'" + Birthday + "',");   
	        sb.append("'" + Sex + "',");
	        sb.append("'" + Address + "',");   
	        sb.append("'" + Job + "',");   
	        sb.append("'" + Membership_status + "',");   
	        sb.append(Is_admin);
	        sb.append(");");

            sql = sb.toString();
            System.out.println(sql);
 	        int res = stmt.executeUpdate(sql);
	        if(res == 0)
	            System.out.println("New account was successfully created.");
	         
	        sb.setLength(0);
	        
			conn.commit();
		}catch (SQLException ex2) {
			System.err.println("sql error = " + ex2.getMessage());
			System.exit(1);
		}
	}		
}