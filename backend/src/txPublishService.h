#ifndef TX_PUBLISH_SERVICE_H
#define TX_PUBLISH_SERVICE_H
#include <iostream>
#include <vector>
#include "passService.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <sstream>
#include <iomanip>
#include "connection.h"
using namespace std;

class txPublishService
{
    private:
        unsigned int _code;
        std::string _username;
        std::string _label;
        std::string _description;
        unsigned int _price;
        std::string _duration;
        std::string _status;
        unsigned int _id_community;

    
    public:
        txPublishService();
        txPublishService(unsigned int id_community, string username, string label, string description, unsigned int price, string duration, string status);
        ~txPublishService();
        void publishService();
        void execute();
};

#endif
