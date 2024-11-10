#include"txValidateNeighbor.h"

txValidateNeighbor::txValidateNeighbor(string usr, string pass)
{
    _usr = usr;
    _pass = pass;
    _neighbor = passNeighbor();
}

void txValidateNeighbor::execute(){

    finderNeighbor fN;
    vector<passNeighbor> neighbors = fN.findNeighborByUsername(_usr);
    if (neighbors.size() > 0){
        _neighbor = neighbors[0];
        if (neighbors[0].getPassword() == _pass){
            _valid = true;
        } else {
            _valid = false;
            _error = "Contrasenya incorrecta";
        }
    } else if (neighbors.size() <= 0) {
        _valid = false;
        _error = "Usuari inexistent";
    }
}

nlohmann::json txValidateNeighbor::getResult(){
    nlohmann::json j;

    j["validation"] = _valid;
    if (_valid){
        j["name"] = _neighbor.getName();
        j["username"] = _neighbor.getUsername();
        j["mail"] = _neighbor.getMail();
        j["tokens"] = _neighbor.getTokens();
        j["name"] = _neighbor.getName();
        j["dni"] = _neighbor.getDni();
    } else {
        j["error"] = _error;
    }
    return j;
}



txValidateNeighbor::~txValidateNeighbor()
{
}