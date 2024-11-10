#ifndef TX_ADD_NEIGHBOR_H
#define TX_ADD_NEIGHBOR_H
#include <iostream>
#include <vector>
#include <string>
#include "passNeighbor.h"
#include "finderNeighbor.h"
#include "passPartOf.h"
#include "finderCommunity.h"
#include "passCommunity.h"
#include "finderPartOf.h"

class txAddNeighbor{
private:
    std::string _username;
    std::string _communityName;
public:
    txAddNeighbor();
    txAddNeighbor(std::string username, std::string communityName);
    ~txAddNeighbor();

    void execute();
};




#endif