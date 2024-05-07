/********************************************************************************
** Form generated from reading UI file 'thankyoupage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THANKYOUPAGE_H
#define UI_THANKYOUPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ThankYouPage
{
public:
    QPushButton *pushButtonNewCustomer;
    QLabel *label;

    void setupUi(QDialog *ThankYouPage)
    {
        if (ThankYouPage->objectName().isEmpty())
            ThankYouPage->setObjectName("ThankYouPage");
        ThankYouPage->resize(400, 300);
        pushButtonNewCustomer = new QPushButton(ThankYouPage);
        pushButtonNewCustomer->setObjectName("pushButtonNewCustomer");
        pushButtonNewCustomer->setGeometry(QRect(130, 190, 80, 18));
        label = new QLabel(ThankYouPage);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 110, 101, 16));

        retranslateUi(ThankYouPage);

        QMetaObject::connectSlotsByName(ThankYouPage);
    } // setupUi

    void retranslateUi(QDialog *ThankYouPage)
    {
        ThankYouPage->setWindowTitle(QCoreApplication::translate("ThankYouPage", "Dialog", nullptr));
        pushButtonNewCustomer->setText(QCoreApplication::translate("ThankYouPage", "New Customer", nullptr));
        label->setText(QCoreApplication::translate("ThankYouPage", "Thank you for Your order!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThankYouPage: public Ui_ThankYouPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THANKYOUPAGE_H
