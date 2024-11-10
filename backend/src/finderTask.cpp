#include "finderTask.h"

finderTask::finderTask()
{
}
        
finderTask::~finderTask()
{
}

vector<passService> finderTask::findTasks(string dni, int communityCode)
{
    connection& conn = connection::getInstance();
    string code = to_string(communityCode);
    // Consulta SQL que une las tablas 'accepted' y 'service' y filtra por 'dni_neighbor'
    string query = "SELECT s.code, s.id_community, s.username, s.label, s.description, s.price, s.duration, s.status_service "
                   "FROM amep11.service s "
                   "JOIN amep11.accepted a ON s.code = a.code_service "
                   "WHERE a.dni_neighbor = '" + dni + "' AND s.id_community = '" + code +"' "; 

    sql::ResultSet* res = conn.connect(query);

    vector<passService> Vps;
    while (res->next())
    {
        passService ps;
        ps.setCode(res->getUInt("code"));
        ps.setIdCommunity(res->getUInt("id_community"));
        ps.setUsername(res->getString("username"));
        ps.setLabel(res->getString("label"));
        ps.setDescription(res->getString("description"));
        ps.setPrice(res->getInt("price"));
        ps.setDuration(res->getString("duration"));
        ps.setStatusService(res->getString("status_service"));
        Vps.push_back(ps);
    }

    delete res;
    return Vps;
}
