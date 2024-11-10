#ifndef REQUESTS_H
#define REQUESTS_H
#include <iostream>
#include <ctime>
#include <string>
#include "httplib.h"
#include "presentationLayer.h"

using namespace std;

class requests{
    public:
        static requests& getInstance(){
            static requests instance;
            return instance;
        }   
        static void montserrat_ttf(const httplib::Request& req, httplib::Response& res);
        static void services_css(const httplib::Request& req, httplib::Response& res);
        static void pallette_css(const httplib::Request& req, httplib::Response& res);
        static void login_html(const httplib::Request& req, httplib::Response& res);
        static void login_css(const httplib::Request& req, httplib::Response& res);
        static void deleteNeighbor_html(const httplib::Request& req, httplib::Response& res);
        static void deleteNeighbor_css(const httplib::Request& req, httplib::Response& res);
        static void userDeleted_html(const httplib::Request& req, httplib::Response& res);
        static void userDeleted_css(const httplib::Request& req, httplib::Response& res);
        static void services_html(const httplib::Request& req, httplib::Response& res);
        static void swarvice_img(const httplib::Request& req, httplib::Response& res);
        static void register_html(const httplib::Request& req, httplib::Response& res);
        static void register_css(const httplib::Request& req, httplib::Response& res);
        static void publishService_html(const httplib::Request& req, httplib::Response& res);
        static void publishService_css(const httplib::Request& req, httplib::Response& res);
        static void service_html(const httplib::Request& req, httplib::Response& res);
        static void service_css(const httplib::Request& req, httplib::Response& res);
        static void createCommunity_html(const httplib::Request& req, httplib::Response& res);
        static void createCommunity_css(const httplib::Request& req, httplib::Response& res);
        static void deleteCommunity_html(const httplib::Request& req, httplib::Response& res);
        static void deleteCommunity_css(const httplib::Request& req, httplib::Response& res);
        static void consultCommunities_html(const httplib::Request& req, httplib::Response& res);
        static void consultCommunities_css(const httplib::Request& req, httplib::Response& res);
        static void profileMenu_html(const httplib::Request& req, httplib::Response& res);
        static void profileMenu_css(const httplib::Request& req, httplib::Response& res);
        static void cookies_js(const httplib::Request& req, httplib::Response& res);
        static void admin_css(const httplib::Request& req, httplib::Response& res);
        static void admin_html(const httplib::Request& req, httplib::Response& res);


        void requestAll(httplib::Server &svr);
        
};

#endif
