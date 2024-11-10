#ifndef FINDER_USER_ACCEPTED_SERVICES_H
#define FINDER_USER_ACCEPTED_SERVICES_H

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

class finderUserAcceptedServices{
    public:
        finderUserAcceptedServices();
        ~finderUserAcceptedServices();

        vector<passService> findYourAcceptedServices(string user, int idCommunity);
};

#endif