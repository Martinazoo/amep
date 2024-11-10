#include "connection.h"


void connection::setAtributes()
{
    _server_ip = "ubiwan.epsevg.upc.edu";
    _user = "amep11";
    _password = "zoxoX3feoYae-";
}
/* This is used when something is returned */
sql::ResultSet* connection::connect(const std::string &sqlSentence)
{
    connection& conn = connection::getInstance();
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    //Parameters of the connection
    conn.setAtributes();
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(_server_ip, _user, _password);
    // Initialize stmt before using it
    stmt = con->createStatement();
    try {
        res = stmt->executeQuery(sqlSentence);  // Changed to execute
    } catch (sql::SQLException &e) {
        std::cout << "Error executing query: " << e.what() << std::endl;
    }
    
    // Remember to clean up resources
    delete stmt;        
    delete con;
    return res;
}

/* This is used when nothing is returned */
void connection::executeUpdate(const std::string& query) 
{
        
    connection& conn = connection::getInstance();
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    //Parameters of the connection
    conn.setAtributes();
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(_server_ip, _user, _password);
    // Initialize stmt before using it
    stmt = con->createStatement();
    
    stmt->executeUpdate(query); // Changed to execute
    
    delete stmt;        
    delete con;
}
