#include "Product.h"

Product::Product(const std::string& lifeCyclePeriod, const std::string& name, const std::string& description, const std::string& image, const double& price, const double& amount, const double& mass, const double& volume, const int& productID)
{
	setlifeCyclePeriod(lifeCyclePeriod);
	setName(name);
	setDescription(description);
	setImage(image);
	setPrice(price);
	setAmount(amount);
	setMass(mass);
	setVolume(volume);
	setProductID(productID);
}

Product::Product()
{
}

Product::~Product()
{
}

bool Product::setlifeCyclePeriod(const std::string& lifeCyclePeriod)
{
	if (lifeCyclePeriod != " ") {
		this->lifeCyclePeriod = lifeCyclePeriod;
		return true;
	}return false;
}

std::string Product::getlifeCyclePeriod() const
{
	return lifeCyclePeriod;
}

bool Product::setName(const std::string& name)
{
	if (name != " ") {
		this->name = name;
		return true;
	}return false;
}

std::string Product::getName() const
{
	return name;
}

bool Product::setDescription(const std::string& description)
{
	if (description != " ") {
		this->description = description;
		return true;
	}return false;
}

std::string Product::getDescription() const
{
	return description;
}

bool Product::setImage(const std::string& image)
{
	if (image != " ") {
		this->image = image;
		return true;
	}return false;
}

std::string Product::getImage() const
{
	return image;
}

bool Product::setPrice(const double& price)
{
	if (price >= 0) {
		this->price = price;
		return true;
	}return false;
}

double Product::getPrice() const
{
	return price;
}

bool Product::setAmount(const double& amount)
{
	if (amount >= 0) {
		this->amount = amount;
		return true;
	}return false;
}

double Product::getAmount() const
{
	return amount;
}

bool Product::setMass(const double& mass)
{
	if (mass >= 0) {
		this->mass = mass;
		return true;
	}return false;
}

double Product::getMass() const
{
	return mass;
}

bool Product::setVolume(const double& volume)
{
	if (volume >= 0) {
		this->volume = volume;
		return true;
	}return false;
}

double Product::getVolume() const
{
	return volume;
}

bool Product::setProductID(const int& productID)
{
	if (productID >= 0) {
		this->productID = productID;
		return true;
	}return false;
}

int Product::getProductID() const
{
	return productID;
}


