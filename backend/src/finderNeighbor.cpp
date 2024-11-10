#include "finderNeighbor.h"

finderNeighbor::finderNeighbor()
{

}
finderNeighbor::~finderNeighbor()
{

}
vector<passNeighbor> finderNeighbor::findNeighbor(std::string dniNeighbor)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.neighbor WHERE dni = '"+dniNeighbor +"' ");

    vector<passNeighbor> Vpn;
    while(res->next()){
        passNeighbor pn;
        pn.setDni(res->getString("dni"));
        pn.setMail(res->getString("mail"));
        pn.setName(res->getString("name"));
        pn.setUsername(res->getString("username"));
        pn.setPassword(res->getString("password"));
        pn.setTokens(res->getUInt("tokens"));
        Vpn.push_back(pn);
    }
    delete res;
    return Vpn;
}

vector<passNeighbor> finderNeighbor::findNeighborByUsername(std::string username)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.neighbor WHERE username = '"+ username +"' ");
    vector<passNeighbor> Vpn;
    while(res->next()){
        passNeighbor pn;
        pn.setDni(res->getString("dni"));
        pn.setMail(res->getString("mail"));
        pn.setName(res->getString("name"));
        pn.setUsername(res->getString("username"));
        pn.setPassword(res->getString("password"));
        pn.setTokens(res->getUInt("tokens"));
        Vpn.push_back(pn);
    }
    delete res;
    return Vpn;
}

std::vector<passNeighbor> findCollision(std::string username, std::string mail, std::string dni){
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.neighbor WHERE username = '"+ username +"' OR mail = '"+ mail +"' OR dni = '"+ dni +"' ");

    vector<passNeighbor> Vpn;
    while(res->next()){
        passNeighbor pn;
        pn.setDni(res->getString("dni"));
        pn.setMail(res->getString("mail"));
        pn.setName(res->getString("name"));
        pn.setUsername(res->getString("username"));
        pn.setPassword(res->getString("password"));
        pn.setTokens(res->getUInt("tokens"));
        Vpn.push_back(pn);
    }
    delete res;
    return Vpn;
}
