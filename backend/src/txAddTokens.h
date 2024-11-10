#ifndef TX_ADD_TOKENS_H
#define TX_ADD_TOKENS_H
#include <iostream>
#include "passNeighbor.h"
#include "finderNeighbor.h"

using namespace std;

class txAddTokens
{
    public:
        txAddTokens();
        ~txAddTokens();
        void execute(string dni, int tokens);
};

#endif
