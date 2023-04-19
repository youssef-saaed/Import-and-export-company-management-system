#pragma once

#include "Date.h"
#include "Account.h"

class Person {
private:
    string name;
    Date birthdate;
    string address;
    int phonenum;
    int gender;
    string profilePic;
    int referecode;
    string membership;
    Account account;

public:
    Person();

    string getName();
    void setName(string name);

    int getAge();
    Date getBirthdate();
    void setBirthdate(Date birthdate);

    string getAddress();
    void setAddress(string address);

    int getPhonenum();

    int getGender();
    void setGender(int gender);

    int getReferecode();
    void setReferecode(int referecode);

    string getProfilePic();
    void setProfilePic(string profilePic);

    string getMemberShip();
    void setMemberShip(string membership);

    void viewInfo();
    void delete_account();
};


#ndif //IMPORT_AND_EXPORT_COMPANY_MANAGEMENT_SYSTEM_PERSON_H
