#include "SystemStart.h"

SystemStart::SystemStart(int argc, char* argv[], std::string companyName, std::string logoPath)
{
    Category *allCategories;
    std::ifstream fileReader;
    fileReader.open("./DB/categories count.txt");
    std::string line;
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
