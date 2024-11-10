#ifndef TX_DELETE_COMMUNITY_H
#define TX_DELETE_COMMUNITY_H
#include <iostream>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "passCommunity.h"
#include "finderCommunity.h"
using namespace std;

class txDeleteCommunity{
    private:
        int _id;
        
    public:
        txDeleteCommunity();
        ~txDeleteCommunity();
        txDeleteCommunity(int id);

        void execute();
};

#endif