#include "finderService.h"

/* constructor */
finderService::finderService()
{
    
}

/* destructor */
finderService::~finderService()
{

}

/* Pre: */
/* Post: returns a vector that contains the info of all Services in the system */

vector<passService> finderService::findCommunityServices(unsigned int codeService)
{
    connection& conn = connection::getInstance();
    string codeS = to_string(codeService);
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.accepted WHERE code_service = '"+ codeS +"' ");

    vector<passService> Vps;
    while(res->next()){
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

vector<passService> finderService::findService(unsigned int codeS) {
    
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.service WHERE code = '" + to_string(codeS) + "'");
    
    passService ps;
    vector<passService> Vps;
    if (res->next()) {
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
    
    // netejar els recursos
    delete res;   
    return Vps; 
}

vector<passService> finderService::findServiceCommunityAccepted(unsigned int idCommunity, string self)
{
    connection& conn = connection::getInstance();
    string idC = to_string(idCommunity);

    // Consulta SQL que une las tablas 'service' y 'accepted' para obtener los servicios aceptados
    string query = "SELECT s.code, s.id_community, s.username, s.label, s.description, s.price, s.duration, s.status_service "
                   "FROM amep11.service s "
                   "JOIN amep11.accepted a ON s.code = a.code_service "
                   "WHERE s.id_community = " + idC + " AND s.status_service = 'accepted' AND a.dni_neighbor IS NULL "
                   "AND s.username != '" + self + "'";

    sql::ResultSet* res = conn.connect(query);

    vector<passService> Vp2;
    while (res->next())
    {
        passService ps;
        ps.setCode(res->getInt("code"));
        ps.setIdCommunity(res->getInt("id_community"));
        ps.setUsername(res->getString("username"));
        ps.setLabel(res->getString("label"));
        ps.setDescription(res->getString("description"));
        ps.setPrice(res->getInt("price"));
        ps.setDuration(res->getString("duration"));
        ps.setStatusService(res->getString("status_service"));
        Vp2.push_back(ps);
    }

    delete res;
    return Vp2;
}


vector<passService> finderService::findServiceCommunityPending(unsigned int idCommunity)
{
    connection& conn = connection::getInstance();
    string idC = to_string(idCommunity);
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.service WHERE id_community = '"+ idC +"' AND status_service = 'pending'");

    vector<passService> Vps;
    while(res->next()){
        passService ps;
        ps.setCode(res->getInt("code"));
        ps.setIdCommunity(res->getInt("id_community"));
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

vector<passService> finderService::filterServices(string description, string label, int minVal, int maxVal, int community, string self)
{
    connection& conn = connection::getInstance();
    string minV = to_string(minVal);
    string maxV = to_string(maxVal);
    string idComm = to_string(community);
    string query;
    if(description == "" and label =="Tots"){
        query = "SELECT s.code, s.id_community, s.username, s.label, s.description, s.price, s.duration, s.status_service "
                    "FROM amep11.service s "
                    "JOIN amep11.accepted a ON s.code = a.code_service "
                    "WHERE s.id_community = " + idComm + " AND s.status_service = 'accepted' AND a.dni_neighbor IS NULL "
                    "AND s.username != '" + self + "'"
                    "AND s.price >= " + minV + " AND s.price <= " + maxV + "";
    }else if(description != "" and label != "Tots"){
        query = "SELECT s.code, s.id_community, s.username, s.label, s.description, s.price, s.duration, s.status_service "
                    "FROM amep11.service s "
                    "JOIN amep11.accepted a ON s.code = a.code_service "
                    "WHERE s.id_community = " + idComm + " AND s.status_service = 'accepted' AND a.dni_neighbor IS NULL "
                    "AND s.username != '" + self + "' AND s.description LIKE '" + description + "%' "
                    "AND s.label = '"+ label +"' AND s.price >= '" + minV + "' AND s.price <= '" + maxV + "'";
    }else if( description != "" and label == "Tots"){
        query = "SELECT s.code, s.id_community, s.username, s.label, s.description, s.price, s.duration, s.status_service "
                    "FROM amep11.service s "
                    "JOIN amep11.accepted a ON s.code = a.code_service "
                    "WHERE s.id_community = " + idComm + " AND s.status_service = 'accepted' AND a.dni_neighbor IS NULL "
                    "AND s.username != '" + self + "' AND s.description LIKE '" + description + "%' "
                    "AND s.price >= '" + minV + "' AND s.price <= '" + maxV + "'";
    }else if(description == "" and label != "Tots"){
        query = "SELECT s.code, s.id_community, s.username, s.label, s.description, s.price, s.duration, s.status_service "
                    "FROM amep11.service s "
                    "JOIN amep11.accepted a ON s.code = a.code_service "
                    "WHERE s.id_community = " + idComm + " AND s.status_service = 'accepted' AND a.dni_neighbor IS NULL "
                    "AND s.username != '" + self + "' AND s.label = '"+ label +"' AND s.price >= '" + minV + "' AND s.price <= '" + maxV + "'";
    }
    cout << query << endl;

    sql::ResultSet* res = conn.connect(query);
    vector<passService> Vps;
    while(res->next()){
        passService ps;
        ps.setCode(res->getInt("code"));
        ps.setIdCommunity(res->getInt("id_community"));
        ps.setUsername(res->getString("username"));
        ps.setLabel(res->getString("label"));
        ps.setDescription(res->getString("description"));
        ps.setPrice(res->getInt("price"));
        ps.setDuration(res->getString("duration"));
        ps.setStatusService(res->getString("status_service"));
        Vps.push_back(ps);
    }
    cout << "Vps size: " << Vps.size() << endl;
    delete res;
    return Vps;
}
