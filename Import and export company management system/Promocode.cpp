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

bool Promocode::addPromocode(const std::string& code)
{
	if (std::find(promoCodes.begin(), promoCodes.end(), code) == promoCodes.end()) {
		promoCodes.push_back(code);
		std::cout << "promocode" << code << "added" << std::endl;
		return true;
	}
	else {
		std::cout << code << "already exists" << std::endl;
		return false;

	}
}

bool Promocode::editPromocode(const std::string& oldCode, const std::string& newCode)
{
	auto iteratore = std::find(promoCodes.begin(), promoCodes.end(), oldCode);
	if (iteratore != promoCodes.end()) {
		*iteratore = newCode;
		std::cout << newCode << "old code edited" << std::endl;
		return true;
	}
	else {
		std::cout << newCode << "already exists" << std::endl;
		return false;
	}
}

bool Promocode::removePromocode(const std::string& code)
{
	auto iteratore = std::find(promoCodes.begin(), promoCodes.end(), code);
	if (iteratore != promoCodes.end()) {
		promoCodes.erase(iteratore);
		std::cout << code << "removed";
		return true;
	}
	else {
		std::cout << code << "doesn't exist" << std::endl;
		return false;
	}
}
