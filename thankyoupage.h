#ifndef THANKYOUPAGE_H
#define THANKYOUPAGE_H

#include <QDialog>

namespace Ui {
class ThankYouPage;
}

class ThankYouPage : public QDialog
{
    Q_OBJECT

public:
    explicit ThankYouPage(QWidget *parent = nullptr);
    ~ThankYouPage();

private slots:

    void on_pushButtonNewCustomer_clicked();

private:
    Ui::ThankYouPage *ui;
};

#endif // THANKYOUPAGE_H
