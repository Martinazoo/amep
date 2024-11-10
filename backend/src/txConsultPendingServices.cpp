#include "txConsultPendingServices.h"

txConsultPendingServices::txConsultPendingServices()
{

}
txConsultPendingServices::txConsultPendingServices(string communityName):_communityName(communityName)
{

}
txConsultPendingServices::~txConsultPendingServices()
{

}

void txConsultPendingServices::execute()
{
    finderService fs;
    finderCommunity fc;
    vector<passCommunity> vpc = fc.findCommunity(_communityName);
    if(!vpc.empty()){
        vector<passService> vps = fs.findServiceCommunityPending(vpc[0].getId());
        res = vps;
    }else {
        throw("The community does not exist");
    }
}

string txConsultPendingServices::getResult()
{
    nlohmann::json json;
    json["serveis"];
    for (unsigned int i = 0; i < res.size(); i++)
    {
        nlohmann::json object;
        object["code"] = res[i].getCode();
        object["id_community"] = res[i].getIdCommunity();
        object["username"] = res[i].getName();
        object["label"] = res[i].getLabel();
        object["description"] = res[i].getDescription();
        object["price"] = res[i].getPrice();
        object["duration"] = res[i].getDuration();
        object["status_service"] = res[i].getStatusService();
        json["serveis"].push_back(object);
    }
    return json.dump();
}