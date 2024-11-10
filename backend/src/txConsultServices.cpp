#include "txConsultServices.h"



/* constructor */
txConsultServices::txConsultServices()
{

}

txConsultServices::txConsultServices(string communityName, string self):_self(self), _communityName(communityName)
{

}

/* destructor */
txConsultServices::~txConsultServices()
{

}

/* pre: true */
/* post: returns the vector res */
string txConsultServices::getResult()
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


/* pre: true */
/* post: now, 'res' contains all services of the database */
void txConsultServices::execute()
{
    finderCommunity fc;
    finderService fs;
    finderAccepted fa;
    vector<passCommunity> pc = fc.findCommunity(_communityName);
    vector<passService> ps = fs.findServiceCommunityAccepted(pc[0].getId(), _self);    
    //if(pc.empty() or ps.empty()){
        //throw("There is no services in the community or the community does not exist");
   // }else {
        res = ps;
    //}
}
