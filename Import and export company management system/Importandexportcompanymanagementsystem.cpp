#include "Importandexportcompanymanagementsystem.h"

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    QString username = ui.userLoginI->text();
    QString password = ui.passwordLoginI->text();

    std::ifstream handler("test.csv");

    std::string line;
    bool found = false;
    while (std::getline(handler, line))
    {
        QString qline = QString::fromStdString(line);

        QStringList columns = qline.split(",");
        if (columns[1] == username && columns[3] == password)
        {
            found = true;
            QString message = "Welcome Back " + username + "\n";
            QMessageBox::information(this, tr("Login Successful"), message);
            break;
        }
    }
    handler.close();
    if (!found)
    {
        QMessageBox::information(this, tr("Login Failed"), tr("Invalid username or password."));
    }
}

void Importandexportcompanymanagementsystem::customizeUI(std::string logoPath) {
    ui.Logo->setPixmap(QPixmap(QString::fromStdString(logoPath)));
}

void Importandexportcompanymanagementsystem::registerUser()
{
    std::ofstream handler("test.csv", std::ios::app);
    if (handler.is_open()) {
        QString name = ui.nameI->text();
        QString username = ui.userI->text();
        QString email = ui.emailI->text();
        QString password = ui.passwordI->text();
        QString phone = ui.phoneNumI->text();
        QString address = ui.addressI->text();
        QString gender;
        QString prime;

        if (ui.genderMale->isChecked())
        {
            gender = "male";
        }
        else if (ui.genderFemale->isChecked())
        {
            gender = "female";
        }

        if (ui.isPrimeCheckbox->isChecked())
        {
            prime = "Prime";
        }
        else
        {
            prime = "Normal";
        }


        QString PhotoSelect = QFileDialog::getOpenFileName(this, tr("Select Image"), "/", tr("Image files(*.jpg;*.jpeg;*.png);;JPG files(*.jpg);;JPEG file(*.jpeg);;PNG files(*.png);;JPG files(*.jpg);;JPEG file(*.jpeg);;PNG files(*.png)"));
            
        QDir mediaDir("media");
        if (!mediaDir.exists())
        {
            mediaDir.mkpath(".");
        }

        QFileInfo Info(PhotoSelect);
        QString FilePath = mediaDir.path() + "/" + Info.fileName();
        QFile::copy(PhotoSelect, FilePath);



        handler << name.toStdString() << "," << username.toStdString() << "," << email.toStdString() << "," << password.toStdString() << "," << phone.toStdString() << "," << address.toStdString() << "," << gender.toStdString() << "," << FilePath.toStdString() << "," << prime.toStdString();
        handler.close();

        QMessageBox::information(this, tr("Registration Successful"), tr("Registered Successfully"));
    }
}
