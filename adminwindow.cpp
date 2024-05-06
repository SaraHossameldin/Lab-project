#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QStandardItemModel>
#include "database.h"
#include <QWidget>
#include <QTabWidget>

AdminWindow::AdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminWindow)
{
 /*QWidget *tabWidgetContents = ui->tabWidgetEditProducts->widget(1);
    QTableView *tableView = new QTableView(tabWidgetContents);
*/
    ui->setupUi(this);
    this->displayProducts();
    this->displayUsers();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
void AdminWindow::displayProducts()
{
    DataBase db;
    auto productList = db.getProducts();

    static QStandardItemModel model(productList.size(), 8, this); // Initialize an empty model

    model.clear();
    model.setHorizontalHeaderItem(0, new QStandardItem("Id"));
    model.setHorizontalHeaderItem(1, new QStandardItem("Name"));
    model.setHorizontalHeaderItem(2, new QStandardItem("Category"));
    model.setHorizontalHeaderItem(3, new QStandardItem("Unit Price"));
    model.setHorizontalHeaderItem(4, new QStandardItem("Is New"));
    model.setHorizontalHeaderItem(5, new QStandardItem("Discount Rate"));
    model.setHorizontalHeaderItem(6, new QStandardItem("Brand"));
    model.setHorizontalHeaderItem(7, new QStandardItem("Mark Delete"));
    auto row = 0;
    for (const Product &product : productList)
    {
        QList<QStandardItem *> rowData;
        rowData << new QStandardItem(QString::number(product.id));
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

    ui->tableView_2->horizontalHeader()->setStretchLastSection(true); // Stretch the last column
    ui->tableView_2->setModel(&model);
    ui->tableView_2->show();
}

void AdminWindow::displayUsers ()
{
    DataBase db;
    auto userlist = db.getUserInfo();

    static QStandardItemModel model(userlist.size(), 5, this);

    model.clear();
    model.setHorizontalHeaderItem(0, new QStandardItem("id"));
    model.setHorizontalHeaderItem(1, new QStandardItem("username"));
    model.setHorizontalHeaderItem(2, new QStandardItem("password"));
    model.setHorizontalHeaderItem(3, new QStandardItem("isAdmin"));
    model.setHorizontalHeaderItem(4, new QStandardItem("Mark Delete"));
    auto row = 0;
    for (const UserInfo &user :userlist )
    {
        QList<QStandardItem *> rowData;
        rowData << new QStandardItem(QString::number(user.id));
        rowData << new QStandardItem(user.username);
        rowData << new QStandardItem(user.password);
        rowData << new QStandardItem(user.isAdmin ? "Yes" : "No");
        rowData << new QStandardItem("0");
        model.appendRow(rowData);
        row++;
    }

    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setModel(&model);
    ui->tableView->show();

}

void AdminWindow::on_pushButtonAddUser_clicked()
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    QList<QStandardItem *> rowData;
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("No");
    rowData << new QStandardItem("0");
    model->appendRow(rowData);

}


void AdminWindow::on_pushButtonAddUser_2_clicked()
{
    //apply changes in user table
    //add to cart button
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    QStack<int> rowsToRemove;
    DataBase db;

    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem* item = model->item(row, 4);
        if (item) {
            int value = item->data(Qt::EditRole).toInt();
            if (value == 1){
                rowsToRemove.push(row);
            } else {
                QStandardItem* item1 = model->item(row, 0);
                QStandardItem* item2 = model->item(row, 1);
                QStandardItem* item3 = model->item(row, 2);
                QStandardItem* item4 = model->item(row, 3);
                int id = item1->data(Qt::EditRole).toInt();
                QString username = item2->data(Qt::EditRole).toString();
                QString password = item3->data(Qt::EditRole).toString();
                int IsAdmin = item4->data(Qt::EditRole).toString() == "Yes" ? 1 : 0;
                if (id > 0)
                    db.updateUser(id, username, password, IsAdmin);
                else
                {
                    auto newUser = UserInfo(0, username, password, IsAdmin);
                    db.addNewUser(newUser);
                }

            }
        }
    }

    while (!rowsToRemove.isEmpty()) {
        int rowToRemove = rowsToRemove.pop();
        QStandardItem* item1 = model->item(rowToRemove, 0);
        int id = item1->data(Qt::EditRole).toInt();
        db.deleteUser(id);
        model->removeRow(rowToRemove);
    }

    this->displayUsers();
}


void AdminWindow::on_pushButtonAddProduct_clicked()
{
    //add new product
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_2->model());
    QList<QStandardItem *> rowData;
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("1");
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("0");
    model->appendRow(rowData);
}

void AdminWindow::on_pushButtonAddProduct_2_clicked()
{
    //apply changes in products table
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_2->model());
    QStack<int> rowsToRemove;
    DataBase db;

    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem* item = model->item(row, 7);
        if (item) {
            int value = item->data(Qt::EditRole).toInt();
            if (value == 1){
                rowsToRemove.push(row);
            } else {
                QStandardItem* item1 = model->item(row, 0);
                QStandardItem* item2 = model->item(row, 1);
                QStandardItem* item3 = model->item(row, 2);
                QStandardItem* item4 = model->item(row, 3);
                QStandardItem* item5 = model->item(row, 4);
                QStandardItem* item6 = model->item(row, 5);
                QStandardItem* item7 = model->item(row, 6);
                int id = item1->data(Qt::EditRole).toInt();
                QString name = item2->data(Qt::EditRole).toString();
                QString category = item3->data(Qt::EditRole).toString();
                double unitPrice = item4->data(Qt::EditRole).toDouble();
                int isNew = item5->data(Qt::EditRole).toString() == "Yes" ? 1 : 0;
                double discount = item6->data(Qt::EditRole).toDouble();
                QString Brand = item7->data(Qt::EditRole).toString();
                if (id > 0)
                    db.updateProduct(id, name, category, unitPrice, isNew, discount, Brand);
                else
                {
                    db.addProduct(name, category, unitPrice, isNew, discount, Brand);
                }
            }
        }
    }

    while (!rowsToRemove.isEmpty()) {
        int rowToRemove = rowsToRemove.pop();
        QStandardItem* item1 = model->item(rowToRemove, 0);
        int id = item1->data(Qt::EditRole).toInt();
        db.deleteProduct(id);
        model->removeRow(rowToRemove);
    }

    this->displayProducts();
}
