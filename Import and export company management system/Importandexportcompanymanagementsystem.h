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
class Product;
class User;
class Category;
class Importandexportcompanymanagementsystem : public QMainWindow
{
    Q_OBJECT
public:
    friend class SystemStart;
    Importandexportcompanymanagementsystem(QWidget* parent = nullptr)
        : QMainWindow(parent)
    {
        ui.setupUi(this);

        ui.passwordI->setEchoMode(QLineEdit::Password);
        ui.passwordLoginI->setEchoMode(QLineEdit::Password);
        ui.editPassword->setEchoMode(QLineEdit::Password);

        ui.storeView->hide(); 
        ui.categoryView->hide();
        ui.productView->hide();
        ui.editAccountView->hide();
        ui.addCreditView->hide();
        ui.inventoryView->hide();
        ui.teamCreditsView->hide();
        ui.addCategoryView->hide();

        ui.loginErrorBox->hide();
        ui.signupErrorBox->hide();
        ui.editAccErrorBox->hide();
        ui.addCategoryErrorBox->hide();

        connect(ui.exitBtn, &QPushButton::clicked, this, &QMainWindow::close);
        connect(ui.minimizeBtn, &QPushButton::clicked, this, [=]() {QWidget::setWindowState(Qt::WindowMinimized); });
        connect(ui.registerBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::registerUser);
        connect(ui.loginBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::loginUser);
        connect(ui.upload, &QPushButton::clicked, this, [=]() {uploadFile(ui.userI->text()); });
        connect(ui.categoryBackBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::backToAllCategories);
        connect(ui.toCategoryBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::backToCategory);
        connect(ui.editAccBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::editAcc);
        connect(ui.editAccBackBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::closeEditAcc);
        connect(ui.searchBtn, &QPushButton::clicked, this, [=]() {search(ui.searchInput->text().toLower().toStdString()); });
        connect(ui.addCreditBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::viewAddCash);
        connect(ui.addCreditBackBtn, &QPushButton::clicked, this, [=]() {ui.addCreditView->hide(); });
        connect(ui.addCreditConfirmBtn, &QPushButton::clicked, this, [=]() {ui.addCreditView->hide(); addCash(ui.addCreditAmount->value()); });
        connect(ui.goToCredits, &QPushButton::clicked, this, [=]() {ui.teamCreditsView->show(); });
        connect(ui.teamCreditsBackBtn, &QPushButton::clicked, this, [=]() {ui.teamCreditsView->hide(); });
        connect(ui.addCategoryBtn, &QPushButton::clicked, this, [=]() {ui.addCategoryView->show(); });
        connect(ui.addCategoryBackBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::backFromAddCategory);
        connect(ui.uploadCategoryPic, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::uploadCategoryPic);
        connect(ui.addCategoryAddBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::addCategory);
    }
    ~Importandexportcompanymanagementsystem();
    void customizeUI(std::string);

private slots:
    void registerUser();
    void loginUser();
    void uploadFile(QString);
    void uploadCategoryPic();
    void generateCategories();
    void generateCategoriesE();
    void generateProducts(int);
    void generateProducts(int*);
    void backToAllCategories();
    void backToCategory();
    void productViewSetup(Product*);
    void editAcc();
    void closeEditAcc();
    void search(std::string);
    void addCash(double);
    void viewAddCash();
    void backFromAddCategory();
    void addCategory();

private:
    Ui::ImportandexportcompanymanagementsystemClass ui;
    Inventory* inventory;
    Product* searchResult;
    int searchResultCount;
    int currentCategory;
    User* currentUser;
    Employee* currentEmployee;
    std::string filePath = "";
    std::string categoryImgPath = "";
};

