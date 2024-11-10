#include "txLogNeighbor.h"

//constructores i destructora
txLogNeighbor::txLogNeighbor()
{

}

txLogNeighbor::~txLogNeighbor()
{

}

txLogNeighbor::txLogNeighbor(string uN, string pN): _usernameN(uN), _passwordN(pN)
{

}


void txLogNeighbor::execute()
{
    passNeighbor n(_usernameN,_passwordN);
    n.log();
}