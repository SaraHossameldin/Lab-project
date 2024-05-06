/********************************************************************************
** Form generated from reading UI file 'findproduct.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPRODUCT_H
#define UI_FINDPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindProduct
{
public:
    QLabel *SHOPWITHMELABEL;
    QLineEdit *SearchMe;
    QPushButton *SearchButton;
    QListWidget *products;

    void setupUi(QDialog *FindProduct)
    {
        if (FindProduct->objectName().isEmpty())
            FindProduct->setObjectName("FindProduct");
        FindProduct->setEnabled(true);
        FindProduct->resize(556, 643);
        SHOPWITHMELABEL = new QLabel(FindProduct);
        SHOPWITHMELABEL->setObjectName("SHOPWITHMELABEL");
        SHOPWITHMELABEL->setGeometry(QRect(40, 20, 361, 111));
        SearchMe = new QLineEdit(FindProduct);
        SearchMe->setObjectName("SearchMe");
        SearchMe->setEnabled(true);
        SearchMe->setGeometry(QRect(50, 140, 301, 26));
        SearchMe->setAutoFillBackground(false);
        SearchButton = new QPushButton(FindProduct);
        SearchButton->setObjectName("SearchButton");
        SearchButton->setGeometry(QRect(350, 140, 131, 29));
        products = new QListWidget(FindProduct);
        products->setObjectName("products");
        products->setGeometry(QRect(50, 200, 441, 401));
        products->setSelectionMode(QAbstractItemView::MultiSelection);

        retranslateUi(FindProduct);

        QMetaObject::connectSlotsByName(FindProduct);
    } // setupUi

    void retranslateUi(QDialog *FindProduct)
    {
        FindProduct->setWindowTitle(QCoreApplication::translate("FindProduct", "Dialog", nullptr));
        SHOPWITHMELABEL->setText(QCoreApplication::translate("FindProduct", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:700; color:#005500;\">ShopWithMe</span></p></body></html>", nullptr));
        SearchMe->setPlaceholderText(QCoreApplication::translate("FindProduct", "Blouse,Pants,Dress", nullptr));
        SearchButton->setText(QCoreApplication::translate("FindProduct", "ADD TO CART", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindProduct: public Ui_FindProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPRODUCT_H
