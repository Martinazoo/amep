#ifndef TX_CONSULT_SERVICE_H
#define TX_CONSULT_SERVICE_H
#include <iostream>
#include <vector>
#include "finderService.h"
#include "passService.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

class txConsultService{
    private:
        unsigned int _code;
        vector<passService> res;
    public:
        txConsultService();
        ~txConsultService();
        txConsultService(unsigned int code);
    
        void execute();
        vector<passService> getResult();
};

#endif