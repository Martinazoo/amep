#include "txFilterServices.h"

txFilterServices::txFilterServices()
{
    _description = "";
    _label = "";
    _minVal = 0;
    _maxVal = 0;
    _community = 0;
    _username = "";
}

txFilterServices::txFilterServices(string description, string label, int minVal, int maxVal, int community, string username): _description(description), _label(label), _minVal(minVal), _maxVal(maxVal), _community(community), _username(username)
{

}

txFilterServices::~txFilterServices()
{

}

void txFilterServices::execute()
{
    finderService fS;
    vector<passService> vps = fS.filterServices(_description, _label, _minVal, _maxVal, _community, _username);
    _resu = vps;
}

string txFilterServices::getResult()
{
    nlohmann::json json;
    json["serveis"];
    for(unsigned int i = 0; i < _resu.size(); i++)
    {
        nlohmann::json object;
        object["code"] = _resu[i].getCode();
        object["description"] = _resu[i].getDescription();
        object["duration"] = _resu[i].getDuration();
        object["id_community"] = _resu[i].getIdCommunity();
        object["label"] = _resu[i].getLabel();
        object["username"] = _resu[i].getName();
        object["price"] = _resu[i].getPrice();
        object["status_service"] = _resu[i].getStatusService();
        json["serveis"].push_back(object);
    }
    return json.dump();
}
