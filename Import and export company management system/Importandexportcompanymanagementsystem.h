#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Importandexportcompanymanagementsystem.h"

class Importandexportcompanymanagementsystem : public QMainWindow
{
    Q_OBJECT

public:
    Importandexportcompanymanagementsystem(QWidget *parent = nullptr);
    ~Importandexportcompanymanagementsystem();

private:
    Ui::ImportandexportcompanymanagementsystemClass ui;
};
