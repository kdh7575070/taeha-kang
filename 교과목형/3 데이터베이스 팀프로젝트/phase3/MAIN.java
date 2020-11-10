package phase3;

 

import java.sql.*;

import java.util.Properties;

 

public class MAIN {

	

	public static final String URL = "jdbc:postgresql://localhost/knumovie?user=postgres&password=comp322";

	public static void main(String[] args) {

		// TODO Auto-generated method stub

 

		Connection conn = null;

//		Statement stmt = null;

		String sql = "";

		try {

			Class.forName("org.postgresql.Driver");

			System.out.println("Success!");

		} catch (ClassNotFoundException e) {

			System.err.println("error " + e.getMessage());

			System.exit(1);

		}

		

		try {

			conn = DriverManager.getConnection(URL);

			System.out.println("Success!");

			conn.setAutoCommit(false);

		}catch(SQLException ex) {

			ex.printStackTrace();

			System.err.println("Cannot get a connection: " + ex.getMessage());

			System.exit(1);

		}

		

		/* 1 */

		account.create_account(conn,"jjaaaa@newsvine.com", "dddad", "Toe", "Towe", "01033358473", "2001-11-11", "male", "\\0", "Account Representative IV", "Prime", false);

		

		

	}

}



