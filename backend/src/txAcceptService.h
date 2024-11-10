#ifndef TX_ACCEPT_SERVICE_H
#define TX_ACCEPT_SERVICE_H
#include <iostream>
#include <vector>
#include "txConsultPendingServices.h"
#include "passService.h"
#include "finderPendingService.h"

using namespace std;

class txAcceptService {

    private:
        string _idCommunity;
        string _code;
    
    public:
        txAcceptService();
        ~txAcceptService();
        txAcceptService(string code, string idCommunity);

        void execute();
};

#endif