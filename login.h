#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"database.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT



public:
    DataBase database;
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool userNamePassword();
    QVector<QString> userPass;

    bool validUser;

private slots:
    void on_loginButton_clicked();

    void on_SIGNUPBUTTON_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
