#include "txEndService.h"

txEndService::txEndService()
{
    
}

txEndService::txEndService(int code, std::string dniNeighborCharge, std::string usernameNeighborPay): _code(code), _dniNeighborCharge(dniNeighborCharge), _usernameNeighborPay(usernameNeighborPay)
{
    
}

txEndService::~txEndService()
{
    
}

void txEndService::execute()
{

    finderService fs;
    finderNeighbor fn;
    cout << "el codi es " << _code << endl;
    vector<passService> vps = fs.findService(_code);
    vector<passNeighbor> vnp = fn.findNeighborByUsername(_usernameNeighborPay);
    if(vps.empty() || vnp.empty()){
        cout << "No s'ha trobat el servei o el vei" << endl;
        return;
    }else {
        passNeighbor pnc(_dniNeighborCharge, vps[0].getPrice());
        passNeighbor pnp(vnp[0].getDni(), vps[0].getPrice());

        pnc.charge();
        pnp.pay();
        
        passAcceptService pas(_code, _dniNeighborCharge);
        pas.endService();   //aqui nomes borrara el servei de la taula accepted i de la de servei
    }
}
