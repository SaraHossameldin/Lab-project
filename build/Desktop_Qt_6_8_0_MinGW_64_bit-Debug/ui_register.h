/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLineEdit *Username_lineedit;
    QLineEdit *PasswordLineedit;
    QLineEdit *RetypePasswordlineedit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_OK;
    QLabel *label_AlreadyExisting;
    QLabel *label_NotMatching;
    QLabel *label_FilledError;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(364, 329);
        Username_lineedit = new QLineEdit(Register);
        Username_lineedit->setObjectName("Username_lineedit");
        Username_lineedit->setGeometry(QRect(10, 50, 171, 20));
        PasswordLineedit = new QLineEdit(Register);
        PasswordLineedit->setObjectName("PasswordLineedit");
        PasswordLineedit->setGeometry(QRect(10, 130, 171, 20));
        PasswordLineedit->setEchoMode(QLineEdit::Password);
        RetypePasswordlineedit = new QLineEdit(Register);
        RetypePasswordlineedit->setObjectName("RetypePasswordlineedit");
        RetypePasswordlineedit->setGeometry(QRect(10, 220, 171, 21));
        RetypePasswordlineedit->setEchoMode(QLineEdit::Password);
        label = new QLabel(Register);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 61, 16));
        label_2 = new QLabel(Register);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 100, 61, 20));
        label_3 = new QLabel(Register);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 180, 91, 20));
        pushButton_OK = new QPushButton(Register);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setGeometry(QRect(120, 280, 80, 18));
        label_AlreadyExisting = new QLabel(Register);
        label_AlreadyExisting->setObjectName("label_AlreadyExisting");
        label_AlreadyExisting->setGeometry(QRect(210, 50, 111, 16));
        label_NotMatching = new QLabel(Register);
        label_NotMatching->setObjectName("label_NotMatching");
        label_NotMatching->setGeometry(QRect(200, 220, 181, 20));
        label_FilledError = new QLabel(Register);
        label_FilledError->setObjectName("label_FilledError");
        label_FilledError->setGeometry(QRect(60, 250, 141, 16));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Register", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "Retype Password:", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Register", "OK", nullptr));
        label_AlreadyExisting->setText(QCoreApplication::translate("Register", "*Already Existing", nullptr));
        label_NotMatching->setText(QCoreApplication::translate("Register", "* Not Matching", nullptr));
        label_FilledError->setText(QCoreApplication::translate("Register", "*All Fields Must be Filled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
