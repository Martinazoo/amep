#ifndef TX_MODIFY_SERVICE_H
#define TX_MODIFY_SERVICE_H
#include <iostream>
#include <vector>
#include "finderService.h"
#include "passService.h"
#include "passAcceptService.h"
#include "finderAccepted.h"
using namespace std;

class txModifyService {
    
    private: 
        string _lUser;
        string _code;
    
    public:
        txModifyService();
        ~txModifyService();
        txModifyService(string code, string loggedUser);

        void execute();
        void modify(string label, string description, int price,string duration);
};

#endif