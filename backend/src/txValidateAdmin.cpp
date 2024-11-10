#include "txValidateAdmin.h"

txValidateAdmin::txValidateAdmin(std::string userName, std::string communityName)
{
    _communityName = communityName;
    _userName = userName;
    _validation = false;
}

txValidateAdmin::~txValidateAdmin()
{
}

void txValidateAdmin::execute(){
    finderNeighbor fN;
    std::vector<passNeighbor> neighbor = fN.findNeighborByUsername(_userName);
    
    if (neighbor.size() < 1){
        _error = "ERROR: Your user does not exist";
        return;
    }
    
    std::string userDni = neighbor[0].getDni();
    
    finderCommunity fC;
    vector<passCommunity> community = fC.findCommunity(_communityName);
    if (community.size() < 1){
        _error = "ERROR: The community your looking for doesn't exists";
        return;
    }

    std::string communityDni = community[0].getDniAdmin();

    if (communityDni == userDni){
        _validation = true;
        _error = "";
    } else {
        _error = "ERROR: You are not the administrator of this community";
    }
    
}

nlohmann::json txValidateAdmin::getResult(){
    nlohmann::json result;
    result["validation"] = _validation;
    result["error"] = _error;    
    return result;
}