#include "creditcardinformation.h"
#include "ui_creditcardinformation.h"
#include "thankyoupage.h"
#include "shoppingcart.h"

CreditCardInformation::CreditCardInformation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreditCardInformation)
{
    ui->setupUi(this);
}

CreditCardInformation::~CreditCardInformation()
{
    delete ui;
}

void CreditCardInformation::on_pushButtonConfirmPurchase_clicked()
{
    hide();
    ThankYouPage *final= new ThankYouPage;
    final->show();

}


void CreditCardInformation::on_pushButton_BacktoCart_clicked()
{
    hide();
    QStringList cartItems;
    ShoppingCart *cart = new ShoppingCart(cartItems);
    cart->show();
}

