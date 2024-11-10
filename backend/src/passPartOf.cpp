#include "passPartOf.h"

passPartOf::passPartOf()
{

}
passPartOf::~passPartOf()
{

}
passPartOf::passPartOf(string dniNeighbor, int idCommunity):_dniNeighbor(dniNeighbor), _idCommunity(idCommunity)
{

}

void passPartOf::setDni(string dniNeighbor)
{
    _dniNeighbor = dniNeighbor;
}

void passPartOf::setId(int idCommunity)
{
    _idCommunity = idCommunity;
}

string passPartOf::getDni()
{
    return _dniNeighbor;
}

int passPartOf::getId()
{
    return _idCommunity;
}

void passPartOf::insert()
{   
    string strIdComm = to_string(_idCommunity);
    connection& conn = connection::getInstance();
    cout << _dniNeighbor << endl;
    cout << strIdComm << endl;
    conn.executeUpdate("INSERT INTO amep11.neigh_partof_comm (dni_neighbor, id_community) VALUES ('"+ _dniNeighbor +"', '"+ strIdComm +"')"); //falla aqui
    
}
//Deletes all the services of the user and the user of thecommunity
void passPartOf::remove()
{
    finderNeighbor fn;
    vector<passNeighbor> vpn = fn.findNeighbor(_dniNeighbor);
    string strIdComm = to_string(_idCommunity);
    connection& conn = connection::getInstance();
    conn.executeUpdate("DELETE FROM amep11.neigh_partof_comm WHERE dni_neighbor = '"+ _dniNeighbor +"' and id_community = '"+ strIdComm +"'");
    conn.executeUpdate("DELETE FROM amep11.service WHERE username = '"+ vpn[0].getName() +"' and id_community = '"+ strIdComm +"'");
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.service WHERE id_community = '"+ strIdComm +"' and status_service = 'accepted' ");
    while(res->next()){
        string codeService = to_string(res->getInt("code"));
        conn.executeUpdate("DELETE FROM amep11.accepted WHERE code_service = '"+ codeService +"' and dni_neighbor = '"+ _dniNeighbor +"' ");
    }
    delete res;


}