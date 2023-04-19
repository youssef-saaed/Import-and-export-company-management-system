#pragma once
#include "Cart.h"
#include "Order.h"

class User {
private:
    float Ubalance;
    Cart userCart;
    Order pastOrders;

public:
    User();

    float getBalance();
    void setBalance(float Ubalance);

    void viewProfile();
    void view_P_history();

    void change_Password();
};
#endif
