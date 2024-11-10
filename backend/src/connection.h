#ifndef CONNECTION_H
#define CONNECTION_H
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <algorithm>

class connection{
    private:
        std::string _server_ip;
        std::string _user;
        std::string _password;
        
        connection() {
            _server_ip = "";
            _user = "";
            _password = "";
        }
    public:
        static connection& getInstance(){
            static connection instance;
            return instance;
        }
        void setAtributes();
        sql::ResultSet* connect(const std::string &sqlSentence);
        void executeUpdate(const std::string& query);

};

#endif