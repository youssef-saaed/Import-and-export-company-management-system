#pragma once

#include <string>
#include "Date.h"
#include "Account.h"

class Person {

protected:
    std::string name;
    std::string phonenum;
    int gender;
    Date birthdate;
    std::string address;
    std::string profilePic;
    std::string membership;
    int referecode;

public:
    Account account;
    Person();
    Person(std::string name, Date birthdate, std::string address, std::string phonenum, int gender, std::string profilePic, int referecode, std::string membership, Account account);
    virtual ~Person();

    std::string getName() const;
    bool setName(const std::string& name);

    std::string getPhonenum() const;
    bool setPhonenum(const std::string& phonenum);

    int getGender() const;
    bool setGender(int const& gender);

    int getAge() const;
    Date getBirthdate() const;
    bool setBirthdate(Date const& birthdate)
    {
        if (birthdate.isValid()) {
            this->birthdate = birthdate;
            return true;
        }
        return false;
    }

    std::string getAddress() const;
    bool setAddress(std::string const& address);

    std::string getProfilePic() const;
    bool setProfilePic(std::string const& profilePic);

    std::string getMembership() const;
    bool setMembership(std::string const& membership);

    int getReferecode() const;
    bool setReferecode(int const& referecode);

    virtual void viewInfo() const = 0;
    virtual void delete_account() const = 0;
};
