#include "SystemStart.h"

void Importandexportcompanymanagementsystem::backToAllCategories()
{
    ui.categoryView->hide();
    ui.searchInput->clear();
    ui.categories->show();
}

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    Account userAcc;

    userAcc.setUsername(ui.userLoginI->text().toStdString());
    userAcc.setPassword(ui.passwordLoginI->text().toStdString());

    User user;
    user.account = &userAcc;
    std::string loginResult = user.Login();

    if (loginResult == "User")
    {
        ui.loginAndRegister->hide();
        ui.userHiLabel->setText(QString::fromStdString("Welcome back! " + user.account->getUsername()));
        ui.refNumLabel->setText(QString::fromStdString("Ref No.: " + std::to_string(user.getReferecode())));
        generateCategories();
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
        generateCategories();
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
    filePath = FilePath.toStdString() ;
}

void Importandexportcompanymanagementsystem::generateCategories()
{
    Category* categories = inventory->getCategories();
    for (int i = 0; i < inventory->getCategoryCount(); i++) {
        QWidget* category = new QWidget(ui.scrollAreaWidgetContents);
        category->setObjectName("category" + QString::fromStdString("_" + std::to_string(i)));
        category->setMinimumSize(QSize(1004, 120));
        category->setMaximumSize(QSize(1004, 120));
        category->setStyleSheet(QString::fromUtf8("#category_" + std::to_string(i) + "{\n"
            "background-color:rgb(60, 116, 221);\n"
            "border-radius: 15%;\n"
            "}"));
        QLabel* categoryLabel = new QLabel(category);
        categoryLabel->setObjectName("categoryLabel" + QString::fromStdString("_" + std::to_string(i)));
        categoryLabel->setText(QString::fromStdString(categories[i].getName()));
        categoryLabel->setGeometry(QRect(140, 44, 211, 31));
        categoryLabel->setStyleSheet(QString::fromUtf8("#categoryLabel_" + std::to_string(i) + "{\n"
            "color:white;\n"
            "font-size: 18px;\n"
            "font-weight: 700;\n"
            "}"));
        QLabel* categoryPic = new QLabel(category);
        categoryPic->setObjectName("categoryPic" + QString::fromStdString("_" + std::to_string(i)));
        categoryPic->setGeometry(QRect(50, 40, 41, 41));
        categoryPic->setPixmap(QPixmap(QString::fromStdString(categories[i].getImage())));
        categoryPic->setScaledContents(true);
        QPushButton* categoryBtn = new QPushButton(category);
        categoryBtn->setObjectName("categoryBtn" + QString::fromStdString("_" + std::to_string(i)));
        categoryBtn->setGeometry(QRect(910, 33, 50, 50));
        categoryBtn->setCursor(QCursor(Qt::PointingHandCursor));
        categoryBtn->setStyleSheet(QString::fromUtf8("#categoryBtn_" + std::to_string(i) + "{\n"
            "border: none;\n"
            "border-radius:25px;\n"
            "background-color:white;\n"
            "}\n"
            "#categoryBtn_" + std::to_string(i) + "::hover{\n"
            "background-color:rgb(200, 200, 200);\n"
            "}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("./media/right arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        categoryBtn->setIcon(icon2);
        categoryBtn->setIconSize(QSize(17, 16));
        connect(categoryBtn, &QPushButton::clicked, this, [=]() {generateProducts(i); });
        ui.verticalLayout->addWidget(category, i, Qt::AlignTop);
    }
}

void Importandexportcompanymanagementsystem::generateProducts(int j)
{
    QLayoutItem* child;
    while (ui.gridLayout->count() != 0) {
        child = ui.gridLayout->takeAt(0);
        if (child->widget() != 0) {
            delete child->widget();
        }
        delete child;
    }
    int n = inventory->getCategories()[j].getNumOfProducts();
    Product* products = inventory->getCategories()[j].getProducts();
    for (int i = 0; i < n; i++) {
        QFrame* product = new QFrame(ui.scrollAreaWidgetContents_2);
        product->setObjectName("product_" + QString::fromStdString(std::to_string(i)));
        product->setMinimumSize(QSize(194, 240));
        product->setMaximumSize(QSize(194, 240));
        product->setStyleSheet(QString::fromUtf8("#product_" + std::to_string(i) + "{\n"
            "background-color:#fff;\n"
            "border-radius:25%;\n"
            "border: 0.5px solid #2b094a;\n"
            "}"));
        product->setFrameShape(QFrame::StyledPanel);
        product->setFrameShadow(QFrame::Raised);
        QLabel* productImg = new QLabel(product);
        productImg->setObjectName("productImg_" + QString::fromStdString(std::to_string(i)));
        productImg->setGeometry(QRect(37, 30, 121, 121));
        productImg->setTextFormat(Qt::PlainText);
        productImg->setPixmap(QPixmap(QString::fromUtf8(products[i].getImage())));
        productImg->setScaledContents(true);
        QLabel* productName = new QLabel(product);
        productName->setObjectName("productName_" + QString::fromStdString(std::to_string(i)));
        productName->setText(QString::fromStdString(products[i].getName()));
        productName->setGeometry(QRect(20, 170, 100, 20));
        productName->setStyleSheet(QString::fromUtf8("#productName_" + std::to_string(i) + "{\n"
            "color:#2b094a;\n"
            "font-weight:700;\n"
            "}"));
        QLabel* productPrice = new QLabel(product);
        productPrice->setObjectName("productPrice_" + QString::fromStdString(std::to_string(i)));
        productPrice->setText(QString::fromStdString(std::to_string(products[i].getPrice())).left(QString::fromStdString(std::to_string(products[i].getPrice())).size()-4));
        productPrice->setGeometry(QRect(20, 190, 100, 20));
        productPrice->setStyleSheet(QString::fromUtf8("#productPrice_" + std::to_string(i) + "{\n"
            "color:#2b094a;\n"
            "font-weight:700;\n"
            "}"));
        QPushButton* productBtn = new QPushButton(product);
        productBtn->setObjectName("productBtn_" + QString::fromStdString(std::to_string(i)));
        productBtn->setGeometry(QRect(130, 170, 51, 41));
        productBtn->setCursor(QCursor(Qt::PointingHandCursor));
        productBtn->setStyleSheet(QString::fromUtf8("#productBtn_" + std::to_string(i) + "{\n"
            "background-color:#39b105;\n"
            "}\n"
            "#productBtn_" + std::to_string(i) + "::hover{\n"
            "background-color:#fff;\n"
            "border:1px solid #000;\n"
            "}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("media/right arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        productBtn->setIcon(icon2);
        ui.gridLayout->addWidget(product, i / 5, i % 5, 1, 1);
    }
    ui.categories->hide();
    ui.categoryView->show();
}

