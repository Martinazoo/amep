#include "presentationLayer.h"
using namespace std;


/* private constructor <<singleton>> */
presentationLayer::presentationLayer()
{

}

/* destructor */
presentationLayer::~presentationLayer()
{

}

/* pre: true */
/* Post: all system services are displayed */
void presentationLayer::consultServices(const httplib::Request& req, httplib::Response& res)
{
    cout << "CONSULT SERVICES" << endl;
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string commName = data["community"];
    std::string usr = data["username"];

    try{
        txConsultServices tcs(commName, usr);
        tcs.execute();
        string json = tcs.getResult();
        res.set_content(json, "text/json");
        
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "Hola" << endl;
    }
    
}



void presentationLayer::validateNeighbor(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json usuari = nlohmann::json::parse(req.body.c_str());
    std::string usr = usuari["username"];
    std::string pass = usuari["password"];
    
    txValidateNeighbor vN(usr, pass);
    vN.execute();
    res.set_content(vN.getResult().dump(), "text/json");
}

void presentationLayer::validateAdmin(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json usuari = nlohmann::json::parse(req.body.c_str());
    std::string usr = usuari["username"];
    std::string comm = usuari["community"];
    txValidateAdmin vN(usr, comm);
    vN.execute();
    res.set_content(vN.getResult().dump(), "text/json");
}

void presentationLayer::consultPendingServices(const httplib::Request& req, httplib::Response& res) 
{
    nlohmann::json usuari = nlohmann::json::parse(req.body.c_str());
    std::string usr = usuari["username"];
    std::string comm = usuari["community"];
    try{
        txConsultPendingServices tcps(comm);
        tcps.execute();
        string json = tcps.getResult();
        res.set_content(json, "text/json");
    }catch(const exception &e){
        cerr << "ERROR: " << e.what() << "\n";
    }
}

void presentationLayer::consultUserPendingServices(const httplib::Request& req, httplib::Response& res){
    cout<<  "CONSULT USER PENDING SERVICES\n";
    nlohmann::json usuari = nlohmann::json::parse(req.body.c_str());
    std::string usr = usuari["username"];
    int idCommunity = usuari["idCommunity"];
    cout << usr << endl;

    try{
        txConsultYourPendingServices tcyps(usr, idCommunity);
        tcyps.execute();
        string json = tcyps.getResult();
        res.set_content(json, "text/json");
    }catch(const exception &e){
        cerr << "ERROR: " << e.what() << "\n";
    }
}

void presentationLayer::consultUserAcceptedServices(const httplib::Request& req, httplib::Response& res)
{
    std::cout << "CONSULT USER ACCEPTED SERVICES\n";
    nlohmann::json usuari = nlohmann::json::parse(req.body.c_str());
    std::string usr = usuari["username"];
    int idCommunity = usuari["idComunity"];


    try{
        txConsultYourAcceptedServices tcyaps(usr, idCommunity);
        tcyaps.execute();
        string json = tcyaps.getResult();
        res.set_content(json, "text/json");
    }catch(const exception& e){
        cerr << "ERROR: " << e.what() << "\n";
    }
}

void presentationLayer::logNeighbor(string username, string password)
{
    txLogNeighbor tln(username,password);
    tln.execute();
}

void presentationLayer::eraseNeighbor(const httplib::Request& req, httplib::Response& res)
{
    std::cout << "ERASE NEIGHBOR\n";
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string dni = data["dni"];
    std::cout << "dni: " << dni << std::endl;
    txDeleteNeighbor tDn(dni);
    tDn.execute();


}


void presentationLayer::registerNeighbor(const httplib::Request& req, httplib::Response& res) 
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string dniN = data["dni"];
    std::string mailN = data["mail"];
    std::string nameN = data["name"];
    std::string usernameN = data["username"];
    std::string passwordN = data["password"];

    txRegisterNeighbor txRN(dniN, mailN, nameN, usernameN, passwordN, 50); 
    txRN.execute();
    
    res.set_content(txRN.getResult(), "text/json");
}

void presentationLayer::modifyNeighbor(const httplib::Request& req, httplib::Response& res) 
{
    
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string userN = data["username"];
    std::string nameN = data["name"];
    std::string passwordN = data["password"];
    
    txModifyNeighbor txMN(userN, nameN, passwordN);
    txMN.execute();
    std::cout << txMN.getResult() << std::endl;
    res.set_content(txMN.getResult(), "text/json");
}

void presentationLayer::consultService(const httplib::Request& req, httplib::Response& res) 
{
    
    unsigned int code = stoi(req.matches[1]);

    txConsultService txCS(code);
    txCS.execute(); 

    vector<passService> vps = txCS.getResult(); 

    nlohmann::json json;
    json["service"];
    nlohmann::json service;
    service["code"] = vps[0].getCode();
    service["label"] = vps[0].getLabel();
    service["price"] = vps[0].getPrice();
    service["description"] = vps[0].getDescription();
    service["name"] = vps[0].getName();
    service["duration"] = vps[0].getDuration();
    json["service"] = service;
    res.set_content(json.dump(), "text/json");
    res.status = httplib::StatusCode::OK_200;
}

