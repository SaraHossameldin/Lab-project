#ifndef CREDITCARDINFORMATION_H
#define CREDITCARDINFORMATION_H

#include <QDialog>

namespace Ui {
class CreditCardInformation;
}

class CreditCardInformation : public QDialog
{
    Q_OBJECT

public:
    explicit CreditCardInformation(QWidget *parent = nullptr);
    ~CreditCardInformation();

private slots:
    void on_pushButtonConfirmPurchase_clicked();

    void on_pushButton_BacktoCart_clicked();

private:
    Ui::CreditCardInformation *ui;
};

#endif // CREDITCARDINFORMATION_H
