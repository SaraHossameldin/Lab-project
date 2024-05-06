#include "thankyoupage.h"
#include "ui_thankyoupage.h"
#include "login.h"

ThankYouPage::ThankYouPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ThankYouPage)
{
    ui->setupUi(this);
}

ThankYouPage::~ThankYouPage()
{
    delete ui;
}





void ThankYouPage::on_pushButtonNewCustomer_clicked()
{
    hide();
    Login* login= new Login;
    login->show();
}

