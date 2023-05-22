#include "SystemStart.h"


void Importandexportcompanymanagementsystem::backToAllCategories()
{
    ui.categoryView->hide();
    ui.searchInput->clear();
    ui.categories->show();
}

void Importandexportcompanymanagementsystem::productViewSetup(Product* p)
{
    ui.productViewPrice->setAlignment(Qt::AlignRight);
    ui.productViewName->setText(QString::fromStdString(p->getName()));
    ui.productViewPrice->setText(QString::fromStdString(std::to_string(p->getPrice())).left(std::to_string(p->getPrice()).size() - 4) + QString::fromStdString("EGP"));
    ui.productViewDescriptionT->setText(QString::fromStdString(p->getDescription()));
    ui.productViewMassT->setText(QString::fromStdString(std::to_string(p->getMass())).left(std::to_string(p->getMass()).size() - 4) + QString::fromStdString("GM"));
    ui.productViewVolumeT->setText(QString::fromStdString(std::to_string(p->getVolume())).left(std::to_string(p->getVolume()).size() - 4) + QString::fromStdString("ML"));
    ui.productViewLCT->setText(QString::fromStdString(p->getlifeCyclePeriod()));
    ui.productViewPic->setPixmap(QPixmap(QString::fromStdString(p->getImage())));
    ui.categoryView->hide();
    ui.productView->show();
}

Importandexportcompanymanagementsystem::~Importandexportcompanymanagementsystem()
{}

