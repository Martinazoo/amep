#ifndef TX_VALIDATE_NEIGBOR_H
#define TX_VALIDATE_NEIGBOR_H

#include "passNeighbor.h"
#include "mysql_driver.h"
#include "mysql_error.h"
#include "mysql_connection.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <string>
#include "nlohmann/json.hpp"
#include <iostream>
#include "finderNeighbor.h"
#include "passNeighbor.h"
#include <string>
#include <vector>

class txValidateNeighbor
{
private:
    passNeighbor _neighbor;
    std::string _usr;
    std::string _pass;
    bool _valid = false;
    string _error;

public:
    txValidateNeighbor(string usr, string pass);
    ~txValidateNeighbor();
    void execute();
    nlohmann::json getResult();

};



#endif