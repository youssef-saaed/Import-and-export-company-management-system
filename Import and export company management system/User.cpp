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
        return "username is empty, please enter a username";
    }

    if (account.getEmail() == "") {
        return "email is empty, please enter an email";
    }
    if (phonenum == "") {
        return "Phone Number is empty, please enter a Phone Number";
    }
    if (address == "") {
        return "address is empty, please enter an address";
    }


    std::ifstream handler;
    std::string path = "youssef-saaed\\Import-and-export-company-management-system\\Import and export company management system\\DB\\userAndEmployeeData.csv";
    handler.open(path);
    std::string line = "";


    if (handler) {
        bool all_data_found = true;
        int row_count = 0;
        bool data_found;
        while (std::getline(handler, line)) {
            row_count++;

            std::vector <std::string> data;
            std::string user;
            std::istringstream ss(line);
            while (std::getline(ss, user, ',')) {
                data.push_back(user);
            }

            std::string username = account.getUsername();
            std::string email = account.getEmail();
            std::string password = account.getPassword();
            std::string phoneNumber = phonenum;

            std::vector<std::pair<std::string, std::string>> required_data = {
               {"name", name},
               {"username", username},
               {"email", email},
               {"password", password},
               {"phonenumber", phoneNumber},
               {"address", address}
            };
            for (auto required : required_data) {
                bool exists = false;
                for (size_t i = 0; i < data.size(); i++) {
                    if (data[i] == required.second) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    std::cout << "Data '" << required.first << "' missing in row " << row_count << std::endl;
                    all_data_found = false;
                    data_found = false;
                }
            }

            if (data_found) {
                std::cout << "All required data found in row " << row_count << std::endl;
            }
        }

        if (all_data_found) {
            std::cout << "All required data found in all rows!" << std::endl;
        }
    }
    else {
        std::cout << "File not found: " << path << std::endl;
    }


        return std::string();
    }
}
