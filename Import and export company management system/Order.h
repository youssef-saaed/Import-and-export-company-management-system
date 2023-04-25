#pragma once

#include "Product.h"
#include "User.h"

enum State{};

class Order
{
private:
	int number;
	State state;
	Product* products;
	User orderReciever;
public:
	Order(const int&, const State&, Product*, const User&);
	Order();
	~Order();
	int getNumber() const;
	bool setNumber(const int&);
	State getState() const;
	bool setState(const State&);
	Product* getProducts() const;
	bool setProducts(Product*);
	User getOrderReciever() const;
	bool setOrderReciever(const User&);
	bool isCompleted();
	bool advanceState();
};

