#include "finderAccepted.h"

finderAccepted::finderAccepted()
{

}

finderAccepted::~finderAccepted()
{

}

std::vector<passAcceptService> finderAccepted::findAccepted(std::string dniNeighbor)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res;
    res = conn.connect("SELECT * FROM amep11.accepted WHERE dni_neighbor = '"+ dniNeighbor +"'");
    std::vector<passAcceptService> accepted;
    while(res->next())
    {
        passAcceptService pass(res->getInt("code_service"), res->getString("dni_neighbor"));
        accepted.push_back(pass);
    }
    delete res;
    return accepted;
}

std::vector<passAcceptService> finderAccepted::findAcceptedByCode(int codeService)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res;
    std::string code = std::to_string(codeService);
    res = conn.connect("SELECT * FROM amep11.accepted WHERE code_service = '"+ code +"' AND dni_neighbor IS NULL");
    std::vector<passAcceptService> accepted;
    while(res->next())
    {
        passAcceptService pass(res->getInt("code_service"), res->getString("dni_neighbor"));
        accepted.push_back(pass);
    }
    delete res;
    return accepted;
}
std::vector<passAcceptService> finderAccepted::findAcceptedByCodeAndDni(int codeService, std::string dniNeighbor)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res;
    res = conn.connect("SELECT * FROM amep11.accepted WHERE code_service = '"+ std::to_string(codeService) +"' AND dni_neighbor = '"+ dniNeighbor +"'");
    std::vector<passAcceptService> accepted;
    while(res->next())
    {
        passAcceptService pass(res->getInt("code_service"), res->getString("dni_neighbor"));
        accepted.push_back(pass);
    }
    delete res;
    return accepted;
}