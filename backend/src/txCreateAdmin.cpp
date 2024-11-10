#include "txCreateAdmin.h"

txCreateAdmin::txCreateAdmin():_username("")
{

}

txCreateAdmin::txCreateAdmin(std::string dni):_username(dni)
{

}

txCreateAdmin::~txCreateAdmin()
{

}

void txCreateAdmin::execute()
{
        finderNeighbor fn;
        vector<passNeighbor> vpn = fn.findNeighborByUsername(_username);  //find neighbor by username
        finderAdmin fa;
        vector<passAdmin> vpa = fa.findAdmin(vpn[0].getDni());
        if(vpn.empty()){
            throw("The user does not exist");
        }else if(vpa.empty()) {
            passAdmin pa(vpn[0].getDni());
            pa.insert();
        }
}