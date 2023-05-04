#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <fstream>
#include <iostream>
#include <string>

#include "ui_Importandexportcompanymanagementsystem.h"

class Importandexportcompanymanagementsystem : public QMainWindow
{
    Q_OBJECT

public:
    Importandexportcompanymanagementsystem(QWidget* parent = nullptr)
        : QMainWindow(parent)
    {
        ui.setupUi(this);
        ui.passwordI->setEchoMode(QLineEdit::Password);
        ui.passwordLoginI->setEchoMode(QLineEdit::Password);
        ui.loginErrorBox->hide();
        ui.signupErrorBox->hide();
        connect(ui.registerBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::registerUser);
        connect(ui.loginBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::loginUser);
        connect(ui.upload, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::registerUser);
    }
    ~Importandexportcompanymanagementsystem();

private slots:
    void registerUser();
    void loginUser();

private:
    Ui::ImportandexportcompanymanagementsystemClass ui;
};
