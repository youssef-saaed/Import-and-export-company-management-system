#include "User.h"


User::User(std::string name, Date birthdate, std::string address, int phonenum, int gender, std::string profilePic,
    int referecode, std::string membership, Account account, double Ubalance, Cart userCart, Order* pastOrders)
    : Person(name, birthdate, address, phonenum, gender, profilePic, referecode, membership, account),
    Ubalance(Ubalance), userCart(userCart), pastOrders(pastOrders) {}

User::User() : Ubalance(0.0), userCart(), pastOrders(0) {}

double User::getBalance() const
{
    return Ubalance;
}

bool User::setBalance(double const& Ubalance)
{
    this->Ubalance = Ubalance;
    return true;
}

void User::viewProfile() const
{

}

void User::view_P_history() const
{

}

void User::change_Password() const
{

}

void User::viewInfo() const
{

}

void User::delete_account() const
{

}
