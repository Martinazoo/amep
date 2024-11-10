#include "txDeclineService.h"

txDeclineService::txDeclineService()
{

}

txDeclineService::txDeclineService(string code, string idCommunity): _code(code), _idCommunity(idCommunity)
{

}

txDeclineService::~txDeclineService()
{

}

void txDeclineService::execute()
{
    finderPendingService PS;
    vector<passService> Vps = PS.find(_code, _idCommunity);
    if(not Vps.empty())
        PS.decline(_code, _idCommunity);
    else return;
}