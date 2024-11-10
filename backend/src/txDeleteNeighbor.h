#ifndef TX_DELETE_NEIGHBOR_H
#define TX_DELETE_NEIGHBOR_H
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "connection.h"
#include "passNeighbor.h"
using namespace std;

class txDeleteNeighbor{
    private:
        string _dni;
        
    public:
        txDeleteNeighbor();
        txDeleteNeighbor(string dni);
        ~txDeleteNeighbor();
        void execute();

};



#endif