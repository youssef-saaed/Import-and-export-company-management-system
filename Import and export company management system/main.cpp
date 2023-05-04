#pragma once
#include "Importandexportcompanymanagementsystem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Importandexportcompanymanagementsystem w;
    w.show();
    return a.exec();
}