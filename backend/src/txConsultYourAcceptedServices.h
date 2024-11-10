#ifndef TX_CONSULT_YOUR_ACCEPTED_SERVICES_H
#define TX_CONSULT_YOUR_ACCEPTED_SERVICES_H
#include <iostream>
#include <vector>
#include "passService.h"
#include "finderUserAcceptedServices.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "nlohmann/json.hpp"
using namespace std;

class txConsultYourAcceptedServices{
    private: 
        string _user;
        int _idCommunity;
        vector<passService> res;
    public:
        txConsultYourAcceptedServices();
        txConsultYourAcceptedServices(string user, int idCommunity);
        ~txConsultYourAcceptedServices();
        string getResult();
        void execute();
};

#endif