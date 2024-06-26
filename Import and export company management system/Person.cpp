#include "Person.h"

Person::Person()
{
}

Person::Person(std::string name, Date birthdate, std::string address, std::string phonenum, Gender gender, std::string profilePic, Account* account)
    : name(name), birthdate(birthdate), address(address), phonenum(phonenum), gender(gender), profilePic(profilePic), account(account) {}

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


Gender Person::getGender() const
{
    return gender;
}

bool Person::setGender(Gender const& gender)
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

std::string Person::Login()
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
    
    if (csvReader.good())
    {
        while (std::getline(csvReader, line))
        {
            QString qline = QString::fromStdString(line);
            QStringList cells = qline.split(",");
            if (cells[2].toStdString() == account->getUsername() && cells[4].toStdString() == account->getPassword())
            {
                found = true;
                referecode = cells[0].toInt();
                name = cells[1].toStdString();
                account->setEmail(cells[3].toStdString());
                account->setAccountType(cells[5].toStdString());
                account->setIsVerified(cells[6].toInt());
                phonenum = cells[7].toStdString();
                gender = static_cast<Gender>(cells[8].toInt());
                birthdate.setDay(cells[9].toInt());
                birthdate.setMonth(cells[10].toInt());
                birthdate.setYear(cells[11].toInt());
                address = cells[12].toStdString();
                profilePic = cells[13].toStdString();
                break;
            }
        }
    }

    csvReader.close();

    if (found) {
        importData();
        return account->getAccountType();
    }
    else {
        return "Invalid username or password";
    }
}










