#include "finderPendingService.h"


/* constructor */
finderPendingService::finderPendingService()
{

}

/* destructor */
finderPendingService::~finderPendingService()
{

}

vector<passService> finderPendingService::find(string code, string idCommunity)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.pending WHERE code_service = '"+ code +"'");

    vector<passService> Vps;
    while(res->next()){
        passService ps;
        ps.setCode(res->getInt("code_service"));
        Vps.push_back(ps);
        //cout << Vps[0].getCode() << endl;
    }
    delete res;
    return Vps;
}

vector<passService> finderPendingService::findPending(int idCommunity)
{
    connection& conn = connection::getInstance();
    string idComm = to_string(idCommunity);
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.service WHERE id_community = '"+ idComm +"' AND status_service = 'pending'");
    vector<passService> Vps;
    passService ps;
    while(res->next()){
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


void finderPendingService::pendingToAccepted(string code, string idCommunity)
{
    connection& conn = connection::getInstance();
    try {
        std::cout << "plorem" << std::endl;
        // Eliminar el elemento de la tabla 'pending'
        conn.executeUpdate("DELETE FROM amep11.pending WHERE code_service = '"+ code+"' ");
        std::cout << "Service accepted" << std::endl;
        // Insertar en la tabla 'accepted'
        conn.executeUpdate("INSERT INTO amep11.accepted (code_service, dni_neighbor) VALUES ('"+ code +"', NULL)");
        conn.executeUpdate("UPDATE amep11.service SET status_service = 'accepted' WHERE code = '"+ code +"' AND id_community = '"+ idCommunity +"'");
    } catch (sql::SQLException& e) {
        // Manejo de excepciones de MySQL
        std::cerr << "Error MySQL: " << e.what() << std::endl;
    }

    // No necesitas eliminar el ResultSet aquí, ya que no estás utilizando uno

}



void finderPendingService::decline(string code, string idCommunity)
{
    connection& conn = connection::getInstance();
    try {
        // Eliminar el elemento de la tabla 'pending'
        conn.executeUpdate("DELETE FROM amep11.pending WHERE code_service = '"+ code+"' ");
        conn.executeUpdate("DELETE FROM amep11.service WHERE code = '"+ code+"' ");
    } catch (sql::SQLException& e) {
        // Manejo de excepciones de MySQL
        std::cerr << "Error MySQL: " << e.what() << std::endl;
    }
}
