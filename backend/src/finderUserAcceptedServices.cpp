#include "finderUserAcceptedServices.h"

finderUserAcceptedServices::finderUserAcceptedServices()
{

}

finderUserAcceptedServices::~finderUserAcceptedServices()
{

}

vector<passService> finderUserAcceptedServices::findYourAcceptedServices(string user, int idCommunity)
{
    connection& conn = connection::getInstance();
    string idComm = to_string(idCommunity);
    // Consulta SQL que une las dos tablas y filtra los resultados necesarios
    string query = "SELECT s.code, s.id_community, s.username, s.label, s.description, s.price, s.duration, s.status_service "
                   "FROM amep11.service s "
                   "JOIN amep11.accepted a ON s.code = a.code_service "
                   "WHERE s.username = '" + user + "' AND s.status_service = 'accepted' AND a.dni_neighbor IS NULL AND s.id_community = '"+ idComm +"' ";

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

