#ifndef FINDER_NEIGHBOR_H
#define FINDER_NEIGHBOR_H
#include <iostream>
#include <vector>
#include <string>
#include "passNeighbor.h"
#include "connection.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


class finderNeighbor{
    public:
        finderNeighbor();
        ~finderNeighbor();
        std::vector<passNeighbor> findNeighbor(std::string dniNeighbor);
        std::vector<passNeighbor> findNeighborByUsername(std::string username);
        std::vector<passNeighbor> findCollision(std::string username, std::string mail, std::string dni);

};

#endif
