#include "requests.h"

string const WEBSITE_RELATIVE_PATH = "../Website";

void requests::montserrat_ttf(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/fonts/Montserrat.ttf");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "font/ttf");
}

void requests::services_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/services.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::pallette_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH  + "/css/pallette.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::login_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/login.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::login_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/login.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::deleteNeighbor_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/deleteNeighbor.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::deleteNeighbor_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/deleteNeighbor.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}


void requests::userDeleted_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/userDeleted.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::userDeleted_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/userDeleted.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::services_html(const httplib::Request& req, httplib::Response& res)
{
    //Cargar l'archiu index.html (que es el archiu demanat per el client) a la memoria principal
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/community/services.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    //actualitzar la resposta del servidor per a que retorni larxiu, el segon parametre es el format del text en aquest cas un HTML
    res.set_content(content, "text/html");
    
}

void requests::swarvice_img(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/img/swarvice.png");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "image/png");
}

void requests::register_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/register.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::register_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/register.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::publishService_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/publishService.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::publishService_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/publishService.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::service_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/service.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::service_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/service.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::createCommunity_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/createCommunity.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}
void requests::createCommunity_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/createCommunity.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}
void requests::deleteCommunity_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/consultCommunities.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}
void requests::deleteCommunity_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/consultCommunites.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}
void requests::consultCommunities_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/consultCommunities.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::consultCommunities_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/consultCommunities.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::profileMenu_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/profileMenu.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::profileMenu_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/profileMenu.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::cookies_js(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/js/cookies.js");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "application/javascript");
}

void requests::admin_html(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/community/admin.html");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/html");
}

void requests::admin_css(const httplib::Request& req, httplib::Response& res)
{
    std::ifstream file(WEBSITE_RELATIVE_PATH + "/css/admin.css");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    res.set_content(content, "text/css");
}

void requests::requestAll(httplib::Server &svr)
{
    presentationLayer & pre = presentationLayer::getInstance();
    requests& req = requests::getInstance();

    //svr.set_base_dir(BASE_DIR_PATH)       Path a todos los archivos publicos
    // Define el resto de lambdas para otras rutas...
    //Per a la petició GET amb pattern "/"(localhost:8085/) el servidor executarà la funcio "index_html" 
    //Per a la petició GET amb pattern "/index.html"(localhost:8085/index.html) el servidor executarà la funcio "index_html" 
    svr.Get("/", req.login_html);
    svr.Get("/community/services", req.services_html);
    svr.Get("/css/services.css", req.services_css);
    svr.Get("/css/pallette.css", req.pallette_css);
    svr.Get("/fonts/Montserrat.ttf", req.montserrat_ttf);   
    svr.Get("/img/swarvice.png", req.swarvice_img);
    svr.Get("/css/login.css", req.login_css);
    svr.Get("/login.html", req.login_html); 
    svr.Get("/css/deleteNeighbor.css", req.deleteNeighbor_css);
    svr.Get("/deleteNeighbor", req.deleteNeighbor_html);
    svr.Get("/css/userDeleted.css", req.userDeleted_css);
    svr.Get("/userDeleted.html", req.userDeleted_html);
    svr.Get("/css/register.css", req.register_css);  
    svr.Get("/register",req.register_html); 
    svr.Get("/css/publishService.css", req.publishService_css);
    svr.Get("/publishService", req.publishService_html);
    svr.Get("/service", req.service_html);
    svr.Get("/css/service.css", req.service_css);
    svr.Get("/css/consultCommunities.css", req.consultCommunities_css);
    svr.Get("/consultCommunities.html", req.consultCommunities_html);
    svr.Get("/css/createCommunity.css", req.createCommunity_css);
    svr.Get("/createCommunity.html", req.createCommunity_html);
    svr.Get(R"(/consultService/(\d+))", presentationLayer::consultService);
    svr.Get("/profileMenu.html", req.profileMenu_html);
    svr.Get("/css/profileMenu.css", req.profileMenu_css);
    svr.Get("/js/cookies.js", req.cookies_js);
    svr.Get("/community/admin", req.admin_html);
    svr.Get("/css/admin.css", req.admin_css);

    svr.Post("/modifyCommunity", pre.modifyCommunity);
    svr.Post("/ModifyNeighbor", pre.modifyNeighbor);

    svr.Post("/ConsultServices.json", pre.consultServices);
    svr.Post("/ConsultCommunities.json", pre.consultCommunities);
    svr.Post("/ConsultPendingServices.json", pre.consultPendingServices);
    svr.Post("/ConsultTasks.json", pre.consultTasks);

    
    svr.Post("/loginvalidation.json", presentationLayer::validateNeighbor);
    svr.Post("/createCommunity", presentationLayer::createCommunity);
    svr.Post("/registerNeighbor.json", presentationLayer::registerNeighbor);
    //svr.Post("/takeService", presentationLayer::takeService);
    //svr.Post("/exchangeService", presentationLayer::exchangeService);
    svr.Post("/deleteCommunity", presentationLayer::deleteCommunity);
    svr.Post("/ValidateAdmin.js", presentationLayer::validateAdmin);
    svr.Post("/AcceptarServei.json", pre.acceptService);
    svr.Post("/PublicarServei.json",pre.publishService);
    svr.Post("/RebutjarServei.json",pre.declineService);
    svr.Post("/leaveCommunity.json",pre.leaveCommunity);
    
    svr.Post("/ValidateAdmin.json",pre.validateAdmin);
    svr.Post("/AddNeighbor.json",pre.addNeighbor);
    
    svr.Post("/consultNeighbors.json",pre.consultNeighbors);

    svr.Post("/FilterServices.json",pre.filterServices);


    svr.Post("/DeleteCommunity.json",pre.deleteCommunity);
    svr.Post("/TakeService.json",pre.takeService);
    svr.Post("/ExchangeService.json",pre.exchangeService);
    svr.Post("/ConsultTasks.json",pre.consultTasks);
    svr.Post("/ConsultUserAcceptedServices.json",pre.consultUserAcceptedServices);
     svr.Post("/ConsultUserPendingServices.json",pre.consultUserPendingServices);
    svr.Post("/EraseNeighbor.json",pre.eraseNeighbor);
    svr.Post("/EndService.json",pre.endService);
}