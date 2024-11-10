#ifndef PASS_SERVICE_H
#define PASS_SERVICE_H
#include <iostream>
#include <ctime>
#include <string>
#include "connection.h"
using namespace std;

class passService {
    private:
        unsigned int _code;
        unsigned int _idCommunity;
        string _username;
        string _label;
        string _description;
        unsigned int _price;
        string _duration;
        string _statusService;

    public:

        passService();
        //passService(unsigned int code, string name, string label, string description, unsigned int price, string duration, string statusService);
        passService(unsigned int code, unsigned int idCommunity, string name, string label, string description, unsigned int price, string duration, string statusService);
        passService(unsigned int code);
        passService(unsigned int id_community, string username, string label, string description, int price, string duration, string status);
        
        passService(const passService& pService);
        ~passService();

        void insert();

        void setCode(unsigned int code);
        void setIdCommunity(unsigned int idCommunity);
        void setUsername(string username);
        void setLabel(string label);
        void setDescription(string description);
        void setPrice(unsigned int price);
        void setDuration(string duration);
        void setStatusService(string statusService);
        void modifyService(string label, string description, unsigned int price, string duration);

        unsigned int getCode() const;
        unsigned int getIdCommunity() const;
        string getName() const;
        string getLabel() const;
        string getDescription() const;
        unsigned int getPrice() const;
        string getDuration() const;
        string getStatusService() const;

};

#endif
