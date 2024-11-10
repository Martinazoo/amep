// ----- BACKEND ----- //
//acceed db to look for pending services, you as admin user, have the ability to accept or decline the service, if the service is accepted then it's service
//is deleted from pending service and moved to services. By the other hand, if that service selected is declined, the service will be removed from de db

// ----- FRONTEND ----- //
//as admin user using the app, you'll be seeing a list of all the pending services are in the community with name (name) whom u are admin. Every single service
//will have to be selected. When you'll select a service you'll be redirected to another window in which you will only see the service you've selected and if u
//want to accept it or decline it. In every two options you'll be redirected again to the pending services

#include "txAcceptService.h"

txAcceptService::txAcceptService()
{

}
txAcceptService::~txAcceptService(){}
txAcceptService::txAcceptService(string code, string idCommunity): _code(code), _idCommunity(idCommunity){}

void txAcceptService::execute()
{
    //Cercadora admin, retorna passarela d'admin
    //getNom
    //txShowServices
    finderPendingService PS;
    vector<passService> Vps = PS.find(_code, _idCommunity);
    if(not Vps.empty())
        PS.pendingToAccepted(_code, _idCommunity);
    else
        return;
}