#include "passAdmin.h"

passAdmin::passAdmin(): _dniAdmin("")
{

}
passAdmin::passAdmin(std::string dni):_dniAdmin(dni)
{

}
passAdmin::~passAdmin()
{

}
std::string passAdmin::getDni()
{
    return _dniAdmin;
}
void passAdmin::setDni(std::string dni)
{
    _dniAdmin = dni;
}
void passAdmin::insert()
{
    connection& c = connection::getInstance();
    c.executeUpdate("INSERT INTO amep11.admin(dni_admin)VALUES('"+_dniAdmin +"')");
}
void passAdmin::modify(std::string dni)
{
    connection& c = connection::getInstance();
    c.executeUpdate("UPDATE amep11.admin SET dni_admin = '"+dni+"'");
}
void passAdmin::erase()
{
 
    connection& c = connection::getInstance();
    sql::ResultSet* res = c.connect("DELETE FROM amep11.admin WHERE dni_admin = '"+_dniAdmin+"';");
    delete res;
    

}