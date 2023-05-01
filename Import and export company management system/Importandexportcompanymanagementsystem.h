#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_Importandexportcompanymanagementsystem.h"

class Importandexportcompanymanagementsystem : public QMainWindow
{
    Q_OBJECT

public:
    Importandexportcompanymanagementsystem(QWidget* parent = nullptr);
    ~Importandexportcompanymanagementsystem();

private slots:
    void registerUser();

private:
    Ui::ImportandexportcompanymanagementsystemClass ui;
};
