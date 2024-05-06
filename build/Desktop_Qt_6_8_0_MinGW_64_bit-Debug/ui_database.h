/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_database
{
public:

    void setupUi(QDialog *database)
    {
        if (database->objectName().isEmpty())
            database->setObjectName("database");
        database->resize(400, 300);

        retranslateUi(database);

        QMetaObject::connectSlotsByName(database);
    } // setupUi

    void retranslateUi(QDialog *database)
    {
        database->setWindowTitle(QCoreApplication::translate("database", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class database: public Ui_database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
