#include <iostream>
#include "requests.h"
#include "httplib.h"
#include "presentationLayer.h"
#include "httplib.h"
using namespace std;

string const WEBSITE_RELATIVE_PATH = "../Website";

int main() {

    httplib::Server server;
    requests& req = requests::getInstance();
    req.requestAll(server);

    const unsigned int PORT = 8060;
    cout << "Server listening at port: " << PORT << endl;
    server.listen("localhost", PORT); 
    
        
    
        
    
    
    //presentationLayer::consultUserPendingServices();
}

