
#include "Account.h"
#include <string>

Account::Account(std::string const& username, std::string const& password, std::string const& email, bool const& isverified,
    std::string const& accountType) {
    Account::username = username;
    Account::password = password;
    Account::email = email;
    Account::isverified = isverified;
    Account::accountType = accountType;
}

Account::Account()
{
    username = "";
    password = "";
    email = "";
    isverified = false;
    accountType = "";
}

std::string const& Account::getUsername() const
{
    return username;
}

bool Account::setUsername(std::string const& username)
{
    Account::username = username;
    return true;
}

std::string const& Account::getPassword() const
{
    return password;
}

bool Account::setPassword(std::string const& password)
{
    Account::password = password;
    return true;
}

std::string const& Account::getEmail() const
{
    return email;
}

bool Account::setEmail(std::string const& email)
{
    Account::email = email;
    return true;
}

bool const& Account::getIsVerified() const
{
    return isverified;
}

bool Account::setIsVerified(bool const& isverified)
{
    Account::isverified = isverified;
    return true;
}

std::string const& Account::getAccountType() const
{
    return accountType;
}

bool Account::setAccountType(std::string const& accountType)
{
    Account::accountType = accountType;
    return true;
}

void Account::verify() const {

}
