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

        ui.loginErrorBox->hide();
        ui.signupErrorBox->hide();
        connect(ui.registerBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::registerUser);
        connect(ui.loginBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::loginUser);
        connect(ui.upload, &QPushButton::clicked, this, [=]() {uploadFile(ui.userI->text()); });
        ui.gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        /*for (int i = 0; i < 15; i++) {
            QFrame* product = new QFrame(ui.scrollAreaWidgetContents_2);
            product->setObjectName("product2");
            product->setMinimumSize(QSize(194, 240));
            product->setMaximumSize(QSize(194, 240));
            product->setStyleSheet(QString::fromUtf8("#product2{\n"
                "background-color:#fff;\n"
                "border-radius:25%;\n"
                "border: 0.5px solid #2b094a;\n"
                "}"));
            product->setFrameShape(QFrame::StyledPanel);
            product->setFrameShadow(QFrame::Raised);
            QLabel* productImg = new QLabel(product);
            productImg->setObjectName("productImg2");
            productImg->setGeometry(QRect(37, 30, 121, 121));
            productImg->setTextFormat(Qt::PlainText);
            productImg->setPixmap(QPixmap(QString::fromUtf8("media/Products img/milk.png")));
            productImg->setScaledContents(true);
            QLabel* productName = new QLabel(product);
            productName->setObjectName("productName2");
            productName->setText(QString::fromStdString("Milk"));
            productName->setGeometry(QRect(20, 170, 100, 20));
            productName->setStyleSheet(QString::fromUtf8("#productName2{\n"
                "color:#2b094a;\n"
                "font-weight:700;\n"
                "}"));
            QLabel* productPrice = new QLabel(product);
            productPrice->setObjectName("productPrice2");
            productPrice->setText(QString::fromStdString("9.5EGP"));
            productPrice->setGeometry(QRect(20, 190, 100, 20));
            productPrice->setStyleSheet(QString::fromUtf8("#productPrice2{\n"
                "color:#2b094a;\n"
                "font-weight:700;\n"
                "}"));
            QPushButton* productBtn = new QPushButton(product);
            productBtn->setObjectName("productBtn2");
            productBtn->setGeometry(QRect(130, 170, 51, 41));
            productBtn->setCursor(QCursor(Qt::PointingHandCursor));
            productBtn->setStyleSheet(QString::fromUtf8("#productBtn2{\n"
                "background-color:#39b105;\n"
                "}\n"
                "#productBtn2::hover{\n"
                "background-color:#fff;\n"
                "border:1px solid #000;\n"
                "}"));
            QIcon icon2;
            icon2.addFile(QString::fromUtf8("media/right arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
            productBtn->setIcon(icon2);
            ui.gridLayout->addWidget(product, i / 5, i % 5, 1, 1);
        }*/
    }
    ~Importandexportcompanymanagementsystem();
    void customizeUI(std::string);

private slots:
    void registerUser();
    void loginUser();
    void uploadFile(QString);
    void generateCategories();

private:
    Ui::ImportandexportcompanymanagementsystemClass ui;
    std::string filePath = "";
};

