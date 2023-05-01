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

void Importandexportcompanymanagementsystem::registerUser()
{
    QString name = ui.nameI->text();
    QString username = ui.userI->text();
    QString email = ui.emailI->text();
    QString password = ui.passwordI->text();
    QString phone = ui.phoneNumI->text();
    QString address = ui.addressI->text();

    // Perform the registration logic here, e.g., create a new user account, save it to a database, etc.

    QString message = "Name: " + name + "\n" +
        "Username: " + username + "\n" +
        "Email: " + email + "\n" +
        "Password: " + password + "\n" +
        "Phone: " + phone + "\n" +
        "Address: " + address;

    QMessageBox::information(this, tr("Registration Successful"), message);
}
