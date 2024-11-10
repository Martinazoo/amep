#ifndef TX_CONSULT_TASKS_H
#define TX_CONSULT_TASKS_H

#include <iostream>
#include <vector>
#include "passService.h"
#include "finderTask.h"
#include "nlohmann/json.hpp"

using namespace std;

class txConsultTasks {
    private:
        string _dni;
        int _communityCode;
        vector<passService> _resu;

    public:
        txConsultTasks(string dni, int communityCode);
        ~txConsultTasks();
        string getResult();
        void execute();
};

#endif