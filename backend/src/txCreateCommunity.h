#ifndef TX_CREATE_COMMUNITY_H
#define TX_CREATE_COMMUNITY_H
#include <iostream>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "passCommunity.h"
#include "finderCommunity.h"
#include "finderNeighbor.h"
#include "finderPartOf.h"
#include "passPartOf.h"
#include <nlohmann/json.hpp>
using namespace std;

class txCreateCommunity{
    private:
        int _id;
        string _username;
        string _name;
        string _description;
        tm _creationDate;
        unsigned int _numMembers;
        std::string _error;
        
    public:
        txCreateCommunity();
        ~txCreateCommunity();
        txCreateCommunity(string username, string name, string description);
        std::string getResult();

        void execute();
};

#endif