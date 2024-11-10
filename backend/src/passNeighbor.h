#ifndef PASS_NEIGHBOR_H
#define PASS_NEIGHBOR_H
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "connection.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

class passNeighbor{
    private:
    
        string _dni; 
        string _mail; 
        string _name; 
        string _username; 
        string _password; 
        unsigned int _tokens; 

    public:

        passNeighbor();
        passNeighbor(string dni);
        passNeighbor(string dni, unsigned int tokens);
        passNeighbor(string dni, string mail, string name, string username, string password, unsigned int tokens);
        passNeighbor(string username, string password);
        ~passNeighbor();

        void insert(); 
        void modify(); 
        void modify2();
        void erase(); 
        void log();
        bool boolLog();
        void pay();
        void charge();

        static bool existsDni(const string& dni);
        static bool existsMail(const string& mail);
        static bool existsUsername(const string& username);

        void setDni(string dni); 
        void setMail(string mail);
        void setName(string name);
        void setUsername(string username);
        void setPassword(string password);
        void setTokens(unsigned int tokens);     

        string getDni();
        string getMail();
        string getName();
        string getUsername();
        string getPassword();
        unsigned int getTokens();
};

#endif