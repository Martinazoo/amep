#ifndef TX_VALIDATE_ADMIN_HPP
#define TX_VALIDATE_ADMIN_HPP

#include<string>
#include "nlohmann/json.hpp"
#include "passNeighbor.h"
#include "finderNeighbor.h"
#include "passCommunity.h"
#include "finderCommunity.h"
#include <vector>


class txValidateAdmin
{
private:
    bool _validation;
    std::string _error;
    std::string _communityName;
    std::string _userName;
    
public:
    txValidateAdmin(std::string userName, std::string communityName);
    ~txValidateAdmin();

    void execute();

    nlohmann::json getResult();
    
};

#endif