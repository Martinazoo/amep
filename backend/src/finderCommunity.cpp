#include "finderCommunity.h"

finderCommunity::finderCommunity()
{

}

finderCommunity::~finderCommunity()
{

}

vector<passCommunity> finderCommunity::findCommunity(string name) 
{
    connection& c = connection::getInstance();
    sql::ResultSet* res = c.connect("SELECT * FROM amep11.community WHERE name = '" + name + "'");
    vector<passCommunity> vpc;
    while(res->next()){
        passCommunity pC;
        pC.setId(res->getInt("id"));
        pC.setDniAdmin(res->getString("dni_admin"));
        pC.setName(res->getString("name"));
        pC.setDescription(res->getString("description"));
        pC.setCreationDate(res->getString("creation_date"));
        pC.setMemberCount(res->getInt("num_members"));
        vpc.push_back(pC);
    }
    delete res;
    return vpc;  
}

vector<passCommunity> finderCommunity::findCommunitybyId(int id)
{
    string strid = to_string(id);
    connection& c = connection::getInstance();
    sql::ResultSet* res = c.connect("SELECT * FROM amep11.community WHERE id = '" + strid + "' ");
    vector<passCommunity> vpc;
    while(res->next()){
        passCommunity pC;
        pC.setId(res->getInt("id"));
        pC.setDniAdmin(res->getString("dni_admin"));
        pC.setName(res->getString("name"));
        pC.setDescription(res->getString("description"));
        pC.setCreationDate(res->getString("creation_date"));
        pC.setMemberCount(res->getInt("num_members"));
        vpc.push_back(pC);
    }
    delete res;
    return vpc; 
}
