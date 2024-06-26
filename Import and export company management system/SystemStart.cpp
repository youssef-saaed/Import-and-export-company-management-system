#include "SystemStart.h"

SystemStart::SystemStart(int argc, char* argv[], std::string companyName, std::string logoPath)
{
    

    QApplication a(argc, argv);
    Importandexportcompanymanagementsystem w;
    w.setWindowTitle(QString::fromStdString(companyName + " Management System"));
    w.setWindowIcon(QIcon(QString::fromStdString(logoPath)));
    w.customizeUI(logoPath);
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    loadCategories(w);
    w.show();
    a.exec();
}

void SystemStart::loadCategories(Importandexportcompanymanagementsystem& w)
{
    inventory->loadInventory();
    w.inventory = inventory;
}

void SystemStart::initiatingDB()
{
}
