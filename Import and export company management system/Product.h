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
	~Product();

	void setlifeCyclePeriod(const std::string&);
	std::string getlifeCyclePeriod() const;

	void setName(const std::string&);
	std::string getName() const;

	void setDescription(const std::string&);
	std::string getDescription() const;

	void setImage(const std::string&);
	std::string getImage() const;

	void setPrice(const double&);
	double getPrice() const;

	void setAmount(const double&);
	double getAmount() const;

	void setMass(const double&);
	double getMass() const;

	void setVolume(const double&);
	double getVolume() const;

	void setProductID(const int&);
	int getProductID() const;

	bool isExists(int& productID);

	// void editProduct();

	// void addtoDB();
};

