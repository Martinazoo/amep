#ifndef FINDER_ACCEPTED_H
#define FINDER_ACCEPTED_H
#include <iostream>
#include <vector>
#include <mysql_driver.h>
#include <string>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "passAcceptService.h"
#include "connection.h"

class finderAccepted{
    public:
        finderAccepted();
        ~finderAccepted();
        std::vector<passAcceptService> findAccepted(std::string dniNeighbor);
        std::vector<passAcceptService> findAcceptedByCode(int codeService);
        std::vector<passAcceptService> findAcceptedByCodeAndDni(int codeService, std::string dniNeighbor);
};


#endif