/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *LOGINLabel;
    QLabel *usernameLABEL;
    QLineEdit *usernamelineedit;
    QLineEdit *LineEditPassword;
    QLabel *PasswordLabel;
    QLabel *noaccountlabel;
    QPushButton *loginButton;
    QPushButton *SIGNUPBUTTON;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(459, 660);
        LOGINLabel = new QLabel(Login);
        LOGINLabel->setObjectName("LOGINLabel");
        LOGINLabel->setGeometry(QRect(60, 30, 231, 91));
        usernameLABEL = new QLabel(Login);
        usernameLABEL->setObjectName("usernameLABEL");
        usernameLABEL->setGeometry(QRect(30, 200, 151, 20));
        usernamelineedit = new QLineEdit(Login);
        usernamelineedit->setObjectName("usernamelineedit");
        usernamelineedit->setGeometry(QRect(20, 240, 221, 31));
        LineEditPassword = new QLineEdit(Login);
        LineEditPassword->setObjectName("LineEditPassword");
        LineEditPassword->setGeometry(QRect(20, 320, 221, 31));
        LineEditPassword->setEchoMode(QLineEdit::Password);
        PasswordLabel = new QLabel(Login);
        PasswordLabel->setObjectName("PasswordLabel");
        PasswordLabel->setGeometry(QRect(30, 280, 91, 21));
        noaccountlabel = new QLabel(Login);
        noaccountlabel->setObjectName("noaccountlabel");
        noaccountlabel->setGeometry(QRect(200, 470, 211, 20));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(60, 420, 171, 29));
        SIGNUPBUTTON = new QPushButton(Login);
        SIGNUPBUTTON->setObjectName("SIGNUPBUTTON");
        SIGNUPBUTTON->setGeometry(QRect(290, 500, 93, 29));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        LOGINLabel->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700; font-style:italic; color:#0000ff;\">LOGIN</span></p></body></html>", nullptr));
        usernameLABEL->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#0000ff;\">Username/Email</span></p></body></html>", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#0000ff;\">Password</span></p></body></html>", nullptr));
        noaccountlabel->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:11pt; font-style:italic; color:#aa0000;\">Don't have an account?</span></p></body></html>", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "LOGIN", nullptr));
        SIGNUPBUTTON->setText(QCoreApplication::translate("Login", "Sign-Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
