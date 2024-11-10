#include "txTakeService.h"

txTakeService::txTakeService()
{

}

txTakeService::txTakeService(int code, std::string username): _code(code), _username(username)
{

}

txTakeService::~txTakeService()
{

}

void txTakeService::execute()
{
    finderNeighbor fn;
    finderAccepted fa;
    finderService fs;
    vector<passNeighbor> vpn = fn.findNeighborByUsername(_username);    //mira que existeixi el vei
    std::cout << vpn[0].getDni() << std::endl;
    vector<passAcceptService> vpasc = fa.findAcceptedByCode(_code);  //mira que existeixi una fila del servei acceptat
    std::cout << vpasc[0].getCodeService() << std::endl;
    vector<passAcceptService> vpas = fa.findAccepted(vpn[0].getDni());
    if (!vpas.empty()){
        std::cout << "is emptpty" << std::endl;
    } 
    if(!vpasc.empty() and vpas.empty() and !vpn.empty()){
        passAcceptService pas(_code, vpn[0].getDni());
        pas.takeService();  
    } else {
        std::cout << "ajuda" << std::endl;
        throw("The service or the neighbor does not exist or the neighbor is doing another service ");
    }
    
}