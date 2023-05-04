#pragma once

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportandexportcompanymanagementsystemClass
{
public:
    QWidget* centralWidget;
    QWidget* Header;
    QLabel* Logo;
    QWidget* Footer;
    QLabel* CR;
    QPushButton* goToCredits;
    QFrame* loginAndRegister;
    QWidget* Seperator;
    QLabel* signupLabel;
    QLabel* signupLabel_2;
    QFrame* frame;
    QLineEdit* nameI;
    QLineEdit* phoneNumI;
    QLineEdit* addressI;
    QDateEdit* birthDateI;
    QLabel* birthDateLabel;
    QLabel* genderLabel;
    QRadioButton* genderMale;
    QRadioButton* genderFemale;
    QLabel* picLabel;
    QPushButton* upload;
    QLineEdit* emailI;
    QLineEdit* passwordI;

    void setupUi(QMainWindow* ImportandexportcompanymanagementsystemClass)
    {
        if (ImportandexportcompanymanagementsystemClass->objectName().isEmpty())
            ImportandexportcompanymanagementsystemClass->setObjectName("ImportandexportcompanymanagementsystemClass");
        ImportandexportcompanymanagementsystemClass->resize(1080, 720);
        ImportandexportcompanymanagementsystemClass->setMinimumSize(QSize(1080, 720));
        ImportandexportcompanymanagementsystemClass->setMaximumSize(QSize(1080, 720));
        QIcon icon;
        icon.addFile(QString::fromUtf8("D:/CSAI/Year 1/Semster 2/CSAI 151/Project/Import and export company management system/Media/Logo/logo_transparent.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImportandexportcompanymanagementsystemClass->setWindowIcon(icon);
        centralWidget = new QWidget(ImportandexportcompanymanagementsystemClass);
        centralWidget->setObjectName("centralWidget");
        Header = new QWidget(centralWidget);
        Header->setObjectName("Header");
        Header->setGeometry(QRect(0, 0, 1081, 131));
        Header->setStyleSheet(QString::fromUtf8("#Header{\n"
            "background-color:#a2a2a2;\n"
            "}"));
        Logo = new QLabel(Header);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(20, -64, 271, 271));
        Logo->setPixmap(QPixmap(QString::fromUtf8("D:/CSAI/Year 1/Semster 2/CSAI 151/Project/Import and export company management system/Media/Logo/logo_transparent.png")));
        Logo->setScaledContents(true);
        Footer = new QWidget(centralWidget);
        Footer->setObjectName("Footer");
        Footer->setGeometry(QRect(0, 689, 1081, 31));
        Footer->setStyleSheet(QString::fromUtf8("#Footer{\n"
            "background-color:#2B094A;\n"
            "}"));
        CR = new QLabel(Footer);
        CR->setObjectName("CR");
        CR->setGeometry(QRect(20, 8, 241, 16));
        CR->setStyleSheet(QString::fromUtf8("#CR{\n"
            "color:#fff;\n"
            "}"));
        CR->setTextFormat(Qt::PlainText);
        goToCredits = new QPushButton(Footer);
        goToCredits->setObjectName("goToCredits");
        goToCredits->setGeometry(QRect(985, 3, 75, 24));
        goToCredits->setStyleSheet(QString::fromUtf8("#goToCredits{\n"
            "background-color:#EB2532;\n"
            "color:#fff;\n"
            "border:none;\n"
            "transition: background-color 2s;\n"
            "}\n"
            "#goToCredits:hover{\n"
            "background-color:rgb(140, 22, 30);\n"
            "color:#fff;\n"
            "border:none;\n"
            "}"));
        loginAndRegister = new QFrame(centralWidget);
        loginAndRegister->setObjectName("loginAndRegister");
        loginAndRegister->setEnabled(true);
        loginAndRegister->setGeometry(QRect(0, 130, 1080, 561));
        loginAndRegister->setFrameShape(QFrame::StyledPanel);
        loginAndRegister->setFrameShadow(QFrame::Raised);
        Seperator = new QWidget(loginAndRegister);
        Seperator->setObjectName("Seperator");
        Seperator->setGeometry(QRect(539, 50, 2, 461));
        Seperator->setStyleSheet(QString::fromUtf8("#Seperator{\n"
            "background-color:#000;\n"
            "}"));
        signupLabel = new QLabel(loginAndRegister);
        signupLabel->setObjectName("signupLabel");
        signupLabel->setGeometry(QRect(206, 60, 131, 51));
        signupLabel_2 = new QLabel(loginAndRegister);
        signupLabel_2->setObjectName("signupLabel_2");
        signupLabel_2->setGeometry(QRect(746, 60, 131, 51));
        frame = new QFrame(loginAndRegister);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(120, 110, 301, 331));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        nameI = new QLineEdit(frame);
        nameI->setObjectName("nameI");
        nameI->setGeometry(QRect(10, 20, 281, 31));
        phoneNumI = new QLineEdit(frame);
        phoneNumI->setObjectName("phoneNumI");
        phoneNumI->setGeometry(QRect(10, 137, 281, 31));
        addressI = new QLineEdit(frame);
        addressI->setObjectName("addressI");
        addressI->setGeometry(QRect(10, 177, 281, 31));
        birthDateI = new QDateEdit(frame);
        birthDateI->setObjectName("birthDateI");
        birthDateI->setGeometry(QRect(73, 217, 218, 31));
        birthDateI->setMaximumDate(QDate(2023, 4, 25));
        birthDateI->setMinimumDate(QDate(1900, 1, 1));
        birthDateI->setDate(QDate(2004, 6, 28));
        birthDateLabel = new QLabel(frame);
        birthDateLabel->setObjectName("birthDateLabel");
        birthDateLabel->setGeometry(QRect(13, 224, 61, 16));
        genderLabel = new QLabel(frame);
        genderLabel->setObjectName("genderLabel");
        genderLabel->setGeometry(QRect(13, 257, 61, 16));
        genderMale = new QRadioButton(frame);
        genderMale->setObjectName("genderMale");
        genderMale->setGeometry(QRect(120, 257, 89, 20));
        genderFemale = new QRadioButton(frame);
        genderFemale->setObjectName("genderFemale");
        genderFemale->setGeometry(QRect(200, 257, 89, 20));
        picLabel = new QLabel(frame);
        picLabel->setObjectName("picLabel");
        picLabel->setGeometry(QRect(13, 290, 61, 16));
        upload = new QPushButton(frame);
        upload->setObjectName("upload");
        upload->setGeometry(QRect(73, 285, 218, 31));
        upload->setAutoDefault(false);
        emailI = new QLineEdit(frame);
        emailI->setObjectName("emailI");
        emailI->setGeometry(QRect(10, 60, 281, 31));
        passwordI = new QLineEdit(frame);
        passwordI->setObjectName("passwordI");
        passwordI->setGeometry(QRect(10, 100, 281, 31));
        passwordI->setEchoMode(QLineEdit::Password);
        ImportandexportcompanymanagementsystemClass->setCentralWidget(centralWidget);

        retranslateUi(ImportandexportcompanymanagementsystemClass);

        QMetaObject::connectSlotsByName(ImportandexportcompanymanagementsystemClass);
    } // setupUi

    void retranslateUi(QMainWindow* ImportandexportcompanymanagementsystemClass)
    {
        ImportandexportcompanymanagementsystemClass->setWindowTitle(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Nahed Management System", nullptr));
        Logo->setText(QString());
        CR->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "\302\251 Copyright reserved for <x-coders/> 2023", nullptr));
        goToCredits->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Credits", nullptr));
        signupLabel->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">Sign Up</span></p></body></html>", nullptr));
        signupLabel_2->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">Log In</span></p></body></html>", nullptr));
        nameI->setText(QString());
        nameI->setPlaceholderText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Name", nullptr));
        phoneNumI->setText(QString());
        phoneNumI->setPlaceholderText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Phone", nullptr));
        addressI->setText(QString());
        addressI->setPlaceholderText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Address", nullptr));
        birthDateLabel->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Birth Date:", nullptr));
        genderLabel->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Gender:", nullptr));
        genderMale->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Male", nullptr));
        genderFemale->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Female", nullptr));
        picLabel->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Picture:", nullptr));
        upload->setText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "upload", nullptr));
        emailI->setText(QString());
        emailI->setPlaceholderText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Email", nullptr));
        passwordI->setText(QString());
        passwordI->setPlaceholderText(QCoreApplication::translate("ImportandexportcompanymanagementsystemClass", "Password2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImportandexportcompanymanagementsystemClass : public Ui_ImportandexportcompanymanagementsystemClass {};
} // namespace Ui

QT_END_NAMESPACE