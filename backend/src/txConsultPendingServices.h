#ifndef TX_CONSULT_PENDING_SERVICES_H
#define TX_CONSULT_PENDING_SERVICES_H

#include <iostream>
#include <vector>
#include <string>
#include "finderService.h"
#include "finderCommunity.h"
#include "passCommunity.h"
#include "nlohmann/json.hpp"
using namespace std;

class txConsultPendingServices{
    private:
        string _communityName;
        vector<passService> res;
    public:
        txConsultPendingServices();
        txConsultPendingServices(string communityName);
        ~txConsultPendingServices();

        void execute();
        string getResult();
};


#endif