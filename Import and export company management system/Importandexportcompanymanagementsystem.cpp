#include "Importandexportcompanymanagementsystem.h"

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    QString username=ui.userLoginI->text();
    QString password=ui.passwordLoginI->text();
    QString message2 = "Welcome " + username + "\n";
    QMessageBox::information(this, tr("Login Successful"),message2);
}

void Importandexportcompanymanagementsystem::registerUser()
{
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
        gender = "female";
    }
    QString message = "Name: " + name + "\n" +"Username: " + username + "\n" + "Email: " + email + "\n" +"Password:" + password + "\n" +"Phone: " + phone + "\n" +"Address: " + address+"\n"+"Gender:"+gender;
    QMessageBox::information(this, tr("Registration Successful"), message);
}
