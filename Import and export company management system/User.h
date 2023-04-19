#pragma once
#include "Cart.h"
#include "Order.h"

class User {
private:
    double Ubalance;
    Cart userCart;
    Order pastOrders;

public:
    User();

    double getBalance() const;
    void setBalance(double const& Ubalance);

    void viewProfile() const;
    void view_P_history() const;

    void change_Password() const;
};

#endif // IMPORT_AND_EXPORT_COMPANY_MANAGEMENT_SYSTEM_USER_H
