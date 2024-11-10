#ifndef PASS_ADMIN_H
#define PASS_ADMIN_H

#include <iostream>
#include <string>
#include <vector>
#include "connection.h"
#include "passNeighbor.h"
#include "finderNeighbor.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

class passAdmin{
    private:
        std::string _dniAdmin;
    public:
        passAdmin();
        passAdmin(std::string dni);
        ~passAdmin();

        /* GETTERS */
        std::string getDni();
        /* SETTERS */
        void setDni(std::string dni);
        void insert();
        /* the modify function is not needed because in our application the dni cannot be modified */
        void modify(std::string dni);
        /* the eras function is not needed because in our application the admin cannot be deleted */
        void erase();

};


#endif