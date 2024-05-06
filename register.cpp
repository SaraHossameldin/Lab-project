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

    // Initialize the database
    //auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
   // temp.setDatabaseName(this->path);
    //temp.open();
    }

Register::~Register()
{
    delete ui;
    delete database;
}

void Register::on_pushButton_OK_clicked()
{
    // Check for errors
    QString username = ui->Username_lineedit->text();
    QString password = ui->PasswordLineedit->text();
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
    QVector<UserInfo> userInfoList = db.getUserInfo();

    // Check if username already exists
    int lastUserId = 0;
    for (const UserInfo& userInfo : userInfoList)
    {
        if (userInfo.username == username)
        {
            ui->label_AlreadyExisting->setVisible(true);
            return;
        }
        lastUserId = userInfo.id;
    }

    //DataBase db;
    UserInfo newUser = UserInfo(lastUserId+1, username, password, 0);
    db.addNewUser(newUser);


    // Add new user information to the database
  //  UserInfo newUser;
   // newUser.username = username;
   // newUser.password = password;
   // userInfoList.push_back(newUser);
    //database->updateUserInfo(userInfoList);

    // Hide the current window and show the login window
    hide();
    Login *login = new Login;
    login->show();
}

void Register::on_pushButton_Cancel_clicked()
{
    hide();
    Login *login= new Login;
    login->show();
}



