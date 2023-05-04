#include "Importandexportcompanymanagementsystem.h"

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    QString username = ui.userLoginI->text();
    QString password = ui.passwordLoginI->text();

    std::ifstream handler("test.csv");

    std::string line;
    while (std::getline(handler, line))
    {
        QString qline = QString::fromStdString(line);
        QStringList columns = qline.split(",");
        if (columns[1] == username && columns[3] == password)
        {
            QString message = "Welcome Back " + username + "\n";
            QMessageBox::information(this, tr("Login Successful"),message);
            break;
        }
        else
        {
            QMessageBox::information(this, tr("Login Failed"), tr("Invalid username or password."));
        }
    }
    handler.close();
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
            gender = "female";
        }
        
        QString photoPath ;
        
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("JPEG files (*.jpg);;All files (*.*)"));
        
        

        handler << name.toStdString() << "," << username.toStdString() << "," << email.toStdString() << "," << password.toStdString() << ","
            << phone.toStdString() << "," << address.toStdString() << "," << gender.toStdString() << ",";
        handler.close();

        QMessageBox::information(this, tr("Registration Successful"), tr("Registered Successfully"));
    }
}
