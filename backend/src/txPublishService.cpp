#include "txPublishService.h"


txPublishService::txPublishService()
{

}

txPublishService::txPublishService(unsigned int id_community, string username, string label, string description, unsigned int price, string duration, string status): 
    _id_community(id_community), _username(username), _label(label), _description(description), _price(price), _duration(duration), _status(status)
{
    
}

txPublishService::~txPublishService()
{

}

void txPublishService::publishService()
{


}

void txPublishService::execute()
{
    std::string status = "pending";
    passService pS(_id_community, _username, _label, _description, _price, _duration, status);
    pS.insert();

}