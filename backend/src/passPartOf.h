#ifndef PASS_PART_OF_H
#define PASS_PART_OF_H
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "connection.h"
#include "finderNeighbor.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;


class passPartOf{
    private:
        string _dniNeighbor;
        int _idCommunity;
    public:
        passPartOf();
        ~passPartOf();
        passPartOf(string dniNeighbor, int idCommunity);

        void setDni(string dniNeighbor);
        void setId(int idCommunity);

        string getDni();
        int getId();

        void insert();
        void remove();

};
#endif