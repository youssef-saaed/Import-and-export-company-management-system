#pragma once
#include "Cart.h"
#include "Order.h"
#include "Person.h"
class Order;
class User : public Person {

private:
    double Ubalance;
    Cart* userCart;
    Order* pastOrders;
    std::string membership;

public:
    User();
    
    User(std::string name, Date birthdate, std::string address, std::string phonenum, Gender gender, std::string profilePic, std::string membership, Account account);

    double getBalance() const;
    bool setBalance(const double& Ubalance);

    void viewProfile() const;

    void view_P_history() const;

    void change_Password() const;

    void viewInfo() const;

    void delete_account() const;

    std::string getMembership() const;
    bool setMembership(std::string const& membership);

    std::string Register();
};