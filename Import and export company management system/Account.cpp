#include "Account.h"

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
    this->username = username;
    return true;
}

std::string const& Account::getPassword() const
{
    return password;
}

bool Account::setPassword(std::string const& password)
{
    this->password = password;
    return true;
}

std::string const& Account::getEmail() const
{
    return email;
}

bool Account::setEmail(std::string const& email)
{
    this->email = email;
    return true;
}

bool const& Account::getIsVerified() const
{
    return isverified;
}

bool Account::setIsVerified(bool const& isverified)
{
    this->isverified = isverified;
    return true;
}

User Account::checkCredentials()
    {
        std::ifstream handler("userAndEmployeeData.csv");
        std::string line;
        while (std::getline(handler, line))
        {
            QString qline = QString::fromStdString(line);

            QStringList columns = qline.split(",");
            if (columns[2].toStdString() == username && columns[4].toStdString() == password)
            {
                accountType = columns[5].toStdString();
                User x;
                return x;
            }
        }
        handler.close();
    }

std::string const& Account::getAccountType() const
{
    return accountType;
}

bool Account::setAccountType(std::string const& accountType)
{
    this->accountType = accountType;
    return true;
}

void Account::verify() const {

}
