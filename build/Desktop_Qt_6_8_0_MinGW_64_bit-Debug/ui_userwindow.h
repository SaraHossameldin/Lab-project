/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QTabWidget *ProductsList;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QLineEdit *lineEditbrand;
    QCheckBox *checkBoxDiscount;
    QLabel *labelbrand;
    QWidget *tab_3;
    QTableView *tableView_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;

    void setupUi(QDialog *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(493, 388);
        ProductsList = new QTabWidget(UserWindow);
        ProductsList->setObjectName("ProductsList");
        ProductsList->setGeometry(QRect(0, -1, 491, 381));
        tab = new QWidget();
        tab->setObjectName("tab");
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 20, 61, 20));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 71, 16));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 20, 51, 20));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 0, 37, 12));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 20, 61, 20));
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 50, 471, 201));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 260, 80, 18));
        lineEditbrand = new QLineEdit(tab);
        lineEditbrand->setObjectName("lineEditbrand");
        lineEditbrand->setGeometry(QRect(300, 20, 61, 20));
        checkBoxDiscount = new QCheckBox(tab);
        checkBoxDiscount->setObjectName("checkBoxDiscount");
        checkBoxDiscount->setGeometry(QRect(220, 20, 58, 18));
        labelbrand = new QLabel(tab);
        labelbrand->setObjectName("labelbrand");
        labelbrand->setGeometry(QRect(300, 0, 37, 12));
        ProductsList->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(5, 11, 471, 251));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(400, 270, 80, 18));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(310, 270, 80, 18));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 270, 141, 16));
        ProductsList->addTab(tab_3, QString());

        retranslateUi(UserWindow);

        ProductsList->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QDialog *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("UserWindow", "Product Name", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "Category", nullptr));
        pushButton->setText(QCoreApplication::translate("UserWindow", "Apply Filter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UserWindow", "Add To Cart", nullptr));
        checkBoxDiscount->setText(QCoreApplication::translate("UserWindow", "Discount", nullptr));
        labelbrand->setText(QCoreApplication::translate("UserWindow", "brand", nullptr));
        ProductsList->setTabText(ProductsList->indexOf(tab), QCoreApplication::translate("UserWindow", "Products", nullptr));
        pushButton_3->setText(QCoreApplication::translate("UserWindow", "Confirm", nullptr));
        pushButton_4->setText(QCoreApplication::translate("UserWindow", "Update", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindow", "<html><head/><body><p>Total Amount = </p></body></html>", nullptr));
        ProductsList->setTabText(ProductsList->indexOf(tab_3), QCoreApplication::translate("UserWindow", "Shopping Cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
