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
