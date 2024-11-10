#include "txConsultTasks.h"

txConsultTasks::txConsultTasks(string dni, int communityCode) : _dni(dni), _communityCode(communityCode)
{
}

txConsultTasks::~txConsultTasks()
{
}

string txConsultTasks::getResult()
{
    nlohmann::json json;
    json["serveis"];

    for (unsigned int i = 0; i < _resu.size(); i++)
    {
        nlohmann::json object;
        object["code"] = _resu[i].getCode();
        object["description"] = _resu[i].getDescription();
        object["label"] = _resu[i].getLabel();
        object["price"] = _resu[i].getPrice();
        object["username"] = _resu[i].getName();
        object["duration"] = _resu[i].getDuration();
        json["serveis"].push_back(object);
    }

    return json.dump();
}

void txConsultTasks::execute()
{
    //Grab all tasks from neighbout with _dni from DB and throw them at _res
    finderTask fT;
    vector<passService> r = fT.findTasks(_dni, _communityCode);
    _resu = r;
}