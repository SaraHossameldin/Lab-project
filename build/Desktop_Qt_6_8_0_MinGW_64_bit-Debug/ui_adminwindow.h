/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QPushButton *pushButtonAddUser;
    QPushButton *pushButtonApplyChanges;
    QWidget *tab_2;
    QTableView *tableView_2;
    QPushButton *pushButtonAddProduct;
    QPushButton *pushButtonApplyChangesProducts;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(438, 300);
        tabWidget = new QTabWidget(AdminWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 441, 311));
        tab = new QWidget();
        tab->setObjectName("tab");
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(5, 10, 401, 201));
        pushButtonAddUser = new QPushButton(tab);
        pushButtonAddUser->setObjectName("pushButtonAddUser");
        pushButtonAddUser->setGeometry(QRect(10, 230, 80, 18));
        pushButtonApplyChanges = new QPushButton(tab);
        pushButtonApplyChanges->setObjectName("pushButtonApplyChanges");
        pushButtonApplyChanges->setGeometry(QRect(100, 230, 80, 18));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(10, 10, 401, 211));
        pushButtonAddProduct = new QPushButton(tab_2);
        pushButtonAddProduct->setObjectName("pushButtonAddProduct");
        pushButtonAddProduct->setGeometry(QRect(10, 230, 80, 18));
        pushButtonApplyChangesProducts = new QPushButton(tab_2);
        pushButtonApplyChangesProducts->setObjectName("pushButtonApplyChangesProducts");
        pushButtonApplyChangesProducts->setGeometry(QRect(100, 230, 80, 18));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(AdminWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "Dialog", nullptr));
        pushButtonAddUser->setText(QCoreApplication::translate("AdminWindow", "Add User", nullptr));
        pushButtonApplyChanges->setText(QCoreApplication::translate("AdminWindow", "Apply Changes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AdminWindow", "Edit Users", nullptr));
        pushButtonAddProduct->setText(QCoreApplication::translate("AdminWindow", "Add Product", nullptr));
        pushButtonApplyChangesProducts->setText(QCoreApplication::translate("AdminWindow", "Apply Changes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AdminWindow", "Edit Products ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
