#ifndef FINDER_ADMIN_H
#define FINDER_ADMIN_H
#include "passAdmin.h"
#include <iostream>
#include <vector>
#include "connection.h"
#include <mysql_driver.h>
#include <string>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

class finderAdmin{
    public:
        finderAdmin();
        ~finderAdmin();
        vector<passAdmin> findAdmin(string dniAdmin);
};

#endif