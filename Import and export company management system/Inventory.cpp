#include "Inventory.h"

Inventory::Inventory(Category* categories)
{
	setCategories(categories);
}

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
	delete categories;
}

bool Inventory::setCategories(Category* categories)
{
	if (categories) {
		this->categories = categories;
		return true;
	}return false;
}

Category* Inventory::getCategories() const
{
	return categories;
}

bool Inventory::setCategoryCount(const int& count)
{
	if (count > 0) {
		categoryCount = count;
		return true;
	}
	return false;
}

int Inventory::getCategoryCount() const
{
	return categoryCount;
}
