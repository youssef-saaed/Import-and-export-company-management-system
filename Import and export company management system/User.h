#pragma once
#include "Cart.h"
#include "Order.h"
#include "Person.h"

class User : public Person {

private:
    double Ubalance;
    Cart* userCart;
    Order* pastOrders;

public:
    User();
    
    User(std::string name, Date birthdate, std::string address, std::string phonenum, int gender, std::string profilePic, int referecode, std::string membership, Account account, double Ubalance, Cart* userCart, Order* pastOrders);

    double getBalance() const;
    bool setBalance(const double& Ubalance);

    void viewProfile() const;

    void view_P_history() const;

    void change_Password() const;

    void viewInfo() const;

    void delete_account() const;
};