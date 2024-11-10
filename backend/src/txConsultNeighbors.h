#ifndef TX_CONSULT_NEIGHBORS_H
#define TX_CONSULT_NEIGHBORS_H
#include <iostream>
#include <vector>
#include <string>
#include "passPartOf.h"
#include "finderPartOf.h"
#include "passNeighbor.h"
#include "finderNeighbor.h"
class txConsultNeighbors{
    private: 
       string _nC;
       vector<passPartOf> partOf;
       vector<passNeighbor> res;
    public:
       
    txConsultNeighbors();
    txConsultNeighbors(string nameCom);
    ~txConsultNeighbors();

    void execute();
    vector<passNeighbor> getResult();
};

#endif