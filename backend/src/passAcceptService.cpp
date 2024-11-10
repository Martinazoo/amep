#include "passAcceptService.h"

passAcceptService::passAcceptService()

{

}

passAcceptService::passAcceptService(int codeService, std::string dniNeighbor): _codeService(codeService), _dniNeighbor(dniNeighbor)
{

}
/*
passAcceptService::passAcceptService(int codeService): _codeService(codeService)
{

}   
*/

passAcceptService::~passAcceptService()
{

}

void passAcceptService::takeService()
{
    connection& conn = connection::getInstance();
    std::string code  = std::to_string(_codeService);
    conn.executeUpdate("UPDATE amep11.accepted SET dni_neighbor = '"+ _dniNeighbor +"' WHERE code_service = '"+ code +"' ");
}

int passAcceptService::getCodeService()
{
    return _codeService;
}

std::string passAcceptService::getDniNeighbor()
{
    return _dniNeighbor;
}

void passAcceptService::endService()
{
    connection& conn = connection::getInstance();
    std::string code  = std::to_string(_codeService);
    conn.executeUpdate("DELETE FROM amep11.accepted WHERE code_service = '"+ code +"' ");
    conn.executeUpdate("DELETE FROM amep11.service WHERE code = '"+ code +"' ");
}