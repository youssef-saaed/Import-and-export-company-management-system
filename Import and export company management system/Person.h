#pragma once

#include <string>
#include "Date.h"
#include "Account.h"

class Account;

enum Gender{Male,Female,None};

class Person {

protected:
    std::string name;
    std::string phonenum;
    Gender gender;
    Date birthdate;
    std::string address;
    std::string profilePic;
    int referecode;
public:
    Account* account;
    Person();
    Person(std::string name, Date birthdate, std::string address, std::string phonenum, Gender gender, std::string profilePic, Account* account);
    virtual ~Person();

    std::string getName() const;
    bool setName(const std::string& name);

    std::string getPhonenum() const;
    bool setPhonenum(const std::string& phonenum);

    Gender getGender() const;
    bool setGender(Gender const& gender);

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

    int getReferecode() const;
    bool setReferecode(int const& referecode);

    virtual void viewInfo() const = 0;
    virtual void delete_account() const = 0;
    virtual void getData(Account) const = 0;
};
