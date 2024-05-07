#include "register.h"
#include "ui_register.h"
#include "findproduct.h"
#include "login.h"
#include <QString>
#include <QVector>
#include "database.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);

    // Set error messages to false initially
    ui->label_AlreadyExisting->setVisible(false);
    ui->label_NotMatching->setVisible(false);
    ui->label_FilledError->setVisible(false);
    }

Register::~Register()
{
    delete ui;
    delete database;
}

void Register::on_pushButton_OK_clicked()
{
    //store the text written by the user in a QString called username
    QString username = ui->Username_lineedit->text();
    //store the text written by the user in a QString called password
    QString password = ui->PasswordLineedit->text();
    //store the text written by the user in a QString called retypeusername
    QString retypepassword = ui->RetypePasswordlineedit->text();

    // Reset error labels
    ui->label_NotMatching->setVisible(false);
    ui->label_AlreadyExisting->setVisible(false);
    ui->label_FilledError->setVisible(false);

    // Check if any field is empty
    if (username.isEmpty() || password.isEmpty() || retypepassword.isEmpty())
    {
        ui->label_FilledError->setVisible(true);
        return;
    }

    // Check for password mismatch
    if (password != retypepassword)
    {
        ui->label_NotMatching->setVisible(true);
        return;
    }


    // Get user information from database
    DataBase db;
    //vector of type UserInfo called userInfoList initilaized to be like the vector
    //returned from the getUserInfo() function
    QVector<UserInfo> userInfoList = db.getUserInfo();

    // Check if username already exists
    int lastUserId = 0; //to get the id of the last user
    //loop to check if the username is already in the vector
    for (const UserInfo& userInfo : userInfoList)
    {
        if (userInfo.username == username)
        {
            //if it is found show the error label
            ui->label_AlreadyExisting->setVisible(true);
            return;
        }
        //new value of the last id
        lastUserId = userInfo.id;
    }
    //create a new user with 1+ the id of the last user and the username and password
    //the user eneterd in the lineedits
    UserInfo newUser = UserInfo(lastUserId+1, username, password, 0);
    db.addNewUser(newUser);

    // Hide the current window and show the login window
    hide();
    Login *login = new Login;
    login->show();
}

void Register::on_pushButton_Cancel_clicked()
{
    // Hide the current window and show the login window to try and login again
    hide();
    Login *login= new Login;
    login->show();
}



