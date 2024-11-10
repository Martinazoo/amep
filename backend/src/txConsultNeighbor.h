#ifndef TX_CONSULT_NEIGHBOR_H
#define TX_CONSULT_NEIGHBOR_H
#include <iostream>
#include <vector>
#include <string>
#include "passNeighbor.h"
#include "finderNeighbor.h"

class txConsultNeighbor{
    private: 
        std::string _neighborUsername;
        vector<passNeighbor> res;
    public:
        txConsultNeighbor();
        txConsultNeighbor(std::string neighborUsername);
        ~txConsultNeighbor();

        void execute();
        vector<passNeighbor> getResult();

};

#endif