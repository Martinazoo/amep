#include "txLeaveCommunity.h"

txLeaveCommunity::txLeaveCommunity()
{
    
}

txLeaveCommunity::txLeaveCommunity(string dniUsername, string communityName):_dniUser(dniUsername), _communityName(communityName)
{
    
}

void txLeaveCommunity::execute()
{
    //Precondition the community and the user exis
    finderCommunity fc;
    vector<passCommunity> Vpc = fc.findCommunity(_communityName);  
    passPartOf ppo(_dniUser, Vpc[0].getId());
    ppo.remove();
}