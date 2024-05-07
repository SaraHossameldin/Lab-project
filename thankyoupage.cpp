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




//event handler for when the button labeled "New Customer" is clicked
void ThankYouPage::on_pushButtonNewCustomer_clicked()
{
    //hide current window
    hide();
    //Create a new instance of the Login class
    Login* login= new Login;
    //show the new login window
    login->show();
}

