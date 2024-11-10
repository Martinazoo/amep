#ifndef TX_CONSULT_SERVICES_H
#define TX_CONSULT_SERVICES_H
#include <iostream>
#include <vector>
#include "passService.h"
#include "passCommunity.h"
#include "passAcceptService.h"
#include "finderService.h"
#include "finderAccepted.h"
#include "finderCommunity.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "nlohmann/json.hpp"
using namespace std;

class txConsultServices{
    private:
        string _self; 
        string _communityName;
        vector<passService> res;
    public:
        txConsultServices();
        txConsultServices(string communityName, string self);
        ~txConsultServices();
        string getResult();
        void execute();
};

#endif