void presentationLayer::consultNeighbor(const httplib::Request& req, httplib::Response& res) 
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string usr = data["username"];
    
    txConsultNeighbor tcn(usr);
    tcn.execute();
    vector<passNeighbor> vpn = tcn.getResult();

    nlohmann::json json;
    json["neighbor"];
    nlohmann::json neighbor;
    neighbor["name"] = vpn[0].getName();
    neighbor["username"] = vpn[0].getUsername();
    neighbor["mail"] = vpn[0].getMail();
    neighbor["dni"] = vpn[0].getDni();
    neighbor["tokens"] = vpn[0].getTokens();
    json["neighbor"] = neighbor;
    res.set_content(json.dump(), "text/json");
    res.status = httplib::StatusCode::OK_200;
}

void presentationLayer::consultNeighbors(const httplib::Request& req, httplib::Response& res)
{

    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string cm = data["community"];
    txConsultNeighbors tcns(cm);
    tcns.execute();
    vector<passNeighbor> vpn = tcns.getResult();
    string json = printConsultNeighborsJson(vpn);
    res.set_content(json, "text/json");
    res.status = httplib::StatusCode::OK_200;
}

void presentationLayer::filterServices(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());;
    std::string description = data["description"];
    std::string username = data["username"];
    std::string label = data["label"];
    int minVal = data["minVal"];
    int maxVal = data["maxVal"];
    int community = data["community"];
    cout << "description: " << description <<"h" <<  endl;
    try{
        txFilterServices tfs(description, label, minVal, maxVal, community, username);
        tfs.execute();
        string json = tfs.getResult();
        res.set_content(json, "text/json");
    } catch(const exception &e){
        cerr << "ERROR: " << e.what() << "\n";
    }

}

void presentationLayer::createCommunity(const httplib::Request& req, httplib::Response& res)
{

    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string usr = data["username"];
    std::string communityName = data["nom"];
    std::string communityDescription = data["descripcio"];
    txCreateCommunity txCc(usr, communityName, communityDescription);

    try{
        txCreateAdmin txca(usr);
        txca.execute();
        txCc.execute();  
    }catch(const std::string& e){
        std::cerr << e << std::endl;
    }
    std::cout << "BON DIA" << std::endl;
    std::cout << txCc.getResult() << std::endl;
    res.set_content(txCc.getResult(), "text/json");

}

