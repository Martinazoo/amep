#ifndef TX_CREATE_ADMIN_H
#define TX_CREATE_ADMIN_H
#include <iostream>
#include <string>
#include <vector>
#include "passAdmin.h"
#include "finderAdmin.h"
#include "finderNeighbor.h"
#include "passNeighbor.h"
class txCreateAdmin{
    private:
        std::string _username;
    public:
        txCreateAdmin();
        txCreateAdmin(std::string username);
        ~txCreateAdmin();
        void execute();
};

#endif