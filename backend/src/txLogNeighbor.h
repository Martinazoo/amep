#ifndef TX_LOG_NEIGHBOR_H
#define TX_LOG_NEIGHBOR_H
#include <iostream>
#include <vector>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "passNeighbor.h"
using namespace std;

class txLogNeighbor{
    private:
        string _usernameN; 
        string _passwordN; 
        
    public:
        txLogNeighbor();
        ~txLogNeighbor();
        txLogNeighbor(string uN, string pN);

        void execute();
        
};

#endif