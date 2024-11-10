#include "passService.h"

passService::passService() 
{

}

passService::passService(unsigned int id_community, string username, string label, string description, int price, string duration, string status) : _idCommunity(id_community), _username(username), _label(label), _description(description), _price(price), _duration(duration), _statusService(status)
{

}

passService::passService(unsigned int code): _code(code)
{
    
}

passService::passService(const passService& pService){
    _code = pService._code;
    _idCommunity = pService._idCommunity;
    _username = pService._username;
    _label = pService._label;
    _description = pService._description;
    _price = pService._price;
    _duration = pService._duration;
    _statusService = pService._statusService;
}

passService::~passService()
{

}

void passService::insert()
{
    connection& con = connection::getInstance();
    try
    {
        std::string query = "INSERT INTO amep11.service (id_community, username, label, description, price, duration, status_service) VALUES ('" 
                            + to_string(_idCommunity) + "','" + _username + "', '" + _label + "', '" + _description + "', '" 
                            + to_string(_price) + "', '" + _duration + "', '" + _statusService + "')";

        con.executeUpdate(query);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


/////////////
/* SETTERS */
void passService::setCode(unsigned int code)
{
    _code = code;
}

void passService::setIdCommunity(unsigned int idCommunity)
{
    _idCommunity = idCommunity;
}

void passService::setUsername(string username)
{
    _username = username;
}

void passService::setLabel(string label)
{
    _label = label;
}

void passService::setDescription(string description)
{
    _description = description;
}

void passService::setPrice(unsigned int price)
{
    _price = price;
}

void passService::setDuration(string duration)
{
    _duration = duration;
}
void passService::setStatusService(string statusService)
{
    _statusService = statusService;
}

void passService::modifyService(string labelP, string descriptionP, unsigned int priceP, string durationP) {
    std::string codeS = std::to_string(_code);
    std::string priceS = std::to_string(priceP);
    connection& conn = connection::getInstance();
    try {
        // Actualiza label
        conn.executeUpdate("UPDATE amep11.service SET label = '"+ labelP +"' WHERE code = '"+ codeS +"' ");
        // Actualiza description
        conn.executeUpdate("UPDATE amep11.service SET description = '"+ descriptionP +"' WHERE code = '"+ codeS +"' ");
        // Actualiza price
        conn.executeUpdate("UPDATE amep11.service SET price = '"+ std::to_string(priceP) +"' WHERE code = '"+ codeS +"' ");
        // Actualiza duration
        conn.executeUpdate("UPDATE amep11.service SET duration = '"+ durationP +"' WHERE code = '"+ codeS +"' ");

        // Actualiza status
        std::string status = "pending";
        conn.executeUpdate("UPDATE amep11.service SET status_service = '"+ status +"' WHERE code = '"+ codeS +"' ");
        conn.executeUpdate("INSERT INTO amep11.pending(code_service)VALUES('"+ codeS +"')");
        conn.executeUpdate("DELETE FROM amep11.accepted WHERE code_service = '"+ codeS +"' ");

        std::cout << "Service is already modified" << std::endl;
    } catch (sql::SQLException &e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    }
}



/////////////
/* GETTERS */
unsigned int passService::getCode() const
{
    return _code;
}

unsigned int passService::getIdCommunity() const
{
    return _idCommunity;
}   

string passService::getName() const
{
    return _username;
}
string passService::getLabel() const
{
    return _label;
}
string passService::getDescription() const
{
    return _description;
}
unsigned int passService::getPrice()const
{
    return _price;
}
string passService::getDuration() const
{
    return _duration;
}
string passService::getStatusService() const
{
    return _statusService;
}