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
{   //take the text entered by the user in the line edit for username and store it in a QString named username
    QString username = ui->usernamelineedit->text();
    //take the text entered by the user in the line edit for password and store it in a QString named password
    QString password = ui->LineEditPassword->text();

    //create a vector of type UserInfo and initialize it to be the same as the vector returned by the function getUserInfo
    QVector<UserInfo> userInfoList = database.getUserInfo();
    //loop over the new vector to compare the enetered username and password with the usernames and passwords in the vector
    for (const auto& userInfo : userInfoList)
    {
        //if the username and password are  found in the vector, then login is successful
        if (userInfo.username == username && userInfo.password == password)
        {
            return true;
        }
    }
    return false;

}

void Login::on_loginButton_clicked()
{   //take the text entered by the user in the line edit for username and store it in a QString named username
    QString username = ui->usernamelineedit->text();
    //take the text entered by the user in the line edit for password and store it in a QString named password
    QString password = ui->LineEditPassword->text();
     //create a vector of type UserInfo and initialize it to be the same as the vector returned by the function getUserInfo
    QVector<UserInfo> userInfoList = database.getUserInfo();
    //validUser is set to be false by deafult, and isAdmin by default zero, which means the user is not an admin
    bool validUser = false;
    int isAdmin = 0;
    //loop to compare the eneterd username and password with the usernames and passwords in the vector
    for (const auto& userInfo : userInfoList)
    {
        if (userInfo.username == username && userInfo.password == password)
        {
            //Now, validUser is true
            validUser = true;
            //Now, get the value stored in isAdmin to check if the user is admin or user
            isAdmin = userInfo.isAdmin; // Retrieve the isAdmin value
            break;
        }
    }
    if (validUser)

    {   //the user is an admin
        if (isAdmin==1)
        {
            //hide this window
            hide();
            //create a new AdminWindow
            AdminWindow *adminwindow= new AdminWindow;
            //show the AdminWindow
            adminwindow->show();
        }
        else //not an admin
        {
            //hide this window
            hide();
            //create a new UserWindow
            UserWindow *store= new UserWindow(username);
            //show the UserWindow
            store->show();
        }
    }
    else //(!validUser)
    {
        //show error message
        QMessageBox::information(this, "Error", "Incorrect username or password");
        //clear the lineedits
        ui->usernamelineedit->clear();
        ui->LineEditPassword->clear();
    }
}

//to allow the user to register
void Login::on_SIGNUPBUTTON_clicked()
{
    //hide this window
    hide();
    //create a new Register window
    Register *registerDialog = new Register(this);
    //show the new Regiser window
    registerDialog->show();
}


