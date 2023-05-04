#include "Category.h"

Category::Category(const std::string& name, const std::string& description, const std::string& tags, const std::string& image, Product* products) {
	setName(name);
	setDescription(description);
	setTags(tags);
	setImage(image);
	setProducts(products);
}

Category::~Category()
{
	delete products;
}



bool Category::setName(const std::string& name) {
	if (name != " ") {
		this->name = name;
		return true;
	}return false;
}

std::string Category::getName() const{
	return name;
}

bool Category::setDescription(const std::string& description) {
	if (description != " ") {
		this->description = description;
		return true;
	}return false;
}

std::string Category::getDescription() const {
	return description;
}

bool Category::setTags(const std::string& tags) {
	if (tags != " ") {
		this-> tags = tags;
		return true;
	}return false;
}
std::string Category::getTags() const {
	return tags;
}

bool Category::setImage(const std::string& image)
{
	if (image != " ") {
		this->image = image;
		return true;
	}return false;
}

std::string Category::getImage() const
{
	return image;
}

bool Category::setProducts(Product* products)
{
	if (products) {
		this->products = products;
		return true;
	}return false;
}

Product* Category::getProducts() const
{
	return products;
}

