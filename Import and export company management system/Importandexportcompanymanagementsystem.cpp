#include "Importandexportcompanymanagementsystem.h"

Importandexportcompanymanagementsystem::Importandexportcompanymanagementsystem(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.passwordI->setEchoMode(QLineEdit::Password);
    ui.passwordLoginI->setEchoMode(QLineEdit::Password);

    connect(ui.registerBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::registerUser);
}

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    QString username=ui.userLoginI->text();
    QString password=ui.passwordLoginI->text();
    QMessageBox::information(this, tr("Login Successful"),tr("Login succefully mother fucker"));

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
    QString message = "Name: " + name + "\n" +
        "Username: " + username + "\n" +
        "Email: " + email + "\n" +
        "Password: " + password + "\n" +
        "Phone: " + phone + "\n" +
        "Address: " + address+"\n"+
        "Gender:"+gender;
    QMessageBox::information(this, tr("Registration Successful"), message);
}
