#include "txConsultNeighbors.h"

txConsultNeighbors::txConsultNeighbors()
{

}

txConsultNeighbors::txConsultNeighbors(string nameCom): _nC(nameCom)
{
    
}

txConsultNeighbors::~txConsultNeighbors()
{

}

void txConsultNeighbors::execute()
{
    finderPartOf fpo;
    finderNeighbor fn;
    vector<passPartOf> nei = fpo.findAllMembersOfCommunity(_nC);
    vector<passNeighbor> neigh;
    for (unsigned int i = 0; i < nei.size(); i++)
    {
        vector<passNeighbor> temp = fn.findNeighbor(nei[i].getDni());
        neigh.push_back(temp[0]);
    }
    res = neigh;
}

vector<passNeighbor> txConsultNeighbors::getResult()
{
    return res;
}