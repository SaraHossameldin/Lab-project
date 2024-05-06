/*#ifndef FINDPRODUCT_H
#define FINDPRODUCT_H
#include "product.h"
#include <QDialog>
class QListWidget;
class QStringListModel;

namespace Ui {
class FindProduct;
}

class FindProduct : public QDialog
{
    Q_OBJECT

public:
    explicit FindProduct(QWidget *parent = nullptr);
    ~FindProduct();

private slots:
    void on_SearchButton_clicked();
    void searchProduct(const QString &query);

private:
    Ui::FindProduct *ui;
    QListWidget *products;
    QStringListModel *m_model;
    QVector<Product> m_products;
    void updateProductList();
};

#endif // FINDPRODUCT_H
*/
