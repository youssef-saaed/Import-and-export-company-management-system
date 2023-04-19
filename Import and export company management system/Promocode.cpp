#include "Promocode.h"

Promocode::Promocode(const std::string& code, const Date& expiryDate, Category* categories, Product* products)
{
	setCode(code);
	setExpiryDate(expiryDate);
	setCategories(categories);
	setProducts(products);
}

Promocode::~Promocode()
{
	delete products;
	delete categories;
}

bool Promocode::setCode(const std::string& code)
{
	if (code != "") {
		this->code = code;
		return true;
	}
	return false;
}

std::string Promocode::getCode() const
{
	return code;
}

bool Promocode::setExpiryDate(const Date& expiryDate)
{
	this->expiryDate = expiryDate;
	return true;
}

Date Promocode::getExpiryDate() const
{
	return expiryDate;
}

bool Promocode::setCategories(Category* categories)
{
	if (categories) {
		this->categories = categories;
		return true;
	}
	return false;
}

Category* Promocode::getCategories() const
{
	return categories;
}

bool Promocode::setProducts(Product* products)
{
	if (products) {
		this->products = products;
		return true;
	}
	return false;
}

Product* Promocode::getProducts() const
{
	return products;
}
