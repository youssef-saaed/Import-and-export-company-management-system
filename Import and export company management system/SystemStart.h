#pragma once

#include <cmath>
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

class Importandexportcompanymanagementsystem;
class SystemStart
{
private:
	void initiatingDB();
public:
	Inventory* inventory = new Inventory;
	SystemStart(int, char* [], std::string, std::string);
	void loadCategories(Importandexportcompanymanagementsystem&);
};

