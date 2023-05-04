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
