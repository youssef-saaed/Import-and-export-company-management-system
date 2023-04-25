#include "Person.h"

// Constructor
Person::Person(std::string name, Date birthdate, std::string address, int phonenum, int gender, std::string profilePic, int referecode, std::string membership, Account account)
    : name(name), birthdate(birthdate), address(address), phonenum(phonenum), gender(gender), profilePic(profilePic), referecode(referecode), membership(membership), account(account) {}

// Getters
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return birthdate.getAge();
}

Date Person::getBirthdate() const {
    return birthdate;
}

std::string Person::getAddress() const {
    return address;
}

int Person::getPhonenum() const {
    return phonenum;
}

int Person::getGender() const {
    return gender;
}

int Person::getReferecode() const {
    return referecode;
}

std::string Person::getProfilePic() const {
    return profilePic;
}

std::string Person::getMemberShip() const {
    return membership;
}

// Setters
bool Person::setName(std::string const& name) {
    if (!name.empty()) {
        this->name = name;
        return true;
    }
    return false;
}

bool Person::setBirthdate(Date const& birthdate) {
    if (birthdate.isValid()) {
        this->birthdate = birthdate;
        return true;
    }
    return false;
}

bool Person::setAddress(std::string const& address) {
    if (!address.empty()) {
        this->address = address;
        return true;
    }
    return false;
}

bool Person::setGender(int const& gender) {
    if (gender == 0 || gender == 1) {
        this->gender = gender;
        return true;
    }
    return false;
}

bool Person::setReferecode(int const& referecode) {
    if (referecode >= 0) {
        this->referecode = referecode;
        return true;
    }
    return false;
}

bool Person::setProfilePic(std::string const& profilePic) {
    if (!profilePic.empty()) {
        this->profilePic = profilePic;
        return true;
    }
    return false;
}

bool Person::setMemberShip(std::string const& membership) {
    if (!membership.empty()) {
        this->membership = membership;
        return true;
    }
    return false;
}
