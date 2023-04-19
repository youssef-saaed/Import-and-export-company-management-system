#pragma once

enum State{};

class Order
{
private:
	int number;
	State state;
	Product* products;
	User orderReciever;
public:
	Order(int&, State&, Product*, User&);
	~Order();
	int getNumber() const;
	bool setNumber(int&);
	State getState() const;
	bool setState(State&);
	Product* getProducts() const;
	bool setProducts(Product*);
	User getOrderReciever() const;
	bool setOrderReciever(User&);
	bool isCompleted();
	bool advanceState();
};

