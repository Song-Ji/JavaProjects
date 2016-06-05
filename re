Relational Database
A database is a collection of data with links between 
its entries to make the information accessible from a variety of perspectives.

DBMS: Application software does not directly manipulate the database but instead passes requests to the database management system.
DBMS is software that actully manages and stores data in a particular database
DBMS can control access to the database and ensure the integrity and security of the information.

There are two most popular models used by database management systems to represent data to the application software

relation database model : where data are stored in rectangular tables of mathematical relations with links to show 
the relationships between the tables

object-oriented database model : where objects are stored with links to show the relationships between the objects.

Each row of the table is called a record or tuple, each column is called an attribute because it describe one characteristic of the record.

The first step in designing a relational database is to determine what tables will be required and suitable attributes for each table

DBMS has the responsibility to ensure that the primary key obeys the following constraints:
entity integrity constraint  :  the primary key cannot have null valuse and no two records in the table can have the same valuse
for the primary key(so the student id cannot be null and no two students are allowed the same student id)

referential integrity constraint : a value in a foreign key can only appear if that value already appears in the primary key for
some record(so the enrollment table cannot refer to a student id that does not exist in the student table).

JDBC(java database connectivity) does not communicate directly with a DBMS but instead communicates with a piece of driver software

Configure the JDBC driver
1.Load appropriate driver
The driver(or several drivers) for the database is loaded using the forName method of the Class class.
For instance , to access a MYSQL database via the MYSQL driver :

String driver = "com.mysql.jdbc.Driver";
Class.forName(driver);

2.Connect to database : The DriverManager class(from the package java.sql) is used to establish a connection to a specified database URL
of the form  /* jdbc : subprotocol : subname */ . Here is an example, to connect to the AUT database server "raptor" on 
the port3306 which is allocated to its MySQL DBMS :

String url = "jdbc:mysql://raptor:3306/";
String userName = ;
String password = ;
Connection con = DriverManager.getConnection( url, userName ,password) ;

3.Create a JDBC statement : to execute SQL stataments, first a Statement object must be created for the database connection
The same Statement object can be reused for sending further commands to the database:

Statement stmt = con.createStatement();
If the same SQL statement is to be executed many times, it might be more efficient to use a "PreparedStatement" which gets 
precompiled by DBMS.

4.Execute SQL statements: 
String command = "SELECT ....";
ResultSet rs = stmt.executeQuery(command);

5.Process the result
Some SQL statements , such as SELECT queries return a ResultSet object holding a table of data

while(rs.next())
{
  ..=rs.getXss(...);
}

6.Release resources 
stmt.close();
con.close();




