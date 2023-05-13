#pragma once
#include <string>
#include "Product.h"

class Category
{
private:
	std::string name, description, tags, image;
	Product* products;
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

	// void addTag();

	// void removeTag();

	// void editTag();

	// void editCategory();

	bool search();
};

