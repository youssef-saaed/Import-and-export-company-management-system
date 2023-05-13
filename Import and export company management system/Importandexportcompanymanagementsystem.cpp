#include "SystemStart.h"

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    Account userAcc;

    userAcc.setUsername(ui.userLoginI->text().toStdString());
    userAcc.setPassword(ui.passwordLoginI->text().toStdString());

    if (1)
    {
        User user;
        user.account = &userAcc;

        std::string loginResult = user.Login();

        if (!(loginResult == "Invalid username or password" || loginResult == "username is required" || loginResult == "password is required"))
        {
            ui.loginAndRegister->hide();
            ui.userHiLabel->setText(QString::fromStdString("Welcome back! " + user.account->getUsername()));
            ui.refNumLabel->setText(QString::fromStdString("Ref No.: " + std::to_string(user.getReferecode())));
            ui.storeView->show();
        }
        else
        {
            ui.loginErrorBox->setText(QString::fromStdString("Error! " + loginResult));
            ui.loginErrorBox->show();
        }
    
}
void Importandexportcompanymanagementsystem::customizeUI(std::string logoPath)
{
    ui.Logo->setPixmap(QPixmap(QString::fromStdString(logoPath)));
}

void Importandexportcompanymanagementsystem::registerUser()
{
    std::string name = ui.nameI->text().toStdString();
    std::string username = ui.userI->text().toStdString();
    std::string email = ui.emailI->text().toStdString();
    std::string password = ui.passwordI->text().toStdString();
    std::string phone = ui.phoneNumI->text().toStdString();
    std::string address = ui.addressI->text().toStdString();
    QStringList bdList = ui.birthDateI->text().split('/');
    int day = bdList[1].trimmed().toInt();
    int month = bdList[0].trimmed().toInt();
    int year = bdList[2].trimmed().toInt();
    Gender gender;
    std::string Membership;
    bool isVerified = false;
    std::string accType = "User";

    if (ui.genderMale->isChecked())
    {
        gender = Male;
    }
    else if (ui.genderFemale->isChecked())
    {
        gender = Female;
    }
    else {
        gender = None;
    }

    if (ui.isPrimeCheckbox->isChecked())
    {
        Membership = "Prime";
    }
    else
    {
        Membership = "Normal";
    }

    Date birthDate(day,month,year);
    Account userAcc(username,password,email,isVerified,accType);
    User user(name,birthDate,address,phone,gender,filePath,Membership,&userAcc);
    std::string registerReturn = user.Register();
    if (registerReturn == "Done") {
        ui.loginAndRegister->hide();
        ui.userHiLabel->setText(QString::fromStdString("Hi! " + user.account->getUsername()));
        ui.refNumLabel->setText(QString::fromStdString("Ref No.: " + std::to_string(user.getReferecode())));
        ui.storeView->show();
    }
    else {
        ui.signupErrorBox->setText(QString::fromStdString("Error! " + registerReturn));
        ui.signupErrorBox->show();
    }
}
void Importandexportcompanymanagementsystem::uploadFile(QString user)
{
    if (user == QString::fromStdString("")) user = "Other Users";
    QString PhotoSelect = QFileDialog::getOpenFileName(this, tr("Select Image"), "/", tr("Image files(*.jpg;*.jpeg;*.png);;JPG files(*.jpg);;JPEG file(*.jpeg);;PNG files(*.png);;JPG files(*.jpg);;JPEG file(*.jpeg);;PNG files(*.png)"));

    QDir mediaDir(QString::fromStdString("media/")+user);
    if (!mediaDir.exists())
    {
        mediaDir.mkpath(".");
    }

    QFileInfo Info(PhotoSelect);
    QString FilePath = mediaDir.path() + "/" + Info.fileName();
    QFile::copy(PhotoSelect, FilePath);
    filePath = FilePath.toStdString();
}

