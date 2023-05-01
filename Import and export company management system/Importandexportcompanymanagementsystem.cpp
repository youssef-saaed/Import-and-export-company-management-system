#include "Importandexportcompanymanagementsystem.h"

Importandexportcompanymanagementsystem::Importandexportcompanymanagementsystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.passwordI->setEchoMode(QLineEdit::Password);
    ui.passwordLoginI->setEchoMode(QLineEdit::Password);
    /*QObject::connect(ui.registerBtn,Q)*/
}

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}
