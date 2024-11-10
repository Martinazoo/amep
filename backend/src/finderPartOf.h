#ifndef FINDER_PART_OF_H
#define FINDER_PART_OF_H

#include <iostream>
#include <vector>
#include <string>
#include "passPartOf.h"
#include "passCommunity.h"
#include "connection.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class finderPartOf{        
    public:
        finderPartOf();
        ~finderPartOf();
        vector<passPartOf> findMemberCommunity(string dniNeighbor, int idCommunity);
        vector<passPartOf> findAllCommunitiesOfMember(string dniNeighbor);
        vector<passPartOf> findAllMembersOfCommunity(string namecom);
};



#endif