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
    QString UserName = ui.userLoginI->text();
    QString password = ui.passwordLoginI->text();
    
}

void Importandexportcompanymanagementsystem::registerUser()
{
    QString name = ui.nameI->text();
    QString username = ui.userI->text();
    QString email = ui.emailI->text();
    QString password = ui.passwordI->text();
    QString phone = ui.phoneNumI->text();
    QString address = ui.addressI->text();

}
