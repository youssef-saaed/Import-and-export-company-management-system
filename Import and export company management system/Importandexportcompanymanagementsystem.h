#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <fstream>
#include <iostream>
#include <string>

#include "ui_Importandexportcompanymanagementsystem.h"
#include "SystemStart.h"

class Inventory;
class Importandexportcompanymanagementsystem : public QMainWindow
{
    Q_OBJECT
public:
    Inventory* inventory;
    Importandexportcompanymanagementsystem(QWidget* parent = nullptr)
        : QMainWindow(parent)
    {
        ui.setupUi(this);
        ui.passwordI->setEchoMode(QLineEdit::Password);
        ui.passwordLoginI->setEchoMode(QLineEdit::Password);
        ui.storeView->hide(); 
        ui.categoryView->hide();
        ui.productView->hide();

        ui.loginErrorBox->hide();
        ui.signupErrorBox->hide();
        connect(ui.registerBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::registerUser);
        connect(ui.loginBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::loginUser);
        connect(ui.upload, &QPushButton::clicked, this, [=]() {uploadFile(ui.userI->text()); });
        connect(ui.categoryBackBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::backToAllCategories);
        connect(ui.toCategoryBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::backToCategory);
    }
    ~Importandexportcompanymanagementsystem();
    void customizeUI(std::string);

private slots:
    void registerUser();
    void loginUser();
    void uploadFile(QString);
    void generateCategories();
    void generateProducts(int);
    void backToAllCategories();
    void backToCategory();
    void productViewSetup(Product*);

private:
    Ui::ImportandexportcompanymanagementsystemClass ui;
    std::string filePath = "";
};