void presentationLayer::deleteCommunity(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json response;
    try {
        nlohmann::json data = nlohmann::json::parse(req.body);
        string communityName = data["name"];
        string username = data["username"];

        finderNeighbor fn;
        vector <passNeighbor> neighbor= fn.findNeighborByUsername(username);
        finderCommunity fc;
        vector <passCommunity> community= fc.findCommunity(communityName);
        if (community.empty()) {
            response["success"] = false;
            response["message"] = "La comunitat no existeix";
            res.status = 404;
            res.set_content(response.dump(), "application/json");
            return;
        }

        if (neighbor.front().getDni() == community.front().getDniAdmin()) {
            txDeleteCommunity txDc(community.front().getId());
            txDc.execute();

            response["success"] = true;
            response["message"] = "Comunitat esborrada amb èxit!";
            res.status = 200;
        } else {
            response["success"] = false;
            response["message"] = "No ets l'administrador de la comunitat, la comunitat no s'esborrarà.";
            res.status = 500;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        response["success"] = false;
        response["message"] = "Invalid JSON";
        res.status = 400;
    }

    res.set_content(response.dump(), "application/json");
}

string presentationLayer::printConsultNeighborsJson(vector<passNeighbor> &res){
    nlohmann::json json;
    json["neighborsComm"];

    for (unsigned int i = 0; i < res.size(); i++){
        nlohmann::json object;
        object["dni"] = res[i].getDni();
        object["mail"] = res[i].getMail();
        object["name"] = res[i].getName();
        object["tokens"] = res[i].getTokens();
        object["username"] = res[i].getUsername();
        json["neighborsCom"].push_back(object);
    }
    
    return json.dump();
}

void presentationLayer::publishService(const httplib::Request& req, httplib::Response& res)
{
    // VERSIÓ PER COMANDES, FALTA IMPLEMENTAR FRONTEND
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string username, label, description, duration,price;
    unsigned int idcom, priceI;
    username = data["username"];
    label = data["label"];
    description = data["description"];
    price = data["price"];
    duration = data["duration"];
    idcom = data["idCommunity"];
    priceI = stoi(price);
    txPublishService tps(idcom, username, label, description, priceI, duration, "pending");
    try {
		tps.execute();
		cout << "Nou servei guardat a la bd!" << endl;;
	}
	catch (string Error) {
		if(Error == "BDErr") cerr << "No s'ha pogut publicar el servei" << endl;
	}
}

void presentationLayer::acceptService(const httplib::Request& req, httplib::Response& res)
{

    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    int codeI = data["codi"];
    int idCommunityI= data["idCommunity"];
    std::string code = std::to_string(codeI);
    std::string idCommunity = std::to_string(idCommunityI);
    txAcceptService aS(code, idCommunity);
    try {
	    aS.execute();
		nlohmann::json response;
        response["status"] = "success";
        response["message"] = "Servei modificat";
        res.set_content(response.dump(), "application/json");
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n'; 
	}
}

void presentationLayer::createAdmin()
{
    string dni;
    std::getline(std::cin,dni);
    txCreateAdmin txca(dni);
    txca.execute();
}

void presentationLayer::consultCommunities(const httplib::Request& req, httplib::Response& res)
{
    
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string usr = data["username"];
    try{
        txConsultCommunities tcc(usr);
        tcc.execute();  
        string json = tcc.getResult();
        res.set_content(json,"text/json");
    }catch(const exception &e){
        cerr << "ERROR: " << e.what() << "\n";
    }
    
}


void presentationLayer::addNeighbor(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string username = data["username"];
    std::string communityName = data["community"];
    try{
        txAddNeighbor tan(username, communityName);
        tan.execute();
    }catch(const exception&e){
        cerr << "ERROR: " << e.what() << "\n";
    }
}

void presentationLayer::takeService(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string usr = data["username"];
    //nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    int serviceCode = data["serviceCode"];
    try{
        txTakeService tts (serviceCode, usr);
        tts.execute();
    }catch(const exception &e){
        cerr << "ERROR: " << e.what() << "\n";
    }

}

void presentationLayer::exchangeService(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string usr = data["usr"];
    std::string usrExchange = data["usrExchange"];
    int codeServiceExchange = data["codeServiceExchange"];
    int codeServiceNeighbor = data["codeServiceNeighbor"];
    try{
        txTakeService tts1(codeServiceExchange, usr);
        txTakeService tts2(codeServiceNeighbor, usrExchange);
        tts1.execute();
        tts2.execute();
    }catch(const exception &e){
       cerr << "ERROR: " << e.what() << "\n";
    }
}

void presentationLayer::modifyService(const httplib::Request& req, httplib::Response& res)
{
    std::cout << "HOLA ESTEM AQUÍ" << std::endl;
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    cout << "DATAAAAAA: " << data << endl;
    std::string usr = data["username"];
    int codeS = data["code"];
    std::string labelF = data["label"];
    std::string descriptionF = data["description"];
    std::string durationF = data["duration"];
    std::string price = data["price"];   

        try {
            txModifyService tMs(to_string(codeS), usr);
            tMs.execute();
            int priceF = stoi(price);
            tMs.modify(labelF, descriptionF, priceF, durationF);
            string json = "Servei modificat";
            res.set_content(json, "text/json");
        }
    catch(const exception &err){
        cerr << "ERROR: " << err.what() << "\n";
    }
}

void presentationLayer::modifyCommunity(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string name = data["name"];
    std::string newName = data["newName"];
    std::string newDescription = data["newDescription"];
    txModifyCommunity tmc(name, newName, newDescription);
    tmc.execute();
}

void presentationLayer::declineService(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    int codeI = data["codi"];
    int idCommunityI= data["idCommunity"];
    std::string code = std::to_string(codeI);
    std::string idCommunity = std::to_string(idCommunityI);
    txDeclineService dS(code, idCommunity);
        try {
		dS.execute();
	}
	catch (string Error) {
		if(Error == "BDErr") cerr << "No s'ha pogut declinar el servei" << endl;
	}
}

void presentationLayer::addTokens(string dniN, unsigned int tokens) 
{
    txAddTokens txat;
    txat.execute(dniN, tokens); 

}

void presentationLayer::consultTasks(const httplib::Request& req, httplib::Response& res)
{
    std::cout << "CONSULT TASKS\n";
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string dni = data["dni"];
    int communityCode = data["communityCode"];

    try
    {
        txConsultTasks tCT(dni, communityCode);
        tCT.execute();
        string json = tCT.getResult();
        res.set_content(json, "text/json");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


void presentationLayer::endService(const httplib::Request& req, httplib::Response& res)
{
    std::cout<<"END SERVICE\n";
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    cout << data.dump() << endl;
    int code  = data["code"];
    string selfdni = data["username"];
    string exchangeUsername = data["exchangeUsername"];  
    cout << code << selfdni << exchangeUsername << endl;  //No podem agafar el dni desde les cookies

    try{
        txEndService tes(code, selfdni, exchangeUsername); 
        tes.execute();
    }catch(const std::exception &e){
        cerr << "ERROR: " << e.what() << "\n";
    }
}

void presentationLayer::leaveCommunity(const httplib::Request& req, httplib::Response& res)
{
    nlohmann::json data = nlohmann::json::parse(req.body.c_str());
    std::string dniUser = data["dni"];
    std::string communityName = data["community"];
    try{
        txLeaveCommunity tlc(dniUser, communityName);
        tlc.execute();
        cout << "comunitat abandonad o usuari expulsat amb èxit\n";
    }catch(const exception &e){
        cerr << "ERROR: " << e.what() << "\n";
    }
}

    
