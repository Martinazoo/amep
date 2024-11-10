#include "txModifyNeighbor.h"
#include <iostream>

txModifyNeighbor::txModifyNeighbor()
{

}
txModifyNeighbor::~txModifyNeighbor()
{

}
txModifyNeighbor::txModifyNeighbor(string username, string name, string password): _user(username), _name(name), _password(password)
{

}

void txModifyNeighbor::execute()
{
    _error = "";
    finderNeighbor fn;
    vector<passNeighbor> vpn = fn.findNeighborByUsername(_user);
    if (_name != ""){
        vpn[0].setName(_name);
    } else {
         _error = "Nom buit";
    }
    if (_password != ""){
        vpn[0].setPassword(_password);
    } else {
        _error = "Contrasenya buida";
    }
    
    vpn[0].modify();
}

std::string txModifyNeighbor::getResult(){
    nlohmann::json j;
    j["error"] = _error;
    return j.dump();
}
