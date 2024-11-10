#include "txModifyCommunity.h"

txModifyCommunity::txModifyCommunity(string name, string newName, string newDescription){
    _name = name;
    _newName = newName;
    _newDescription = newDescription;
}

void txModifyCommunity::execute(){
    connection& conn = connection::getInstance();
    string query = "UPDATE community SET name = '" + _newName + "', description = '" + _newDescription + "' WHERE name = '" + _name + "'";
    
    conn.executeUpdate(query);
}