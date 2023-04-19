#pragma once

#include <string>
#include "Product.h"
#include "Category.h"
#include "Date.h"

class Promocode
{
private:
	std::string code;
	Date expiryDate;
	Category* categories;
	Product* products;
public:
	Promocode(const std::string&, const Date&, Category*, Product*);
	~Promocode();
	bool setCode(const std::string&);
	std::string getCode() const;
	bool setExpiryDate(const Date&);
	Date getExpiryDate() const;
	bool setCategories(Category*);
	Category* getCategories() const;
	bool setProducts(Product*);
	Product* getProducts() const;
	bool addCategory(const Category&);
	bool removeCategory(const Category&);
	bool addProduct(const Product&);
	bool removeProduct(const Product&);
	int timeTillExpire() const;
};

