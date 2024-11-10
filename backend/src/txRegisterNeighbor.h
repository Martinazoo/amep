#ifndef TX_REGISTER_NEIGHBOR_H
#define TX_REGISTER_NEIGHBOR_H
#include <iostream>
#include <vector>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "passNeighbor.h"
#include "finderNeighbor.h"
#include <nlohmann/json.hpp>
#include <regex>

using namespace std;

class txRegisterNeighbor{
    private:
        string _dniN;
        string _mailN;
        string _nameN; 
        string _usernameN; 
        string _passwordN; 
        unsigned int _tokensN;
        std::string _error;
        
    public:
        txRegisterNeighbor();
        ~txRegisterNeighbor();
        txRegisterNeighbor(string dN, string mN, string nN, string uN, string pN, unsigned int tN);

        void execute();
        std::string getResult();
};

#endif