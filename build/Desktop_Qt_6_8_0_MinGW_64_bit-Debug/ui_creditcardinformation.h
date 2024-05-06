/********************************************************************************
** Form generated from reading UI file 'creditcardinformation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITCARDINFORMATION_H
#define UI_CREDITCARDINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreditCardInformation
{
public:
    QLineEdit *lineEditName;
    QLineEdit *lineEdit_CardNumber;
    QLineEdit *lineEdit_CVV;
    QPushButton *pushButtonConfirmPurchase;
    QPushButton *pushButton_BacktoCart;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *CreditCardInformation)
    {
        if (CreditCardInformation->objectName().isEmpty())
            CreditCardInformation->setObjectName("CreditCardInformation");
        CreditCardInformation->resize(400, 300);
        lineEditName = new QLineEdit(CreditCardInformation);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(20, 50, 113, 20));
        lineEdit_CardNumber = new QLineEdit(CreditCardInformation);
        lineEdit_CardNumber->setObjectName("lineEdit_CardNumber");
        lineEdit_CardNumber->setGeometry(QRect(20, 100, 113, 20));
        lineEdit_CVV = new QLineEdit(CreditCardInformation);
        lineEdit_CVV->setObjectName("lineEdit_CVV");
        lineEdit_CVV->setGeometry(QRect(20, 160, 113, 20));
        pushButtonConfirmPurchase = new QPushButton(CreditCardInformation);
        pushButtonConfirmPurchase->setObjectName("pushButtonConfirmPurchase");
        pushButtonConfirmPurchase->setGeometry(QRect(90, 210, 80, 18));
        pushButton_BacktoCart = new QPushButton(CreditCardInformation);
        pushButton_BacktoCart->setObjectName("pushButton_BacktoCart");
        pushButton_BacktoCart->setGeometry(QRect(210, 210, 80, 18));
        label = new QLabel(CreditCardInformation);
        label->setObjectName("label");
        label->setGeometry(QRect(36, 30, 51, 20));
        label_2 = new QLabel(CreditCardInformation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 80, 71, 16));
        label_3 = new QLabel(CreditCardInformation);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 140, 37, 12));
        label_4 = new QLabel(CreditCardInformation);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 20, 111, 16));

        retranslateUi(CreditCardInformation);

        QMetaObject::connectSlotsByName(CreditCardInformation);
    } // setupUi

    void retranslateUi(QDialog *CreditCardInformation)
    {
        CreditCardInformation->setWindowTitle(QCoreApplication::translate("CreditCardInformation", "Dialog", nullptr));
        pushButtonConfirmPurchase->setText(QCoreApplication::translate("CreditCardInformation", "Confirm Purchase", nullptr));
        pushButton_BacktoCart->setText(QCoreApplication::translate("CreditCardInformation", "Back to Cart ", nullptr));
        label->setText(QCoreApplication::translate("CreditCardInformation", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("CreditCardInformation", "Card Number:", nullptr));
        label_3->setText(QCoreApplication::translate("CreditCardInformation", "CVV:", nullptr));
        label_4->setText(QCoreApplication::translate("CreditCardInformation", "Credit Card Information ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditCardInformation: public Ui_CreditCardInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITCARDINFORMATION_H
