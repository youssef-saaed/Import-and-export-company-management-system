#pragma once
#include <string>
#include "Date.h"
#include "Account.h"

class Person {
private:
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


    std::string getName() const;
    void setName(std::string const& name);

    int getAge() const;
    Date getBirthdate() const;
    void setBirthdate(Date const& birthdate);

    std::string getAddress() const;
    void setAddress(std::string const& address);

    int getPhonenum() const;

    int getGender() const;
    void setGender(int const& gender);

    int getReferecode() const;
    void setReferecode(int const& referecode);

    std::string getProfilePic() const;
    void setProfilePic(std::string const& profilePic);

    std::string getMemberShip() const;
    void setMemberShip(std::string const& membership);

    void viewInfo() const;
    void delete_account() const;
};

#endif //IMPORT_AND_EXPORT_COMPANY_MANAGEMENT_SYSTEM_PERSON_H
