#ifndef PASS_ACCEPT_SERVICE_H
#define PASS_ACCEPT_SERVICE_H

#include <iostream>
#include <string>
#include <vector>
#include "connection.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
class passAcceptService{
    private:
        int _codeService;
        std::string _dniNeighbor;
    public:
        passAcceptService();
        passAcceptService(int codeService, std::string dniNeighbor);
        //passAcceptService(int codeService);
        ~passAcceptService();
        void takeService();
        void endService();
        int getCodeService();
        std::string getDniNeighbor();
};




#endif