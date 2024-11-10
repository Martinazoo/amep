#include "txConsultCommunities.h"

txConsultCommunities::txConsultCommunities()
{

}
txConsultCommunities::txConsultCommunities(std::string username):_username(username)
{

}
txConsultCommunities::~txConsultCommunities()
{

}

void txConsultCommunities::execute()
{
    finderNeighbor fn;
    finderPartOf fpo;
    vector<passNeighbor> vpn = fn.findNeighborByUsername(_username);
    if(!vpn.empty()){
        vector<passPartOf> vpo = fpo.findAllCommunitiesOfMember(vpn[0].getDni());
            
        for(unsigned int i = 0; i < vpo.size(); ++i){
            finderCommunity fc;
            vector<passCommunity> vpc = fc.findCommunitybyId(vpo[i].getId());    //PetaAqui
            res.push_back(vpc[0]);
        }
    }else{
        throw("The user does not exist");
    }
}
string txConsultCommunities::getResult()
{
    nlohmann::json json;    
    json["communities"];
    for (unsigned int i = 0; i < res.size(); i++)
    {
        nlohmann::json object;
        object["name"] = res[i].getName();
        object["description"] = res[i].getDescription();
        object["id"] = res[i].getId();
        json["communities"].push_back(object);
    }
    return json.dump();
}