#include "txAddNeighbor.h"

txAddNeighbor::txAddNeighbor()
{

}

txAddNeighbor::txAddNeighbor(std::string username, std::string communityName):_username(username), _communityName(communityName)
{

}

txAddNeighbor::~txAddNeighbor()
{

}

void txAddNeighbor::execute()
{
    finderNeighbor fn;
    finderCommunity fc;
    finderPartOf fpo;
    vector<passNeighbor> vpn = fn.findNeighborByUsername(_username);
    vector<passCommunity> vpc = fc.findCommunity(_communityName);
    if(!vpn.empty() and !vpc.empty()){
        vector<passPartOf> vppo = fpo.findMemberCommunity(vpn[0].getDni(), vpc[0].getId());
        if(vppo.empty()){
            passPartOf ppo(vpn[0].getDni(), vpc[0].getId());
            ppo.insert();
            vpc[0].addMember();
        }else {
            throw("The user is already in the Community.");
        }
    }else {
        throw("The user or the Community do not exist in the system. ");
    }
}