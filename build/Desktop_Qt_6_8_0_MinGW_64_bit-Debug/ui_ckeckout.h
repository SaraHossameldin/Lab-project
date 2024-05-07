/********************************************************************************
** Form generated from reading UI file 'ckeckout.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CKECKOUT_H
#define UI_CKECKOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Ckeckout
{
public:
    QPushButton *pushButton_CreditCard;
    QPushButton *pushButton_COD;
    QPushButton *pushButton_Back_to_Shopping_Cart;
    QLabel *label;

    void setupUi(QDialog *Ckeckout)
    {
        if (Ckeckout->objectName().isEmpty())
            Ckeckout->setObjectName("Ckeckout");
        Ckeckout->resize(373, 263);
        pushButton_CreditCard = new QPushButton(Ckeckout);
        pushButton_CreditCard->setObjectName("pushButton_CreditCard");
        pushButton_CreditCard->setGeometry(QRect(140, 70, 80, 18));
        pushButton_COD = new QPushButton(Ckeckout);
        pushButton_COD->setObjectName("pushButton_COD");
        pushButton_COD->setGeometry(QRect(140, 110, 80, 18));
        pushButton_Back_to_Shopping_Cart = new QPushButton(Ckeckout);
        pushButton_Back_to_Shopping_Cart->setObjectName("pushButton_Back_to_Shopping_Cart");
        pushButton_Back_to_Shopping_Cart->setGeometry(QRect(40, 170, 101, 18));
        label = new QLabel(Ckeckout);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 40, 91, 16));

        retranslateUi(Ckeckout);

        QMetaObject::connectSlotsByName(Ckeckout);
    } // setupUi

    void retranslateUi(QDialog *Ckeckout)
    {
        Ckeckout->setWindowTitle(QCoreApplication::translate("Ckeckout", "Dialog", nullptr));
        pushButton_CreditCard->setText(QCoreApplication::translate("Ckeckout", "Credit Card", nullptr));
        pushButton_COD->setText(QCoreApplication::translate("Ckeckout", "Cash on Delivery", nullptr));
        pushButton_Back_to_Shopping_Cart->setText(QCoreApplication::translate("Ckeckout", "Back to Shopping Cart", nullptr));
        label->setText(QCoreApplication::translate("Ckeckout", "Payment Method:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ckeckout: public Ui_Ckeckout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CKECKOUT_H
