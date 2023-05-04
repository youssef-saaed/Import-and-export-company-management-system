#pragma once
#include "Cart.h"

Cart::Cart(Product* products, const ShipmentType& type)
{
	setShipmentType(type);
	setProduct(products);
}

Cart::Cart()
{
}

Cart::~Cart()
{
}

bool Cart::setShipmentType(const ShipmentType& type)
{
	if (type >= 0 && type <= 1) {
		this->type = type;
		return true;
	}return false;
}

ShipmentType Cart::getShipmentType() const
{
	return type;
}

bool Cart::setProduct(Product* products)
{
	if (products) {
		this->products = products;
		return true;
	}return false;
}

Product* Cart::getProduct() const
{
	return products;
}

