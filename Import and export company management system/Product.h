#pragma once
#include <string>

class Product
{
private:
	std::string lifeCyclePeriod, name, description, image;
	double price, amount, mass, volume;
	int productID;
public:
	Product(const std::string&, const std::string&, const std::string&, const std::string&, const double&, const double&, const double&, const double&, const int&);
	Product();
	~Product();

	bool setlifeCyclePeriod(const std::string&);
	std::string getlifeCyclePeriod() const;

	bool setName(const std::string&);
	std::string getName() const;

	bool setDescription(const std::string&);
	std::string getDescription() const;

	bool setImage(const std::string&);
	std::string getImage() const;

	bool setPrice(const double&);
	double getPrice() const;

	bool setAmount(const double&);
	double getAmount() const;

	bool setMass(const double&);
	double getMass() const;

	bool setVolume(const double&);
	double getVolume() const;

	bool setProductID(const int&);
	int getProductID() const;

	bool isExists(int& productID);

	// void editProduct();

	// void addtoDB();
};
