#ifndef TX_MODIFY_COMMUNITY_H
#define TX_MODIFY_COMMUNITY_H

#include <iostream>
#include <vector>
#include "connection.h"
#include "passCommunity.h"

using namespace std;

class txModifyCommunity{
    private:
        string _name;
        string _newName;
        string _newDescription;
    public:
        txModifyCommunity(string name, string newName, string newDescription);
        void execute();
};

#endif