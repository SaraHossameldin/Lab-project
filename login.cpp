#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include "register.h"
#include "database.h"
#include "findproduct.h"
#include "userwindow.h"
#include "adminwindow.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

bool Login::userNamePassword()
{
   /* QString username = ui->usernamelineedit->text();
    QString password = ui->LineEditPassword->text();

    for (int i = 0; i < DataBase.size(); i += 2)
    {
        if (username == DataBase[i] && password == DataBase[i + 1])
            return true;
    }
    return false;
*/
    QString username = ui->usernamelineedit->text();
    QString password = ui->LineEditPassword->text();

    QVector<UserInfo> userInfoList = database.getUserInfo();
    for (const auto& userInfo : userInfoList)
    {
        if (userInfo.username == username && userInfo.password == password)
        {
            return true;
        }
    }
    return false;

}

void Login::on_loginButton_clicked()
{
    QString username = ui->usernamelineedit->text();
    QString password = ui->LineEditPassword->text();
    QVector<UserInfo> userInfoList = database.getUserInfo();
    bool validUser = false;
    int isAdmin = 0;
    for (const auto& userInfo : userInfoList)
    {
        if (userInfo.username == username && userInfo.password == password)
        {
            validUser = true;
            isAdmin = userInfo.isAdmin; // Retrieve the isAdmin value
            break;
        }
    }
    if (validUser)
    {
        if (isAdmin==1)
        {
            hide();
            AdminWindow *adminwindow= new AdminWindow;
            adminwindow->show();
        }
        else
        {
            hide();
            UserWindow *store= new UserWindow(username);
            store->show();
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "Incorrect username or password");
        ui->usernamelineedit->clear();
        ui->LineEditPassword->clear();
    }
}

void Login::on_SIGNUPBUTTON_clicked()
{
    hide();
    Register *registerDialog = new Register(this);
    registerDialog->show();
}


