#include "Importandexportcompanymanagementsystem.h"

Importandexportcompanymanagementsystem::Importandexportcompanymanagementsystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.passwordI->setEchoMode(QLineEdit::Password);
}

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}
