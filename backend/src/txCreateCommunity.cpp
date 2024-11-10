#include "txCreateCommunity.h"

//constructors i destructor
txCreateCommunity::txCreateCommunity()
{

}

txCreateCommunity::~txCreateCommunity()
{

}

txCreateCommunity::txCreateCommunity(string username, string name, string description): _username(username), _name(name), _description(description)
{

}

void txCreateCommunity::execute()
{
    _error = "";
    finderNeighbor fn;
    finderCommunity fc;
    vector<passNeighbor> vpn = fn.findNeighborByUsername(_username);
    vector<passCommunity> vpc = fc.findCommunity(_name);
    if(!vpn.empty() and vpc.empty()) {
        passCommunity p(_name,_description, vpn[0].getDni());
        p.insert();
        vector<passCommunity> vpcCreated = fc.findCommunity(_name);
        passPartOf ppo(vpn[0].getDni(), vpcCreated[0].getId());
        ppo.insert();   
    } else {
        _error = "The user does not exist or the community already exists";
        throw _error;
    }    
}

std::string txCreateCommunity::getResult()
{
    nlohmann::json j;
    j["error"] = _error;
    return j.dump();
}