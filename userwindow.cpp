#include "userwindow.h"
#include "ui_userwindow.h"
#include "database.h"
#include "QListWidget"
#include <QVBoxLayout>
#include <QListView>
#include <QStandardItemModel>
#include <QItemDelegate>
#include "thankyoupage.h"
#include "ckeckout.h"

UserWindow::UserWindow(QString& user, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->username = user;
    this->displayProducts();
    //this->displayOrders();
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::displayProducts(bool ApplyFilter)
{
    DataBase db;
    auto productList = db.getProducts();
    QString filter1 = ui->lineEdit->text();
    QString filter2 = ui->lineEdit_2->text();
    QString filter3= ui->lineEditbrand->text();
    bool flag= ui->checkBoxDiscount->isChecked();

    static QStandardItemModel model(productList.size(), 7, this); // Initialize an empty model

    model.clear();
    model.setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model.setHorizontalHeaderItem(1, new QStandardItem("Category"));
    model.setHorizontalHeaderItem(2, new QStandardItem("Unit Price"));
    model.setHorizontalHeaderItem(3, new QStandardItem("Is New"));
    model.setHorizontalHeaderItem(4, new QStandardItem("Discount Rate"));
    model.setHorizontalHeaderItem(5, new QStandardItem("brand"));
    model.setHorizontalHeaderItem(6, new QStandardItem("Ordered Quantity"));

    auto row = 0;
    for (const Product &product : productList)
    {
        if (!ApplyFilter ||
            (flag && product.DiscountRate > 0) ||
            (filter1.length() == 0 && filter2.length() == 0 && filter3.length()==0 && !flag) ||
            (filter1.length() > 0 && filter1 == product.Name && filter2.length()==0 && filter3.length()==0) ||
            (filter2.length() > 0 && filter2 == product.Category && filter1.length()==0 && filter3.length()==0)||
            (filter3.length()>0 && filter3==product.Brand && filter1.length()==0 && filter2.length()==0)||
            (filter1.length()>0 && filter2.length()>0 && filter1 == product.Name && filter2 == product.Category)||
            (filter1.length()>0 && filter3.length()>0 && filter1== product.Name && filter3== product.Brand)||
            (filter2.length()>0 && filter3.length()>0 && filter2== product.Name && filter3== product.Brand))
        {
            QList<QStandardItem *> rowData;
            rowData << new QStandardItem(product.Name);
            rowData << new QStandardItem(product.Category);
            rowData << new QStandardItem(QString::number(product.UnitPrice));
            rowData << new QStandardItem(product.IsNew ? "Yes" : "No");
            rowData << new QStandardItem(QString::number(product.DiscountRate));
            rowData << new QStandardItem(product.Brand);
            rowData << new QStandardItem("0");

            model.appendRow(rowData);
            row++;
        }
    }

    ui->tableView->horizontalHeader()->setStretchLastSection(true); // Stretch the last column
    // OR
    // ui->tableView->horizontalHeader()->setResizeMode(yourDesiredCol, QHeaderView::Stretch);

    ui->tableView->setModel(&model);
    ui->tableView->show();
}

void UserWindow::on_pushButton_clicked()
{
    this->displayProducts(true);
}

void UserWindow::addToCartClicked(int row, int productId)
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton) {
        int productId = clickedButton->property("productId").toInt();
    }
}

void UserWindow::on_pushButton_2_clicked()
{
    //add to cart button
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem* item = model->item(row, 6); // Column 5 (index 4)
        if (item) {
            double value = item->data(Qt::EditRole).toDouble();
            if (value != 0.0) {
                QStandardItem* item0 = model->item(row, 0);
                QStandardItem* item2 = model->item(row, 2);
                QStandardItem* item4 = model->item(row, 4);
                my_shooping_cart.append(ShoppingCartItem(item0->data(Qt::EditRole).toString(),
                                                         item2->data(Qt::EditRole).toDouble(),
                                                         value,
                                                         item4->data(Qt::EditRole).toDouble()));
            }
        }
    }
    this->displayCartItems();
}

