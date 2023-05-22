#include "User.h"


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

void User::getData() const
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

void User::importData()
{
    std::ifstream csvReader;
    csvReader.open("./DB/user.csv");
    std::string line;
    while (std::getline(csvReader, line)) {
        QStringList row = QString::fromStdString(line).split(",");
        if (row[0].toInt() == referecode) {
            setBalance(row[1].toDouble());
            setMembership(row[4].trimmed().toStdString());

        }
    }
    csvReader.close();
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

    std::regex phoneNumberPattern("^\\d{11}");
    if (!std::regex_match(phonenum, phoneNumberPattern)) {
        return "invalid phone " ;
    }

    if (address == "") {
        return "address is required";
    }

    std::regex addressPattern("^[^,]+$");
    if (!std::regex_match(address, addressPattern)) {
        return "address should not contain commas (,)";
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
    QDir carts(QString::fromStdString("DB/"+account->getUsername() + "/carts"));
    carts.mkpath(".");
    std::string firstCart = "./DB/" + account->getUsername() + "/carts/cart0.csv";
    Ubalance = 0.;
    std::ofstream cartCsv(firstCart,std::ios::out);
    cartCsv << "number,name,quantity,price,shipment type\n";
    cartCsv.close();
    csvWriter.open(path);
    csvWriter << csvData << referecode << ',' << Ubalance << ',' << ',' << firstCart << ',' << membership << '\n';
    csvWriter.close();
    return "Done";
}


void User::updateBalance()
{
    std::ifstream csvReader;
    csvReader.open("./DB/user.csv");
    std::string line,output;
    std::getline(csvReader, line);
    output = line + '\n';
    while (getline(csvReader, line)) {
        QStringList row = QString::fromStdString(line).split(",");
        if (referecode == row[0].toInt()) {
            row[1] = QString::fromStdString(std::to_string(Ubalance));
        }
        output += row[0].toStdString() + ',' + row[1].toStdString() + ',' + row[2].toStdString() + ',' + row[3].toStdString() + ',' + row[4].toStdString() + '\n';
    }
    csvReader.close();

    std::ofstream csvWriter("./DB/user.csv");
    csvWriter << output;
    csvWriter.close();
}
