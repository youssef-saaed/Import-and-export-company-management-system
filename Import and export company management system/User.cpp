#include "User.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

User::User(std::string name, Date birthdate, std::string address, std::string phonenum, Gender gender, std::string profilePic, std::string membership, Account* account)
    : Person(name, birthdate, address, phonenum, gender, profilePic, account),membership(membership) {}

User::User() {}

double User::getBalance() const
{
    return Ubalance;
}

bool User::setBalance(const double& Ubalance)
{
    this->Ubalance = Ubalance;
    return true;
}

void User::viewInfo() const
{
}

void User::delete_account() const
{
}

void User::getData(Account) const
{
}

std::string User::getMembership() const
{
    return membership;
}
bool User::setMembership(std::string const& membership)
{
    if (!membership.empty())
    {
        this->membership = membership;
        return true;
    }
    return false;
}

std::string User::Register()
{
    if (name == "") {
        return "name must be filled";
    }
    
    std::regex namePattern("[A-Za-z\\s]+");
    if (!std::regex_match(name, namePattern)) {
        return "letters and space are only allowed in name";
    }

    if (account->getUsername() == "") {
        return "username is required";
    }

    std::regex userPattern("(\\w+)");
    if (!std::regex_match(account->getUsername(), userPattern)) return "letters,numbers,underscore are only allowed in username";

    std::ifstream csvReader;
    std::string path = "./DB/userAndEmployeeData.csv";
    csvReader.open(path);
    std::string line = "";
    int lastReferenceNumber = 0;
    std::string csvData = "";
    while (std::getline(csvReader, line)) {
        QString qline = QString::fromStdString(line);
        QStringList cells = qline.split(",");
        if (cells[2].toStdString() == account->getUsername()) {
            return "username exists";
        }
        if (!(cells[0].toStdString() == "referenceNumber")) {
            lastReferenceNumber = cells[0].toInt();
        }
        csvData += qline.toStdString();
        csvData += '\n';
    }

    csvReader.close();

    if (account->getEmail() == "") {
        return "email is required";
    }

  
    std::regex emailPattern("(\\w+)((\\.|_|-)(\\w|\\w+))?@(\\w+)(\\.(\\w+))+");
    bool mailIsValid = std::regex_match(account->getEmail(), emailPattern);
    if (!mailIsValid) {
        return "invalid email";
    }

    if (account->getPassword().length() <= 8) {
        return "password must be more than 8 characters";
    }
    if (phonenum == "") {
        return "Phone Number is required";
    }

    for (char digit : phonenum) {
        if (digit < '0' || digit > '9') return "invalid phone number";
    }

    if (address == "") {
        return "address is required";
    }
    if (!birthdate.isValid()) {
        return "enter a valid date";
    }

    if (gender == None) {
        return "you didn't choose gender";
    }
    if (profilePic == "" or profilePic[profilePic.length() - 1] == '/') {
        return "picture is required";
    }

    this->setReferecode(lastReferenceNumber + 1);

    std::ofstream csvWriter;
    csvWriter.open(path);
    csvWriter << csvData << referecode << ',' << name << ',' << account->getUsername() << ',' << account->getEmail() << ',' << account->getPassword() << ',' << account->getAccountType() << ',' << account->getIsVerified() << ',' << phonenum << ',' << gender << ',' << birthdate.getDay() << ',' << birthdate.getMonth() << ',' << birthdate.getYear() << ',' << address << ',' << profilePic << '\n';
    csvWriter.close();

    path = "./DB/user.csv";
    csvData = "";
    csvReader.open(path);
    while (std::getline(csvReader, line)) {
        csvData += line + '\n';
    }
    csvWriter.open(path);
    csvWriter << csvData << referecode << ',' << 0 << ',' << ',' << ',' << membership << '\n';
    csvWriter.close();
    return "Done";
}

std::string User::Login()
{
    if (account->getUsername() == "")
    {
        return "username is required";
    }
    if (account->getPassword() == "") 
    {
        return "password is required";
    }

    std::ifstream csvReader;
    std::string path = "./DB/userAndEmployeeData.csv";
    csvReader.open(path);
    std::string line = "";
    bool found = false;
    QStringList cells;
    if (csvReader.good())
    {
        while (std::getline(csvReader, line))
        {
            QString qline = QString::fromStdString(line);
            cells = qline.split(",");
            if (cells[2].toStdString() == account->getUsername() && cells[4].toStdString() == account->getPassword()) 
            {
                found = true;
                referecode = cells[0].toInt();
                break;
            }
        }
    }

    csvReader.close();

    if (found) {
        return cells[2].toStdString();
    }
    else {
        return "Invalid username or password";
    }
}