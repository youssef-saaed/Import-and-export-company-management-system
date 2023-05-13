#pragma once
#include "Category.h"

class Inventory
{
private:
	Category* categories;
	int categoryCount;
public:
	Inventory(Category*);
	Inventory();
	~Inventory();

	bool setCategories(Category*);
	Category* getCategories() const;

	bool setCategoryCount(const int&);
	int getCategoryCount() const;

	// bool addCategory();

	// bool removeCategory();
};