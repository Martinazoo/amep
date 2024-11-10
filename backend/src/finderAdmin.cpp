#include "finderAdmin.h"

finderAdmin::finderAdmin()
{

}
finderAdmin::~finderAdmin()
{

}
vector<passAdmin> finderAdmin::findAdmin(std::string dniAdmin)
{
    connection& conn = connection::getInstance();
    sql::ResultSet* res = conn.connect("SELECT * FROM amep11.admin WHERE dni_admin = '"+ dniAdmin +"' ");

    vector<passAdmin> Vpa;
    while(res->next()){
        passAdmin pa;
        pa.setDni(res->getString("dni_admin"));
        Vpa.push_back(pa);
    }
    delete res;
    return Vpa;
}