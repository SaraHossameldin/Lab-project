/********************************************************************************
** Form generated from reading UI file 'product.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCT_H
#define UI_PRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_product
{
public:

    void setupUi(QDialog *product)
    {
        if (product->objectName().isEmpty())
            product->setObjectName("product");
        product->resize(400, 300);

        retranslateUi(product);

        QMetaObject::connectSlotsByName(product);
    } // setupUi

    void retranslateUi(QDialog *product)
    {
        product->setWindowTitle(QCoreApplication::translate("product", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class product: public Ui_product {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCT_H
