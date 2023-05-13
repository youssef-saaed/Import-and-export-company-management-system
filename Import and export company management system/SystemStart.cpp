#include "SystemStart.h"

SystemStart::SystemStart(int argc, char* argv[], std::string companyName, std::string logoPath)
{
    Category *allCategories;
    std::ifstream csvReader;
    csvReader.open("DB")
    QApplication a(argc, argv);
    Importandexportcompanymanagementsystem w;
    w.setWindowTitle(QString::fromStdString(companyName + " Management System"));
    w.setWindowIcon(QIcon(QString::fromStdString(logoPath)));
    w.customizeUI(logoPath);
    w.show();
    a.exec();
}

void SystemStart::initiatingDB()
{
}
