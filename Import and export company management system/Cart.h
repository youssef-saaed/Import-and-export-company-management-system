#pragma once
#include "Product.h"

class Cart
{
private:
	Product* products;
	int shipmentType;
public:
	Cart(Product*, const int&);
	~Cart();

	double totalCost(Product*);

	// void checkOut();

	// void display_Info();

	void addProduct(Product*);

	void editProduct(Product*);

	void removeProduct(Product*);

	double applyDiscount();
};