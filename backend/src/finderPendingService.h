#ifndef FINDER_PENDING_SERVICE_H
#define FINDER_PENDING_SERVICE_H

#include <iostream>
#include <vector>
#include "passService.h"
#include "finderService.h"
#include "passService.h"
#include <vector>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "connection.h"
using namespace std; 

class finderPendingService {        
    public:
        finderPendingService();
        ~finderPendingService();
        
        vector<passService> find(string code, string idCommunity);
        vector<passService> findPending(int idCommunity);
        void pendingToAccepted(string code, string idCommunity);
        void decline(string code, string idCommunity);
};

#endif