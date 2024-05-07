#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>

struct ShoppingCartItem
{
    QString ProductName;
    double UnitPrice;
    double Quantity;
    double DiscountRate;

    ShoppingCartItem(QString name, double uPrice, double qty, double disc):ProductName(name), UnitPrice(uPrice), Quantity(qty),
        DiscountRate(disc) {}
};

namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserWindow(QString& user, QWidget *parent = nullptr);

    ~UserWindow();
    void displayProducts(bool ApplyFilter=false);
    void displayCartItems();
    void displayOrders();

    QString username;

private slots:
    void on_pushButtonApplyFilter_clicked();
    void addToCartClicked(int row, int productId);

    void on_pushButtonAddtoCart_clicked();

    void on_pushButtonConfirm_clicked();

    void on_pushButtonUpdate_clicked();

private:
    Ui::UserWindow *ui;
    QVector<ShoppingCartItem> my_shooping_cart;
};

#endif // USERWINDOW_H
