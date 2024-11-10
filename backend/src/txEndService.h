#ifndef TX_END_SERVICE_H
#define TX_END_SERVICE_H
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "finderService.h"
#include "passAcceptService.h"
#include "passNeighbor.h"
#include "finderNeighbor.h"


class txEndService{
    private:
        int _code;
        std::string _dniNeighborCharge;
        std::string _usernameNeighborPay;
    public:
        txEndService();
        txEndService(int code, std::string dniNeighborCharge, std::string usernameNeighborPay);
        ~txEndService();
        void execute();


};


#endif