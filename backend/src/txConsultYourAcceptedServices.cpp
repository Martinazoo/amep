#include "txConsultYourAcceptedServices.h"

txConsultYourAcceptedServices::txConsultYourAcceptedServices()
{

}

txConsultYourAcceptedServices::txConsultYourAcceptedServices(string user, int idCommunity): _user(user), _idCommunity(idCommunity)
{

}

txConsultYourAcceptedServices::~txConsultYourAcceptedServices()
{

}

string txConsultYourAcceptedServices::getResult()
{
    nlohmann::json json;
    json["serveis"];
    for(unsigned int i = 0; i < res.size(); i++)
    {
        nlohmann::json object;
        object["code"] = res[i].getCode();
        object["description"] = res[i].getDescription();
        object["duration"] = res[i].getDuration();
        object["id_community"] = res[i].getIdCommunity();
        object["label"] = res[i].getLabel();
        object["username"] = res[i].getName();
        object["price"] = res[i].getPrice();
        object["status_service"] = res[i].getStatusService();
        json["serveis"].push_back(object);
    }
    return json.dump();
}

void txConsultYourAcceptedServices::execute()
{
//grab all services in accepted status not taken yet with username = user
    finderUserAcceptedServices fUAS;
    vector<passService> r = fUAS.findYourAcceptedServices(_user, _idCommunity);
    res = r;
}