void UserWindow::displayCartItems()
{
    static QStandardItemModel model(this->my_shooping_cart.size(), 4, this); // Initialize an empty model

    model.clear();
    model.setHorizontalHeaderItem(0, new QStandardItem("Product Name"));
    model.setHorizontalHeaderItem(1, new QStandardItem("Unit Price"));
    model.setHorizontalHeaderItem(2, new QStandardItem("Ordered Quantity"));
    model.setHorizontalHeaderItem(3, new QStandardItem("Discount Rate"));
    double total = 0;

    for (const ShoppingCartItem &item : my_shooping_cart) {
        QList<QStandardItem *> rowData;
        rowData << new QStandardItem(item.ProductName);
        rowData << new QStandardItem(QString::number(item.UnitPrice));
        rowData << new QStandardItem(QString::number(item.Quantity));
        rowData << new QStandardItem(QString::number(item.DiscountRate));
        total += (item.Quantity * item.UnitPrice) * (100-item.DiscountRate) / 100.0;
        model.appendRow(rowData);
    }

    ui->tableView_2->horizontalHeader()->setStretchLastSection(true); // Stretch the last column
    // OR
    // ui->tableView->horizontalHeader()->setResizeMode(yourDesiredCol, QHeaderView::Stretch);

    ui->tableView_2->setModel(&model);
    ui->tableView_2->show();

    ui->label_3->setText("Total Amount = " + QString::number(total));
}

/*void UserWindow::displayOrders()
{
    DataBase db;
   // auto ordersList = db.getOrders(this->username);

    static QStandardItemModel model(ordersList.size(), 6, this); // Initialize an empty model

    model.clear();
    model.setHorizontalHeaderItem(0, new QStandardItem("Date"));
    model.setHorizontalHeaderItem(1, new QStandardItem("Total Amount"));
    auto row = 0;
    for (const Order &item : ordersList) {

        QList<QStandardItem *> rowData;
        rowData << new QStandardItem(item.OrderDate.toString());
        rowData << new QStandardItem(QString::number(item.TotalAmount));

        model.appendRow(rowData);
        row++;

    }

    ui->tableView_3->horizontalHeader()->setStretchLastSection(true); // Stretch the last column
    // OR
    // ui->tableView->horizontalHeader()->setResizeMode(yourDesiredCol, QHeaderView::Stretch);

    ui->tableView_3->setModel(&model);
    ui->tableView_3->show();
}*/

void UserWindow::on_pushButton_3_clicked()
{
    //Confirm Order
    hide();
    Ckeckout *page = new Ckeckout(this);
    page->show();
}


void UserWindow::on_pushButton_4_clicked()
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_2->model());
    QStack<int> rowsToRemove; // Use a stack instead of a list
    double total = 0;

    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem* item = model->item(row, 2); // Column 5 (index 4)
        if (item) {
            double value = item->data(Qt::EditRole).toDouble();
            if (value == 0) {
                rowsToRemove.push(row); // Push row index onto the stack
            } else {
                QStandardItem* item1 = model->item(row, 1); // Column 5 (index 4)
                QStandardItem* item3 = model->item(row, 3); // Column 5 (index 4)
                double uprice = item1->data(Qt::EditRole).toDouble();
                double disc = item3->data(Qt::EditRole).toDouble();
                total += (uprice * value) * (100 - disc) / 100;
                this->my_shooping_cart[row].Quantity = value;
            }
        }
    }

    // Remove the marked rows from the model (pop from the stack)
    while (!rowsToRemove.isEmpty()) {
        int rowToRemove = rowsToRemove.pop();
        model->removeRow(rowToRemove);
        this->my_shooping_cart.removeAt(rowToRemove);
    }

    ui->label_3->setText("Total Amount = " + QString::number(total));
}


