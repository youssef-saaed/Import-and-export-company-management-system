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
	~Category();

	void setName(std::string&);
	std::string getName() const;
	
	void setDescription(std::string&);
	std::string getDescription() const;
		
	void setTags(std::string&);
	std::string getTags() const;
		
	void setImage(std::string&);
	std::string getImage() const;
		

	void setProducts(Product*);
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

