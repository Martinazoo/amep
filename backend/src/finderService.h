#ifndef FINDER_SERVICE_H
#define FINDER_SERVICE_H

#include <iostream>
#include <vector>
#include "passService.h"
#include "connection.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <algorithm>
#include <string>

using namespace std; 

class finderService{        
    public:
        finderService();
        ~finderService();
        vector<passService> findCommunityServices(unsigned int codeService);
        vector<passService> findService(unsigned int codeS);
        vector<passService> findServiceCommunityAccepted(unsigned int idCommunity, string self);
        vector<passService> findServiceCommunityPending(unsigned int idCommunity);
        vector<passService> filterServices(string name, string label, int minVal, int maxVal, int community, string username);

};

#endif