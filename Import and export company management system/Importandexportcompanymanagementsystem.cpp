#include "SystemStart.h"

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    Account user;
    user.setUsername(ui.userLoginI->text().toStdString());
    user.setPassword(ui.passwordLoginI->text().toStdString());
    
    std::ifstream handler("test.csv");

    std::string line;
    bool found = false;
    while (std::getline(handler, line))
    {
        QString qline = QString::fromStdString(line);

        QStringList columns = qline.split(",");
        if (columns[1].toStdString()==user.getUsername() &&  user.getPassword() == columns[3].toStdString())
        {
            found = true;
            QString message = "Welcome Back " + QString::fromStdString(user.getUsername()) + "\n";
            QMessageBox::information(this, tr("Login Successful"), message);
            break;
        }
    }
    handler.close();
    
    if (found==false )
    {
        QMessageBox::information(this, tr("Login Failed"), tr("Invalid username or password."));
    }
}

void Importandexportcompanymanagementsystem::customizeUI(std::string logoPath) {
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
    std::string bd = ui.birthDateI->text().toStdString();
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

    Date birthDate(bd);
    Account userAcc(username,password,email,isVerified,accType);
    User user(name,birthDate,address,phone,gender,filePath,Membership,userAcc);
    user.Register();
}
void Importandexportcompanymanagementsystem::uploadFile(QString user) {
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

