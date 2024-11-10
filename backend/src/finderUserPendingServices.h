#ifndef FINDER_USER_PENDING_SERVICES_H
#define FINDER_USER_PENDING_SERVICES_H

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
#include <string>

class finderUserPendingServices {
    public:
        finderUserPendingServices();
        ~finderUserPendingServices();

        vector<passService> findPendingServicesfromUser(std::string user, int idCommunity);
};

#endif