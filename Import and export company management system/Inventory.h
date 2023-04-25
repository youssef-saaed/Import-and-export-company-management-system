#pragma once
#include "Category.h"

class Inventory
{
private:
	Category* categories;
public:
	Inventory(Category*);
	Inventory();
	~Inventory();

	void setCategories(Category*);
	Category* getCategories() const;

	// bool addCategory();

	// bool removeCategory();
};