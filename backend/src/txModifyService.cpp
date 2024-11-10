#include "txModifyService.h"

txModifyService::txModifyService()
{

}

txModifyService::~txModifyService()
{

}

txModifyService::txModifyService(string code, string loggedUser): _code(code), _lUser(loggedUser)
{

}

void txModifyService::execute()
{
    try{
        finderAccepted fA;
        vector<passAcceptService> Vas = fA.findAcceptedByCode(std::stoi(_code));
        if(not Vas.empty())
        {
            string dni_neighbor = Vas[0].getDniNeighbor();
            if(dni_neighbor == "")
            {
                finderService fS;
                vector<passService> Vps = fS.findService(std::stoi(_code));
                if(not Vps.empty())
                {
                    if(_lUser == Vps[0].getName()) return;
                    else
                    {
                        throw std::runtime_error("You're not allowed to modify a service you've not published");
                    }
                }
            }
            else
            {
                throw std::runtime_error("The service is already taken!");
            }
        }
        else 
        {
            throw std::runtime_error("The service is not accepted yet");
        }
    } catch(const std::exception &err){
        std::cerr << "ERROR: " << err.what() << std::endl;
    }
}

void txModifyService::modify(string label, string description, int price, string duration)
{
    try{
        finderService fS;
        vector<passService> Vps = fS.findService(std::stoi(_code));
        if(!Vps.empty())
        {
            Vps[0].modifyService(label, description, price, duration);
            std::cout << "Service modified correctly" << std::endl;
            
        }
        else {
            throw std::runtime_error("The service doesn't exist");
        }
    } catch (const sql::SQLException& e) {
        // Manejo de excepciones de MySQL
        std::cerr << "Error MySQL: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Manejo de otras excepciones
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
