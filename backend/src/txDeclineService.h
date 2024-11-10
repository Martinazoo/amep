#ifndef TX_DECLINE_SERVICE_H
#define TX_DECLINE_SERVICE_H
#include <iostream>
#include <vector>
#include "txConsultPendingServices.h"
#include "passService.h"
#include "finderPendingService.h"

using namespace std;

class txDeclineService {

    private: 
        string _idCommunity;
        string _code;

    public:

        txDeclineService();
        ~txDeclineService();
        txDeclineService(string code, string idCommunity);

        void execute();
};

#endif
