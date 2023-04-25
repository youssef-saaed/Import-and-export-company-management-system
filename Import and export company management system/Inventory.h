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

	bool setCategories(Category*);
	Category* getCategories() const;

	// bool addCategory();

	// bool removeCategory();
};