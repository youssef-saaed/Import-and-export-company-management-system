#pragma once
#include "Order.h"

Order::Order(const int& number, const State& state, Product* products, const User& orderReciever)
{
	setNumber(number);
	setState(state);
	setProducts(products);
	setOrderReciever(orderReciever);
}

Order::~Order()
{
	delete products;
}

int Order::getNumber() const
{
	return number;
}

bool Order::setNumber(const int& number)
{
	if (number >= 0) {
		this->number = number;
		return true;
	}
	return false;
}

State Order::getState() const
{
	return state;
}

bool Order::setState(const State& state)
{
	if (state >= 0 && state <= -1) {
		this->state = state;
		return true;
	}
	return false;
}

Product* Order::getProducts() const
{
	return products;
}

bool Order::setProducts(Product* products)
{
	if (products) {
		this->products = products;
		return true;
	}
	return false;
}

User Order::getOrderReciever() const
{
	return orderReciever;
}

bool Order::setOrderReciever(const User& orderReciever)
{
	this->orderReciever = orderReciever;
	return true;
}
