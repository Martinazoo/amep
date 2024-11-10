#ifndef TX_CONSULT_COMMUNITIES_H
#define TX_CONSULT_COMMUNITIES_H
#include <iostream>
#include <vector>
#include <string>
#include "passPartOf.h"
#include "finderPartOf.h"
#include "passNeighbor.h"
#include "finderNeighbor.h"
#include "passCommunity.h"
#include "finderCommunity.h"
#include "nlohmann/json.hpp"

class txConsultCommunities{
    private:
        std::string _username;
        vector<passCommunity> res;
    public:
        txConsultCommunities();
        txConsultCommunities(std::string username);
        ~txConsultCommunities();

        void execute();
        string getResult();


};
#endif