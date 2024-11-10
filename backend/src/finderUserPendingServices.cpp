#include "finderUserPendingServices.h"

finderUserPendingServices::finderUserPendingServices()
{

}

finderUserPendingServices::~finderUserPendingServices()
{

}

vector<passService> finderUserPendingServices::findPendingServicesfromUser(string user, int idCommunity)
{
    string idComm = to_string(idCommunity);
    connection& conn = connection::getInstance();
    string query = "SELECT * FROM amep11.service WHERE username = " + user + " AND status_service = 'pending' AND id_community = "+ idComm +" ";
    std::cout << query << std::endl;
    
    sql::ResultSet* res = conn.connect(query);

    vector<passService> Vps2;
    while (res->next())
    {
        passService ps;
        ps.setCode(res->getUInt("code"));
        ps.setIdCommunity(res->getInt("id_community"));
        ps.setUsername(res->getString("username"));
        ps.setLabel(res->getString("label"));
        ps.setDescription(res->getString("description"));
        ps.setPrice(res->getDouble("price"));
        ps.setDuration(res->getString("duration"));
        ps.setStatusService(res->getString("status_service"));
        Vps2.push_back(ps);
    }
    delete res;
    return Vps2;
}