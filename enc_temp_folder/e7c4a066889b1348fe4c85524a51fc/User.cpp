#include "User.h"
#include <fstream>
#include <sstream>
#include <vector>
User::User(std::string name, Date birthdate, std::string address, std::string phonenum, Gender gender, std::string profilePic, std::string membership, Account account)
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

    if (account.getUsername() == "") {
        return "username is required";
    }

    std::ifstream csvReader;
    std::string path = "./DB/userAndEmployeeData.csv";
    csvReader.open(path);
    std::string line = "";
    int lastReferenceNumber = 0;
    std::string csvData = "";
    if (csvReader.good()) {
        while (std::getline(csvReader, line)) {
            QString qline = QString::fromStdString(line);
            QStringList cells = qline.split(",");
            if (cells[2].toStdString() == account.getUsername()) {
                return "username exists";
            }
            if (!(cells[0].toStdString() == "referenceNumber")) {
                lastReferenceNumber = cells[0].toInt();
            }
            csvData += qline.toStdString();
            csvData += '\n';
        }
    }

    csvReader.close();

    for (char character : account.getUsername()) {
        if (character == ' ') return "invalid username";
    }

    if (account.getEmail() == "") {
        return "email is required";
    }

    bool dotExist = false;
    bool atExist = false;

    int emailIndex = 0;
    for (char character : account.getEmail()) {
        if (character == '@') atExist = true;
        if (character == '.' && atExist && emailIndex != account.getEmail().length() - 1) {
            dotExist = true;
            break;
        }
        emailIndex++;
    }
    if (!(dotExist && atExist)) {
        return "invalid email";
    }

    if (account.getPassword().length() <= 8) {
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
    csvWriter << csvData << referecode << ',' << name << ',' << account.getUsername() << ',' << account.getEmail() << ',' << account.getPassword() << ',' << account.getAccountType() << ',' << account.getIsVerified() << ',' << phonenum << ',' << gender << ',' << birthdate.getDay() << ',' << birthdate.getMonth() << ',' << birthdate.getYear() << ',' << address << ',' << profilePic << '\n';
    csvWriter.close();
    return "Done";
}

