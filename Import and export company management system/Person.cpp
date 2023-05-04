#include "Person.h"

Person::Person(std::string name, Date birthdate, std::string address, std::string phonenum, int gender, std::string profilePic, int referecode, std::string membership, Account account)
    : name(name), birthdate(birthdate), address(address), phonenum(phonenum), gender(gender), profilePic(profilePic), referecode(referecode), membership(membership), account(account) {}

Person::~Person()
{
}

std::string Person::getName() const
{
    return name;
}

bool Person::setName(const std::string& name)
{
    if (!name.empty())
    {
        this->name = name;
        return true;
    }
    return false;
}


Date Person::getBirthdate() const
{
    return birthdate;
}

int Person::getAge() const
{
    return birthdate.getAge();
}


std::string Person::getAddress() const
{
    return address;
}

bool Person::setAddress(std::string const& address)
{
    if (!address.empty()) {
        this->address = address;
        return true;
    }
    return false;
}


std::string Person::getPhonenum() const
{
    return phonenum;
}

bool Person::setPhonenum(const std::string& phonenum)
{
    if (!phonenum.empty()) {
        this->phonenum = phonenum;
        return true;
    }
    return false;
}


int Person::getGender() const
{
    return gender;
}

bool Person::setGender(int const& gender)
{
    if (gender == 0 || gender == 1) {
        this->gender = gender;
        return true;
    }
    return false;
}


int Person::getReferecode() const
{
    return referecode;
}

bool Person::setReferecode(int const& referecode)
{
    if (referecode >= 0)
    {
        this->referecode = referecode;
        return true;
    }
    return false;
}


std::string Person::getProfilePic() const
{
    return profilePic;
}

bool Person::setProfilePic(std::string const& profilePic)
{
    if (!profilePic.empty())
    {
        this->profilePic = profilePic;
        return true;
    }
    return false;
}

std::string Person::getMembership() const
{
    return membership;
}
bool Person::setMembership(std::string const& membership)
{
    if (!membership.empty())
    {
        this->membership = membership;
        return true;
    }
    return false;
}










