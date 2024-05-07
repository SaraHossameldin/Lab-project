#include "ckeckout.h"
#include "ui_ckeckout.h"
#include "findproduct.h"
#include "shoppingcart.h"
#include "findproduct.h"
#include "thankyoupage.h"

Ckeckout::Ckeckout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ckeckout)
{
    ui->setupUi(this);
}

Ckeckout::~Ckeckout()
{
    delete ui;
}

void Ckeckout::on_pushButton_Back_to_Shopping_Cart_clicked()
{
    //hide current window
    hide();
    //This is to show the parent of this window, which is the UserWindow the user just came from
    ((QDialog*)this->parent())->show();
}

void Ckeckout::on_pushButton_COD_clicked()
{
    //new ThankYouPage
    ThankYouPage *page = new ThankYouPage();
    //hide current window
    this->hide();
    //show new ThankYouPage
    page->show();
}


void Ckeckout::on_pushButton_CreditCard_clicked()
{   //new ThankYouPage
    ThankYouPage *page = new ThankYouPage();
    //hide current window
    this->hide();
    //show new ThankYouPage
    page->show();
}

