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
        ui.storeView->hide();

        /*for (int i = 0; i < 100; i++) {
            QWidget* category = new QWidget(ui.scrollAreaWidgetContents);
            category->setObjectName("category2");
            category->setMinimumSize(QSize(1004, 120));
            category->setMaximumSize(QSize(1004, 120));
            category->setStyleSheet(QString::fromUtf8("#category2{\n"
                "background-color:rgb(60, 116, 221);\n"
                "border-radius: 15%;\n"
                "}"));
            QLabel* categoryLabel = new QLabel(category);
            categoryLabel->setObjectName("categoryLabel2");
            categoryLabel->setText(QString::fromStdString("Test"));
            categoryLabel->setGeometry(QRect(140, 44, 211, 31));
            categoryLabel->setStyleSheet(QString::fromUtf8("#categoryLabel2{\n"
                "color:white;\n"
                "font-size: 18px;\n"
                "font-weight: 700;\n"
                "}"));
            QLabel* categoryPic = new QLabel(category);
            categoryPic->setObjectName("categoryPic2");
            categoryPic->setGeometry(QRect(50, 40, 41, 41));
            categoryPic->setPixmap(QPixmap(QString::fromUtf8("media/shopping-cart-icon-2.png")));
            categoryPic->setScaledContents(true);
            QPushButton* categoryBtn = new QPushButton(category);
            categoryBtn->setObjectName("categoryBtn2");
            categoryBtn->setGeometry(QRect(910, 33, 50, 50));
            categoryBtn->setCursor(QCursor(Qt::PointingHandCursor));
            categoryBtn->setStyleSheet(QString::fromUtf8("#categoryBtn2{\n"
                "border: none;\n"
                "border-radius:25px;\n"
                "background-color:white;\n"
                "}\n"
                "#categoryBtn2::hover{\n"
                "background-color:rgb(200, 200, 200);\n"
                "}"));
            QIcon icon2;
            icon2.addFile(QString::fromUtf8("media/right arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
            categoryBtn->setIcon(icon2);
            categoryBtn->setIconSize(QSize(17, 16));
            ui.verticalLayout->addWidget(category, 0, Qt::AlignTop);
        }*/

        

        ui.loginErrorBox->hide();
        ui.signupErrorBox->hide();
        connect(ui.registerBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::registerUser);
        connect(ui.loginBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::loginUser);
        connect(ui.upload, &QPushButton::clicked, this, [=]() {uploadFile(ui.userI->text()); });
    }
    ~Importandexportcompanymanagementsystem();
    void customizeUI(std::string);

private slots:
    void registerUser();
    void loginUser();
    void uploadFile(QString);

private:
    Ui::ImportandexportcompanymanagementsystemClass ui;
    std::string filePath = "";
};

