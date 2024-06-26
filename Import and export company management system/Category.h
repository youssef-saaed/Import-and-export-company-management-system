#pragma once
#include <string>
#include "Product.h"
#include <regex>
#include <istream>
#include <fstream>
#include <sstream>
#include <QString>

class Product;
class Category
{
private:
	std::string name, description, tags, image;
	Product* products;
	int numOfProducts;
public:
	Category(const std::string&, const std::string&, const std::string&, const std::string&, Product*);
	Category();
	Category(Category*);
	~Category();

	bool setName(const std::string&);
	std::string getName() const;
	
	bool setDescription(const std::string&);
	std::string getDescription() const;
		
	bool setTags(const std::string&);
	std::string getTags() const;
		
	bool setImage(const std::string&);
	std::string getImage() const;
		

	bool setProducts(Product*);
	Product* getProducts() const;

	// void display_Info();

	void addProduct(Product*);

	void editProduct(Product*);

	void removeProduct(Product*);

	std::string check();

	// void addTag();

	// void removeTag();

	// void editTag();

	// void editCategory();

	bool setNumOfProducts(const int&);
	int* search(std::string);
	int getNumOfProducts() const;
	void writeToCsv();
};

