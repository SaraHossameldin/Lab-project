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

/*void Ckeckout::on_pushButton_Back_to_Store_clicked()
{
    hide();
    FindProduct* store= new FindProduct;
    store->show();
}
*/


void Ckeckout::on_pushButton_Back_to_Shopping_Cart_clicked()
{
    hide();
    ((QDialog*)this->parent())->show();
}

void Ckeckout::on_pushButton_Back_to_Store_clicked()
{
    //TODO
}

void Ckeckout::on_pushButton_COD_clicked()
{
    ThankYouPage *page = new ThankYouPage();
    this->hide();
    page->show();
}


void Ckeckout::on_pushButton_CreditCard_clicked()
{
    ThankYouPage *page = new ThankYouPage();
    this->hide();
    page->show();
}

