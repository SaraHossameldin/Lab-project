#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "database.h" // Include the database header

QT_BEGIN_NAMESPACE
namespace Ui { class Register; }
QT_END_NAMESPACE

class Register : public QDialog
{
    Q_OBJECT

public:
    Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_Cancel_clicked();

private:
    Ui::Register *ui;
    DataBase* database;
};

#endif // REGISTER_H

