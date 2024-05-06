#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>
#include <QStringListModel>

namespace Ui
{
class ShoppingCart;
}

class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCart(const QStringList &cartItems, QWidget *parent = nullptr);
    ~ShoppingCart();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
