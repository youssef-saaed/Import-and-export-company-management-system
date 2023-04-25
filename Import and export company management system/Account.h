#pragma once


class Account {

private:
    std::string username;
    std::string password;
    std::string email;
    bool isverified;
    std::string accountType;

public:
    Account(std::string const& username, std::string const& password, std::string const& email, bool const& isverified, std::string const& accountType);
    Account();

    std::string const& getUsername() const;
    bool setUsername(std::string const& username);

    std::string const& getPassword() const;
    bool setPassword(std::string const& password);

    std::string const& getEmail() const;
    bool setEmail(std::string const& email);

    bool const& getIsVerified() const;
    bool setIsVerified(bool const& isverified);

    std::string const& getAccountType() const;
    bool setAccountType(std::string const& accountType);

    void verify() const;
};