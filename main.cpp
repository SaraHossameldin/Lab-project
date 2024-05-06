#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //TODO check DB file exist
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();

}
