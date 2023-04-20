#pragma once
#include <string>
#include "Date.h"
#include "Account.h"

class Person {
protected:
    std::string name;
    Date birthdate;
    std::string address;
    int phonenum;
    int gender;
    std::string profilePic;
    int referecode;
    std::string membership;
    Account account;

public:
    Person(std::string name, Date birthdate, std::string address, int phonenum, int gender, std::string profilePic, int referecode, std::string membership, Account account);
    virtual ~Person() {};
    std::string getName() const;
    bool setName(std::string const& name);
    int getAge() const;
    Date getBirthdate() const;
    bool setBirthdate(Date const& birthdate);
    std::string getAddress() const;
    bool setAddress(std::string const& address);
    int getPhonenum() const;
    int getGender() const;
    bool setGender(int const& gender);
    int getReferecode() const;
    bool setReferecode(int const& referecode);
    std::string getProfilePic() const;
    bool setProfilePic(std::string const& profilePic);
    std::string getMemberShip() const;
    bool setMemberShip(std::string const& membership);
    virtual void viewInfo() const = 0;
    virtual void delete_account() const = 0;
};
