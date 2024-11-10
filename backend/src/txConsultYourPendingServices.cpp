#include "txConsultYourPendingServices.h"

txConsultYourPendingServices::txConsultYourPendingServices()
{

}

txConsultYourPendingServices::txConsultYourPendingServices(string user, int idCommunity): _user(user), _idCommunity(idCommunity)
{

}

txConsultYourPendingServices::~txConsultYourPendingServices()
{

}

string txConsultYourPendingServices::getResult()
{
    nlohmann::json json;
    json["services"];
    for(unsigned int i = 0; i < _res.size(); i++)
    {
        nlohmann::json object;
        object["code"] = _res[i].getCode();
        object["description"] = _res[i].getDescription();
        object["duration"] = _res[i].getDuration();
        object["id_community"] = _res[i].getIdCommunity();
        object["label"] = _res[i].getLabel();
        object["username"] = _res[i].getName();
        object["price"] = _res[i].getPrice();
        object["status_service"] = _res[i].getStatusService();
        json["services"].push_back(object);
    }
    return json.dump();
}

void txConsultYourPendingServices::execute()
{
//Catch all services in pending status with username = user
    finderUserPendingServices fUPS;
    vector<passService> r = fUPS.findPendingServicesfromUser(_user, _idCommunity);
    _res = r;
}