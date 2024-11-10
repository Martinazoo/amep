#include "txConsultService.h"


// constructores i destructora
txConsultService::txConsultService()
{

}

txConsultService::txConsultService(unsigned int code): _code(code) 
{

}

txConsultService::~txConsultService() 
{

}


/* pre: true */
/* post: now, 'res' contains the service with code= _code */
void txConsultService::execute()
{
    finderService finder;
    vector<passService> vps = finder.findService(_code);
    res = vps;
}

vector<passService> txConsultService::getResult() 
{
    return res; 
}