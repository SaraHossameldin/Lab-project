#include "shoppingcart.h"
#include "ui_shoppingcart.h"

ShoppingCart::ShoppingCart(const QStringList &cartItems, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    QStringListModel *model = new QStringListModel(this);
    model->setStringList(cartItems);

    // Set the model to the list view
    ui->listView->setModel(model);
}


ShoppingCart::~ShoppingCart()
{
    delete ui;
}
