#include "txAddTokens.h"

txAddTokens::txAddTokens() {}

txAddTokens::~txAddTokens() {}


// adds tokens to neighbor dni
void txAddTokens::execute(string dni, int tokens) 
{

    finderNeighbor fn; 
    vector<passNeighbor> vn= fn.findNeighbor(dni); 
    passNeighbor n= vn[0];
    unsigned int t= n.getTokens(); 
    t += tokens; 
    n.setTokens(t);
    
    n.modify2();  

}
