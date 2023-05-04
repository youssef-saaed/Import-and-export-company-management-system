#include "Importandexportcompanymanagementsystem.h"
#include <fstream>
#include <iostream>
#include <string>

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    QString username = ui.userLoginI->text();
    QString password = ui.passwordLoginI->text();

    std::ifstream file("test.csv");
    std::string line;
    while (std::getline(file, line))
    {
        QString qline = QString::fromStdString(line);
        QStringList columns = qline.split(",");
        if (columns[1] == username && columns[3] == password)
        {
            QString mess1 = " Welcome Back  " + username + "\n";
            QMessageBox::information(this, tr("Login Successful"), mess1);
            break;
        }
        else if (columns[1] != username && columns[3] != password)
        {
            QMessageBox::information(this, tr("Login Failed"), tr("Invalid UserName or PassWord"));
        }
    }

    file.close();

    
} 

void Importandexportcompanymanagementsystem::registerUser()
{
    std::ofstream handler("test.csv", std::ios::app);
    if (handler.is_open()) {
        QString name = ui.nameI->text();
        QString username = ui.userI->text();
        QString email = ui.emailI->text();
        QString password = ui.passwordI->text();
        QString phone = ui.phoneNumI->text();
        QString address = ui.addressI->text();
        QString gender;
        
        if (ui.genderMale->isChecked())
        {
            gender = "male";
        }
        else if (ui.genderFemale->isChecked())
        {
            gender =  "female";
        }

        handler << name.toStdString() << "," << username.toStdString() << "," << email.toStdString() << "," << password.toStdString() << "," <<
            phone.toStdString() << "," <<address
            .toStdString()  << "," << gender.toStdString() << "\n";
        handler.close();

        QString message = "Registred Succefuly";
        
        QMessageBox::information(this, tr("Registration Successful"), message);
        
    }
}
