#ifndef TX_CONSULT_YOUR_PENDING_SERVICES_H
#define TX_CONSULT_YOUR_PENDING_SERVICES_H
#include <iostream>
#include <vector>
#include "passService.h"
#include "finderUserPendingServices.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "nlohmann/json.hpp"
using namespace std;

class txConsultYourPendingServices {
    private:
        string _user;
        int _idCommunity;
        vector<passService> _res;
    public:
        txConsultYourPendingServices();
        txConsultYourPendingServices(string user, int idCommunity);
        ~txConsultYourPendingServices();
        string getResult();
        void execute();
};

#endif