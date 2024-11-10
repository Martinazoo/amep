#include "passCommunity.h"
#include "connection.h"
#include <iomanip>
#include <sstream>
#include <ctime>


//constructors i destructor
passCommunity::passCommunity()
{
    
}
//Aixo en principi es podra borrar
passCommunity::passCommunity(int id, string name, string description, tm creationDate, int memberCount, string dniAdmin)
{
    _id = id;
    _dniAdmin = dniAdmin;
    _name = name;
    _description = description;
    _creationDate = creationDate;
    _memberCount = memberCount;
}

//creem la comunitat amb només nom i desc ja que la resta de dades no s'han de demanar
passCommunity::passCommunity(string name, string description, string dniAdmin)
{
    _name = name;
    _description = description;
    //Generem una id entre 1000 i 9999
    srand(static_cast<unsigned int>(time(nullptr)));
    _id = 1000 + rand() % (9999-1000 + 1);
    connection& conn = connection::getInstance();
    sql::ResultSet* res;
    res = conn.connect("SELECT * FROM amep11.community WHERE id = '" + to_string(_id) + "'");
    while (res->next())
    {
        _id = 1000 + rand() % (9999-1000 + 1);
        res = conn.connect("SELECT * FROM amep11.community WHERE id = '" + to_string(_id) + "'");
    }
    delete res;
    //Guardem la data d'avui (día al qual estem creant la comunitat)
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    _creationDate = *localTime;
   _memberCount = 1;
   _dniAdmin = dniAdmin;
}

passCommunity::~passCommunity()
{

}

void passCommunity::insert()
{
    connection& conn = connection::getInstance();
    string date = to_string(1900 + _creationDate.tm_year) + "-" + to_string(1 + _creationDate.tm_mon) + "-" + to_string(_creationDate.tm_mday);
    string id = to_string(_id);
    string membercount = to_string(_memberCount);
    conn.executeUpdate("INSERT INTO amep11.community (id, dni_admin, name, description, creation_date, num_members) VALUES ('"+ id +"', '"+ _dniAdmin +"', '"+ _name +"', '"+ _description +"', '" + date +"', '" + membercount +"')");
}

void passCommunity::modify()
{

}

void passCommunity::erase()
{
    connection& c = connection::getInstance();
    c.executeUpdate("DELETE FROM amep11.neigh_partof_comm WHERE id_community = '" + to_string(_id) + "'");
    c.executeUpdate("DELETE FROM amep11.community WHERE id = '"+ to_string(_id)+ "'");

}

void passCommunity::addMember()
{
    connection& conn = connection::getInstance();
    _memberCount++;
    string membercount = to_string(_memberCount);
    string id = to_string(_id);
    conn.executeUpdate("UPDATE amep11.community SET num_members = '"+ membercount +"' WHERE id = '"+ id +"' ");
}
void passCommunity::setId(int id)
{
    _id = id;
}

void passCommunity::setName(string name)
{
    _name = name;
}

void passCommunity::setDescription(string description)
{
    _description = description;
}

void passCommunity::setCreationDate(string date)
{

    tm time;
    istringstream ss(date);
    ss >> get_time(&time, "%y-%m-%d");

    _creationDate = time;
}

void passCommunity::setMemberCount(int memberCount)
{
    _memberCount = memberCount;
}

void passCommunity::setDniAdmin(string dniAdmin)
{
    _dniAdmin = dniAdmin;
}

int passCommunity::getId()
{
    return _id;
}

string passCommunity::getName()
{
    return _name;
}

string passCommunity::getDescription()
{
    return _description;
}

tm passCommunity::getCreationDate()
{
    return _creationDate;
}

string passCommunity::getDniAdmin()
{
    return _dniAdmin;
}

int passCommunity::getMemberCount()
{
    return _memberCount;
}