#pragma once

#include <string>
#include "Account.h"
#include "Cart.h"
#include "Category.h"
#include "Date.h"
#include "Employee.h"
#include "Importandexportcompanymanagementsystem.h"
#include "Inventory.h"
#include "Order.h"
#include "Person.h"
#include "Shipment.h"
#include "User.h"
#include "Vehicle.h"

class Account;
class User;
class Person;

class SystemStart
{
private:
	void initiatingDB();
public:
	SystemStart(int, char* [], std::string, std::string);
};

