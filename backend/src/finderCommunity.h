#ifndef FINDER_COMMUNITY_H
#define FINDER_COMMUNITY_H

#include<iostream>
#include <vector>
#include "passCommunity.h"
#include "connection.h"


class finderCommunity {
    public:
        finderCommunity();
        ~finderCommunity();

        vector<passCommunity> findCommunity(string name);
        vector<passCommunity> findCommunitybyId(int id);

};

#endif