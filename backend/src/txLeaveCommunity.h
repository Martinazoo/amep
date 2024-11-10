#ifndef TXLEAVECOMMUNITY_H
#define TXLEAVECOMMUNITY_H

#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "connection.h"
#include "passPartOf.h"
#include "finderPartOf.h"
#include "finderCommunity.h"
#include "passNeighbor.h"
#include "finderNeighbor.h"
using namespace std;

class txLeaveCommunity{
    private:
        string _dniUser;
        string _communityName;
    public:
        txLeaveCommunity();
        txLeaveCommunity(string dniUser, string communityName);
        void execute();
        
};

#endif 

