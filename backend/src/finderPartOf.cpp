#include "finderPartOf.h"

finderPartOf::finderPartOf()
{

}
finderPartOf::~finderPartOf()
{

}
vector<passPartOf>finderPartOf::findMemberCommunity(string dniNeighbor, int idCommunity)
{
    string strIdCommunity = to_string(idCommunity);
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.neigh_partof_comm WHERE dni_neighbor = '"+dniNeighbor +"' and id_community = '"+ strIdCommunity +"' ");

    vector<passPartOf> Vppo;
    while(res->next()){
        passPartOf ppo;
        ppo.setDni(res->getString("dni_neighbor"));
        ppo.setId(res->getInt("id_community"));
        Vppo.push_back(ppo);
    }
    delete res;
    return Vppo;
}
vector<passPartOf>finderPartOf::findAllCommunitiesOfMember(string dniNeighbor)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.neigh_partof_comm WHERE dni_neighbor = '"+dniNeighbor +"' ");

    vector<passPartOf> Vppo;
    while(res->next()){
        passPartOf ppo;
        ppo.setDni(res->getString("dni_neighbor"));
        ppo.setId(res->getInt("id_community"));
        Vppo.push_back(ppo);
    }
    delete res;
    return Vppo;
}

vector<passPartOf>finderPartOf::findAllMembersOfCommunity(string namecom)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* comID = conn.connect("SELECT * FROM amep11.community WHERE name = '"+namecom+"' ");
    comID->next();

    int idOfCom = comID->getInt("id");
    string stringComID = to_string(idOfCom);

    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.neigh_partof_comm WHERE id_community = '"+ stringComID +"' ");

    vector<passPartOf> Vppo;
    while(res->next()){
        passPartOf ppo;
        ppo.setDni(res->getString("dni_neighbor"));
        ppo.setId(res->getInt("id_community"));
        Vppo.push_back(ppo);
    }
    delete res;
    return Vppo;
}  

