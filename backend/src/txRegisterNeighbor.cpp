#include "txRegisterNeighbor.h"

// constructoras i destructora
txRegisterNeighbor::txRegisterNeighbor()
{

}

txRegisterNeighbor::~txRegisterNeighbor()
{

}

txRegisterNeighbor::txRegisterNeighbor(string dN, string mN, string nN, 
                 string uN, string pN, unsigned int tN): _dniN(dN), _mailN(mN), 
                 _nameN(nN), _usernameN(uN), _passwordN(pN),_tokensN(tN)
{

}


void txRegisterNeighbor::execute()
{
   _error = "";
    passNeighbor n(_dniN, _mailN, _nameN, _usernameN, _passwordN, _tokensN);
   
   try {
    n.insert();
   } catch (sql::SQLException &e) {
    if (e.getErrorCode() == 1062) { 
        std::string errorMessage = e.what();
        std::cerr << errorMessage << std::endl;
        std::regex columnRegex("'([^']+)_UNIQUE'");
        std::regex primaryRegex("'([^']+).PRIMARY'");
        std::smatch matches;
        if (std::regex_search(errorMessage, matches, columnRegex) && matches.size() > 1) {
            std::string column = matches.str(1);
            if(column == "neighbor.mail"){
                _error = "El correu ja existeix.";
            } else if(column == "neighbor.username"){
                _error = "El nom d'usuari ja existeix.";
            }
        } else if(std::regex_search(errorMessage, matches, primaryRegex) && matches.size() > 1){
            _error = "El DNI ja existeix.";
        }else {
            _error = "Error desconegut, prova-ho més tard.";
            std::cerr << "Could not extract the column name from the error message." << std::endl;
        }
    } else {
        std::cerr << "Unknown error." << std::endl;
    }
   }
   
}

std::string txRegisterNeighbor::getResult(){
    nlohmann::json j;
    j["error"] = _error;
    return j.dump();
}
