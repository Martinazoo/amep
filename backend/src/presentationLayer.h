#ifndef PRESENTATION_LAYER_H
#define PRESENTATION_LAYER_H

#include <iostream>
#include <vector>

#include "connection.h"
#include "finderAdmin.h"
#include "finderCommunity.h"
#include "finderNeighbor.h"
#include "finderPendingService.h"
#include "finderService.h"
#include "finderAccepted.h"
#include "finderUserPendingServices.h"
#include "finderUserAcceptedServices.h"
#include "passAdmin.h"
#include "passCommunity.h"
#include "passNeighbor.h"
#include "passService.h"
#include "passAcceptService.h"
#include "requests.h"
#include "txConsultPendingServices.h"
#include "txConsultService.h"
#include "txConsultYourPendingServices.h"
#include "txConsultYourAcceptedServices.h"
#include "txConsultServices.h"
#include "txCreateAdmin.h"
#include "txCreateCommunity.h"
#include "txDeleteCommunity.h"
#include "txDeleteNeighbor.h"
#include "txLogNeighbor.h"
#include "txPublishService.h"
#include "txRegisterNeighbor.h"
#include "txValidateNeighbor.h"
#include "txAcceptService.h"
#include "txDeclineService.h"
#include "txConsultCommunities.h"
#include "txTakeService.h"
#include "txAddNeighbor.h"
#include "txConsultNeighbor.h"
#include "txConsultNeighbors.h"
#include "txValidateAdmin.h"
#include "txModifyNeighbor.h"
#include "txLeaveCommunity.h"
#include "txAddTokens.h"
#include "txFilterServices.h"

#include "txEndService.h"
#include "nlohmann/json.hpp"
#include "txAddNeighbor.h"
#include "txConsultTasks.h"
#include "txModifyCommunity.h"

#include "txModifyService.h"
#include "httplib.h"

using namespace std;

class presentationLayer{
    private:
        presentationLayer();
    public:
        static presentationLayer& getInstance(){
            static presentationLayer instance;
            return instance;
        }   

        ~presentationLayer();
        
        static void validateNeighbor(const httplib::Request& req, httplib::Response& res);
        static void logNeighbor(string username, string password);
        static void eraseNeighbor(const httplib::Request& req, httplib::Response& res);
        static void publishService(const httplib::Request& req, httplib::Response& res);
        static void registerNeighbor(const httplib::Request& req, httplib::Response& res);
        static void modifyNeighbor(const httplib::Request& req, httplib::Response& res);
        static void consultService(const httplib::Request& req, httplib::Response& res);
        static void consultNeighbor(const httplib::Request& req, httplib::Response& res);
        static void consultNeighbors(const httplib::Request& req, httplib::Response& res);
        static string printConsultNeighborsJson(vector<passNeighbor> &res);
        static void createCommunity(const httplib::Request& req, httplib::Response& res);
        static void validateAdmin(const httplib::Request& req, httplib::Response& res);
        static void leaveCommunity(const httplib::Request& req, httplib::Response& res);
        static void filterServices(const httplib::Request& req, httplib::Response& res);


        static void deleteCommunity(const httplib::Request& req, httplib::Response& res);
        static void createAdmin();
        static void addNeighbor(const httplib::Request& req, httplib::Response& res);
        static void consultTasks(const httplib::Request& req, httplib::Response& res);


        static void consultServices(const httplib::Request& req, httplib::Response& res);
        static void consultCommunities(const httplib::Request& req, httplib::Response& res); 
        static void consultPendingServices(const httplib::Request& req, httplib::Response& res);
        static void consultUserPendingServices(const httplib::Request& req, httplib::Response& res);
        static void consultUserAcceptedServices(const httplib::Request& req, httplib::Response& res);
        
        static void printConsultServices(vector<passService> &res);
        static string printConsultServicesJson(vector<passService> &res);   //returns json
        
        static void printConsultPendingServices(string username);
        static void acceptService(const httplib::Request& req, httplib::Response& res);

        //static void takeService();

        static void modifyService(const httplib::Request& req, httplib::Response& res);
        static void modifyCommunity(const httplib::Request& req, httplib::Response& res);
        static void declineService(const httplib::Request& req, httplib::Response& res);

        static void takeService(const httplib::Request& req, httplib::Response& res);
        static void exchangeService(const httplib::Request& req, httplib::Response& res);

        static void addTokens(string dniN, unsigned int tokens);

        

        static void endService(const httplib::Request& req, httplib::Response& res);
};

#endif
