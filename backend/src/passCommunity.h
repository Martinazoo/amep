#ifndef PASS_COMMUNITY_H
#define PASS_COMMUNITY_H
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

class passCommunity{
    private:
        int _id;
        string _dniAdmin;
        string _name;
        string _description;
        tm _creationDate;
        int _memberCount;
    
    public:
        passCommunity();
        passCommunity(int id, string name, string description, tm creationDate, int memberCount, string dniAdmin);
        passCommunity(string name, string description, string dniAdmin);
        ~passCommunity();

        void insert();
        void modify();
        void erase();
        void addMember();

        void setId(int id);
        void setName(string name);
        void setDescription(string description);
        void setMemberCount(int memberCount);
        void setCreationDate(string date);
        void setDniAdmin(string dniAdmin);

        int getId();
        string getName();
        string getDescription();
        tm getCreationDate();
        int getMemberCount();
        string getDniAdmin();
};

#endif