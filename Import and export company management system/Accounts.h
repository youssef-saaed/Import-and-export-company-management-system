#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>

class Accounts {
private:
    std::string username;
    std::string password;
    std::string email;
    bool isverified;
    std::string accountType;

public:
    
    Accounts(std::string const& username, std::string const& password, std::string const& email, bool const& isverified, std::string const& accountType);

    std::string const& getUsername() const;
    void setUsername(std::string const& username);

    std::string const& getPassword() const;
    void setPassword(std::string const& password);

    std::string const& getEmail() const;
    void setEmail(std::string const& email);

    bool const& getIsVerified() const;
    void setIsVerified(bool const& isverified);

    std::string const& getAccountType() const;
    void setAccountType(std::string const& accountType);

    void verify() const;
};

#endif // ACCOUNTS_H
