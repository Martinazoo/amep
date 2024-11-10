#include "txDeleteCommunity.h"

txDeleteCommunity::txDeleteCommunity()
{

}

txDeleteCommunity::~txDeleteCommunity()
{

}

txDeleteCommunity::txDeleteCommunity(int id)
{
    _id = id;
}

void txDeleteCommunity::execute()
{
    finderCommunity fc;
    vector <passCommunity> vpc = fc.findCommunitybyId(_id);
    vpc.front().erase();
}