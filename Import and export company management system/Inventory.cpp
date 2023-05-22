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

void Inventory::loadInventory()
{
    Category* allCategories;
    std::ifstream fileReader, fileReader2;
    fileReader.open("./DB/categories count.txt");
    std::string line, pLine;
    std::getline(fileReader, line);
    int count = QString::fromStdString(line).trimmed().toInt();
    setCategoryCount(count);
    allCategories = new Category[count];
    fileReader.close();

    fileReader.open("./DB/categories.csv");
    std::getline(fileReader, line);
    for (int i = 0; i < count; i++) {
        std::getline(fileReader, line);
        QStringList row = QString::fromStdString(line).split(",");
        Category* temp = new Category;
        temp->setName(row[0].toStdString());
        temp->setDescription(row[1].toStdString());
        temp->setTags(row[2].toStdString());
        temp->setImage(row[3].toStdString());
        QStringList productsNums = row[4].split("-");
        Product* products;
        int j = 0;
        fileReader2.open("./DB/products.csv");
        std::getline(fileReader2, pLine);
        if (productsNums[0] != QString::fromStdString("")) {
            temp->setNumOfProducts(productsNums.size());
            products = new Product[productsNums.size()];
            while (std::getline(fileReader2, pLine)) {
                QStringList pRow = QString::fromStdString(pLine).split(",");
                if (productsNums.indexOf(pRow[0]) != -1) {
                    Product tempP;
                    tempP.setProductID(pRow[0].toInt());
                    tempP.setName(pRow[1].toStdString());
                    tempP.setDescription(pRow[2].toStdString());
                    tempP.setImage(pRow[3].toStdString());
                    tempP.setPrice(pRow[4].toDouble());
                    tempP.setAmount(pRow[5].toDouble());
                    tempP.setlifeCyclePeriod(pRow[6].toStdString());
                    tempP.setMass(pRow[7].toDouble());
                    tempP.setVolume(pRow[8].toDouble());
                    products[j] = tempP;
                    j++;
                }
            }
        }
        fileReader2.close();
        temp->setProducts(products);
        *(allCategories + i) = *temp;
    }
    fileReader.close();

    setCategories(allCategories);
}
