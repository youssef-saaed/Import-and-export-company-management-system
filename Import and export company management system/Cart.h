#pragma once
#include "Product.h"
enum ShipmentType {delivery, notDelivery};
class Cart
{
private:
	Product* products;
	ShipmentType type;
public:
	Cart(Product*, const ShipmentType&);
	Cart();
	~Cart();

	bool setShipmentType(const ShipmentType&);
	ShipmentType getShipmentType() const;

	bool setProduct(Product*);
	Product* getProduct() const;

	double totalCost(Product*);

	// void checkOut();

	// void display_Info();

	void addProduct(Product*);

	void editProduct(Product*);

	void removeProduct(Product*);

	double applyDiscount();
};