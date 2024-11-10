#include "txConsultNeighbor.h"

    txConsultNeighbor::txConsultNeighbor(){

    }
    txConsultNeighbor::txConsultNeighbor(std::string neighborUsername):_neighborUsername(neighborUsername){

    }
    txConsultNeighbor::~txConsultNeighbor(){

    }
    void txConsultNeighbor::execute(){
        finderNeighbor fN;
        vector<passNeighbor> sol = fN.findNeighborByUsername(_neighborUsername);
        res = sol;
    }
    vector<passNeighbor> txConsultNeighbor::getResult(){
        return res;
    }
        