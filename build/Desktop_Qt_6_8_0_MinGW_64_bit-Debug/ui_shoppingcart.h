/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_ShoppingCart
{
public:
    QListView *listView;
    QLabel *label;

    void setupUi(QDialog *ShoppingCart)
    {
        if (ShoppingCart->objectName().isEmpty())
            ShoppingCart->setObjectName("ShoppingCart");
        ShoppingCart->resize(621, 649);
        listView = new QListView(ShoppingCart);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(70, 250, 511, 311));
        label = new QLabel(ShoppingCart);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 70, 571, 181));

        retranslateUi(ShoppingCart);

        QMetaObject::connectSlotsByName(ShoppingCart);
    } // setupUi

    void retranslateUi(QDialog *ShoppingCart)
    {
        ShoppingCart->setWindowTitle(QCoreApplication::translate("ShoppingCart", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ShoppingCart", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:700; font-style:italic; color:#0000ff;\">SHOPPING CART</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShoppingCart: public Ui_ShoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
