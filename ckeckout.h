#ifndef CKECKOUT_H
#define CKECKOUT_H

#include <QDialog>

namespace Ui {
class Ckeckout;
}

class Ckeckout : public QDialog
{
    Q_OBJECT

public:
    explicit Ckeckout(QWidget *parent = nullptr);
    ~Ckeckout();

private slots:
    void on_pushButton_Back_to_Store_clicked();

    void on_pushButton_Back_to_Shopping_Cart_clicked();

    void on_pushButton_COD_clicked();

    void on_pushButton_CreditCard_clicked();

private:
    Ui::Ckeckout *ui;
};

#endif // CKECKOUT_H
