#include "txDeleteNeighbor.h"
using namespace std;
/*constructor*/

txDeleteNeighbor::txDeleteNeighbor()
{
    
}

txDeleteNeighbor::~txDeleteNeighbor()
{

}

txDeleteNeighbor::txDeleteNeighbor(string dni)
{
    _dni = dni;   
}


void txDeleteNeighbor::execute()
{
    std::cout <<"hola" << std::endl;
    passNeighbor pN(_dni);
    std::cout << "vaig a esborrar" << std::endl;
    pN.erase();
    std::cout << "ja he esborrat" << std::endl;

}