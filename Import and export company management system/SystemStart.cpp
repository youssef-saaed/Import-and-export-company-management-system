#include "SystemStart.h"

SystemStart::SystemStart(int argc, char* argv[], std::string companyName, std::string logoPath)
{
    Category *allCategories;
    std::ifstream fileReader,fileReader2;
    fileReader.open("./DB/categories count.txt");
    std::string line,pLine;
    std::getline(fileReader, line);
    int count = QString::fromStdString(line).trimmed().toInt();
    inventory->setCategoryCount(count);
    allCategories = new Category[count];
    fileReader.close();

    fileReader.open("./DB/categories.csv");
    std::getline(fileReader, line);
    for (int i = 0; i < count; i++) {
        std::getline(fileReader, line);
        QStringList row = QString::fromStdString(line).split(",");
        Category *temp = new Category;
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

    inventory->setCategories(allCategories);

    QApplication a(argc, argv);
    Importandexportcompanymanagementsystem w;
    w.setWindowTitle(QString::fromStdString(companyName + " Management System"));
    w.setWindowIcon(QIcon(QString::fromStdString(logoPath)));
    w.customizeUI(logoPath);
    w.inventory = inventory;
    w.show();
    a.exec();
}

void SystemStart::initiatingDB()
{
}
