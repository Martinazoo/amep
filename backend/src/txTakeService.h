#ifndef TX_TAKE_SERVICE_H
#define TX_TAKE_SERVICE_H
#include <iostream>
#include <vector>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <sstream>
#include <iomanip>
#include "passAcceptService.h"
#include "finderAccepted.h"
#include "finderNeighbor.h"
#include "finderService.h"

class txTakeService{
    private:
        int _code;
        std::string _username;   
    public:
        txTakeService();
        txTakeService(int code, std::string username);
        ~txTakeService();

        void execute();

};

#endif