void Importandexportcompanymanagementsystem::loginUser()
{
    Account *userAcc = new Account;

    userAcc->setUsername(ui.userLoginI->text().toLower().toStdString());
    userAcc->setPassword(ui.passwordLoginI->text().toStdString());
    Employee* employee = new Employee;
    User* user = new User;
    employee->account = userAcc;
    employee->Login();
    user->account = userAcc;
    std::string loginResult = user->Login();

    if (loginResult == "User")
    {
        currentUser = user;
        ui.loginAndRegister->hide();
        ui.userHiLabel->setText(QString::fromStdString("Welcome back! " + user->getName()));
        ui.refNumLabel->setText(QString::fromStdString("Ref No.: " + std::to_string(user->getReferecode())));
        generateCategories();
        ui.storeView->show();
    }
    else if (loginResult == "Employee") {
        currentEmployee = employee;
        ui.loginAndRegister->hide();
        ui.userHiLabelE->setText(QString::fromStdString("Welcome back! " + employee->getName()));
        ui.refNumLabelE->setText(QString::fromStdString("Ref No.: " + std::to_string(employee->getReferecode())));
        generateCategoriesE();
        ui.inventoryView->show();
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
    std::string username = ui.userI->text().toLower().toStdString();
    std::string email = ui.emailI->text().toLower().toStdString();
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
    Account* userAcc = new Account(username,password,email,isVerified,accType);
    User* user=new User(name,birthDate,address,phone,gender,filePath,Membership,userAcc);
    std::string registerReturn = user->Register();
    if (registerReturn == "Done") {
        ui.loginAndRegister->hide();
        ui.userHiLabel->setText(QString::fromStdString("Hi! " + user->getName()));
        ui.refNumLabel->setText(QString::fromStdString("Ref No.: " + std::to_string(user->getReferecode())));
        generateCategories();
        ui.storeView->show();
        currentUser = user;
    }
    else {
        ui.signupErrorBox->setText(QString::fromStdString("Error! " + registerReturn));
        ui.signupErrorBox->show();
    }
}
void Importandexportcompanymanagementsystem::uploadFile(QString user)
{
    if (user == QString::fromStdString("")) return;
    QString PhotoSelect = QFileDialog::getOpenFileName(this, tr("Select Image"), "/", tr("Image files(*.jpg;*.jpeg;*.png);;JPG files(*.jpg);;JPEG file(*.jpeg);;PNG files(*.png);;JPG files(*.jpg);;JPEG file(*.jpeg);;PNG files(*.png)"));

    QDir mediaDir(QString::fromStdString("media/")+user.toLower());
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

void Importandexportcompanymanagementsystem::generateCategoriesE()
{
    Category* categories = inventory->getCategories();
    for (int i = 0; i < inventory->getCategoryCount(); i++) {
        QWidget* category = new QWidget(ui.scrollAreaWidgetContents2);
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
        QPushButton* editCategoryBtn = new QPushButton(category);
        editCategoryBtn->setObjectName("editCategoryBtn" + QString::fromStdString("_" + std::to_string(i)));
        editCategoryBtn->setGeometry(QRect(850, 33, 50, 50));
        editCategoryBtn->setCursor(QCursor(Qt::PointingHandCursor));
        editCategoryBtn->setStyleSheet(QString::fromUtf8("#editCategoryBtn_" + std::to_string(i) + "{\n"
            "border: none;\n"
            "border-radius:25px;\n"
            "background-color:white;\n"
            "}\n"
            "#editCategoryBtn_" + std::to_string(i) + "::hover{\n"
            "background-color:rgb(200, 200, 200);\n"
            "}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("./media/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editCategoryBtn->setIcon(icon3);
        editCategoryBtn->setIconSize(QSize(17, 16));
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
        ui.verticalLayout_2->addWidget(category, i, Qt::AlignTop);
    }
}

void Importandexportcompanymanagementsystem::generateProducts(int j)
{
    currentCategory = j;
    QLayoutItem* child;
    while (ui.gridLayout->count() != 0) {
        child = ui.gridLayout->takeAt(0);
        if (child->widget() != nullptr) {
            delete child->widget();
        }
        delete child;
    }
    int n = inventory->getCategories()[j].getNumOfProducts();
    Product* products = inventory->getCategories()[j].getProducts();
    if (n != 0) {
        ui.gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
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
            productPrice->setText(QString::fromStdString(std::to_string(products[i].getPrice())).left(QString::fromStdString(std::to_string(products[i].getPrice())).size() - 4) + QString::fromStdString("EGP"));
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
            connect(productBtn, &QPushButton::clicked, this, [=]() {productViewSetup(&products[i]); });
            ui.gridLayout->addWidget(product, i / 5, i % 5, 1, 1);
        }
    }
    else {
        ui.gridLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QLabel* categoryEmptyLabel = new QLabel(ui.scrollAreaWidgetContents_2);
        categoryEmptyLabel->setObjectName("categoryEmptyLabel");
        categoryEmptyLabel->setStyleSheet(QString::fromUtf8("#categoryEmptyLabel{\n"
            "color:#777;\n"
            "}"));
        categoryEmptyLabel->setText(QString::fromStdString("Category is empty temporarily"));
        ui.gridLayout->addWidget(categoryEmptyLabel, 0, 0, 1, 1);
    }
    ui.categories->hide();
    ui.categoryView->show();
}

void Importandexportcompanymanagementsystem::generateProducts(int* products)
{
    QLayoutItem* child;
    while (ui.gridLayout->count() != 0) {
        child = ui.gridLayout->takeAt(0);
        if (child->widget() != nullptr) {
            delete child->widget();
        }
        delete child;
    }
    Product* all = inventory->getCategories()[currentCategory].getProducts();
    if (products[0] != 0) {
        ui.gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        for (int i = 1; i <= products[0]; i++) {
            QFrame* product = new QFrame(ui.scrollAreaWidgetContents_2);
            product->setObjectName("product_" + QString::fromStdString(std::to_string(products[i])));
            product->setMinimumSize(QSize(194, 240));
            product->setMaximumSize(QSize(194, 240));
            product->setStyleSheet(QString::fromUtf8("#product_" + std::to_string(products[i]) + "{\n"
                "background-color:#fff;\n"
                "border-radius:25%;\n"
                "border: 0.5px solid #2b094a;\n"
                "}"));
            product->setFrameShape(QFrame::StyledPanel);
            product->setFrameShadow(QFrame::Raised);
            QLabel* productImg = new QLabel(product);
            productImg->setObjectName("productImg_" + QString::fromStdString(std::to_string(products[i])));
            productImg->setGeometry(QRect(37, 30, 121, 121));
            productImg->setTextFormat(Qt::PlainText);
            productImg->setPixmap(QPixmap(QString::fromUtf8(all[products[i]].getImage())));
            productImg->setScaledContents(true);
            QLabel* productName = new QLabel(product);
            productName->setObjectName("productName_" + QString::fromStdString(std::to_string(products[i])));
            productName->setText(QString::fromStdString(all[products[i]].getName()));
            productName->setGeometry(QRect(20, 170, 100, 20));
            productName->setStyleSheet(QString::fromUtf8("#productName_" + std::to_string(products[i]) + "{\n"
                "color:#2b094a;\n"
                "font-weight:700;\n"
                "}"));
            QLabel* productPrice = new QLabel(product);
            productPrice->setObjectName("productPrice_" + QString::fromStdString(std::to_string(products[i])));
            productPrice->setText(QString::fromStdString(std::to_string(all[products[i]].getPrice())).left(QString::fromStdString(std::to_string(all[products[i]].getPrice())).size() - 4) + QString::fromStdString("EGP"));
            productPrice->setGeometry(QRect(20, 190, 100, 20));
            productPrice->setStyleSheet(QString::fromUtf8("#productPrice_" + std::to_string(products[i]) + "{\n"
                "color:#2b094a;\n"
                "font-weight:700;\n"
                "}"));
            QPushButton* productBtn = new QPushButton(product);
            productBtn->setObjectName("productBtn_" + QString::fromStdString(std::to_string(products[i])));
            productBtn->setGeometry(QRect(130, 170, 51, 41));
            productBtn->setCursor(QCursor(Qt::PointingHandCursor));
            productBtn->setStyleSheet(QString::fromUtf8("#productBtn_" + std::to_string(products[i]) + "{\n"
                "background-color:#39b105;\n"
                "}\n"
                "#productBtn_" + std::to_string(products[i]) + "::hover{\n"
                "background-color:#fff;\n"
                "border:1px solid #000;\n"
                "}"));
            QIcon icon2;
            icon2.addFile(QString::fromUtf8("media/right arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
            productBtn->setIcon(icon2);
            connect(productBtn, &QPushButton::clicked, this, [=]() {productViewSetup(&all[products[i]]); });
            ui.gridLayout->addWidget(product, (i - 1) / 5, (i - 1) % 5, 1, 1);
        }
    }
    else {
        ui.gridLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QLabel* categoryEmptyLabel = new QLabel(ui.scrollAreaWidgetContents_2);
        categoryEmptyLabel->setObjectName("categoryEmptyLabel");
        categoryEmptyLabel->setStyleSheet(QString::fromUtf8("#categoryEmptyLabel{\n"
            "color:#777;\n"
            "}"));
        categoryEmptyLabel->setText(QString::fromStdString("No results"));
        ui.gridLayout->addWidget(categoryEmptyLabel, 0, 0, 1, 1);
    }
}

void Importandexportcompanymanagementsystem::backToCategory() {
    ui.productView->hide();
    ui.categoryView->show();
}

void Importandexportcompanymanagementsystem::editAcc() 
{
    ui.editName->setText(QString::fromStdString(currentUser->getName()));
    ui.editEmail->setText(QString::fromStdString(currentUser->account->getEmail()));
    ui.editAddress->setText(QString::fromStdString(currentUser->getAddress()));
    ui.editPhonenum->setText(QString::fromStdString(currentUser->getPhonenum()));
    if (currentUser->getMembership() == "Prime") ui.isPrimeEdit->setChecked(true);
    connect(ui.saveEditAccBtn, &QPushButton::clicked, this, &Importandexportcompanymanagementsystem::saveChanges);
    ui.editAccountView->show();
}
std::string Importandexportcompanymanagementsystem::saveChanges()
{
        std::string newName = ui.editName->text().toStdString();
        std::string newEmail = ui.editEmail->text().toStdString();
        std::string newPassword = ui.editPassword->text().toStdString();
        std::string newPhone = ui.editPhonenum->text().toStdString();
        std::string newAddress = ui.editAddress->text().toStdString();
        bool isPrime = ui.isPrimeEdit->isChecked();

        if (newName == "")
        {
            return "name must be filled";
        }
        std::regex nameRegex("[A-Za-z]+");
        if (!std::regex_match(newName, nameRegex))
        {
            return "letters and space are only allowed in name";
        }

        if (newEmail == "")
        {
            return "email must be filled";
        }
        std::regex emailRegex("(\\w+)((\\.|_|-)(\\w|\\w+))?@(\\w+)(\\.(\\w+))+");
        if (!std::regex_match(newEmail, emailRegex))
        {
            return "invalid email";
        }

        if (newPassword == "")
        {
            return "password must be filled";
        }
        std::regex passwordRegex(".{8,}");
        if (!std::regex_match(newPassword, passwordRegex))
        {
            return "invalid password";
        }

        if (newPhone == "")
        {
            return "phone must be filled";
        }
        std::regex phoneRegex("\\d{11}");
        if (!std::regex_match(newPhone, phoneRegex))
        {
            return "invalid phone ";
        }


        if (newAddress == "")
        {
            return "address must be filled";
        }
        std::regex addressRegex("^[^,]+$");
        if (!std::regex_match(newAddress, addressRegex))
        {
            return "invalid address";
        }


}

void Importandexportcompanymanagementsystem::closeEditAcc() 
{
    ui.editAccountView->hide();

}

void Importandexportcompanymanagementsystem::search(std::string word)
{
    int* searchRes = inventory->getCategories()[currentCategory].search(word);
    generateProducts(searchRes);
}

void Importandexportcompanymanagementsystem::addCash(double amount)
{
    currentUser->setBalance(currentUser->getBalance() + amount);
    ui.currentCreditL->setText(QString::fromStdString("Your current credit is ") + QString::fromStdString(std::to_string(currentUser->getBalance())).left(QString::fromStdString(std::to_string(currentUser->getBalance())).size()-4) + QString::fromStdString(" EGP"));
    ui.currentCreditL->setAlignment(Qt::AlignCenter);
    ui.addCreditAmount->setValue(10.00);
    currentUser->updateBalance();
}

void Importandexportcompanymanagementsystem::viewAddCash()
{
    ui.addCreditView->show();
    ui.addCreditAmount->setValue(10.);
    ui.currentCreditL->setAlignment(Qt::AlignCenter);
    ui.currentCreditL->setText(QString::fromStdString("Your current credit is ") + QString::fromStdString(std::to_string(currentUser->getBalance())).left(QString::fromStdString(std::to_string(currentUser->getBalance())).size() - 4) + QString::fromStdString(" EGP"));
}
