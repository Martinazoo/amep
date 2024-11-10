#ifndef TX_MODIFY_NEIGBOR_H
#define TX_MODIFY_NEIGBOR_H
#include <iostream>
#include <vector>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <nlohmann/json.hpp>
#include "passNeighbor.h"
#include "finderNeighbor.h"
#include <regex>

using namespace std;

class txModifyNeighbor{
    private:
        string _user;
        string _name;
        string _password;
        string _error;

    public:
        txModifyNeighbor();
        ~txModifyNeighbor();
        txModifyNeighbor(string username, string name, string password);
        void execute();
        std::string getResult();
};


#endif