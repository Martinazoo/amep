#ifndef TX_FILTER_SERVICES_H
#define TX_FILTER_SERVICES_H
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "finderService.h"
#include "passService.h"
#include "passNeighbor.h"
#include "finderNeighbor.h"
#include <vector>
#include <nlohmann/json.hpp>

class txFilterServices{
    private:
        string _description;
        string _label;
        int _minVal;
        int _maxVal;
        int _community;
        string _username;
        vector<passService> _resu;
    public:
        txFilterServices();
        txFilterServices(string description, string label, int minVal, int maxVal, int community, string username);
        ~txFilterServices();
        void execute();
        string getResult();
};


#endif