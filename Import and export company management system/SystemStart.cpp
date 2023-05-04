#include "SystemStart.h"

SystemStart::SystemStart(int argc, char* argv[], std::string companyName, std::string logoPath)
{
    QApplication a(argc, argv);
    Importandexportcompanymanagementsystem w;
    w.setWindowTitle(QString::fromStdString(companyName + " Management System"));
    w.customizeUI(logoPath);
    w.show();
    a.exec();
}

void SystemStart::initiatingDB()
{
}
