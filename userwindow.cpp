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
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::displayProducts(bool ApplyFilter)
{
    DataBase db;
    //store the vector returned by the getProducts() function in a new vector
    //called productList
    auto productList = db.getProducts();
    //define the filters (The text entered in the lineedits)
    QString filter1 = ui->lineEditName->text();
    QString filter2 = ui->lineEditcategory->text();
    QString filter3= ui->lineEditbrand->text();
    //check box to browse for discounts
    bool flag= ui->checkBoxDiscount->isChecked();

    static QStandardItemModel model(productList.size(), 7, this); // Initialize an empty model
    //number of rows is the size of the vector, and 7 columns

    //set header titles for each column
    model.clear();
    model.setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model.setHorizontalHeaderItem(1, new QStandardItem("Category"));
    model.setHorizontalHeaderItem(2, new QStandardItem("Unit Price"));
    model.setHorizontalHeaderItem(3, new QStandardItem("Is New"));
    model.setHorizontalHeaderItem(4, new QStandardItem("Discount Rate"));
    model.setHorizontalHeaderItem(5, new QStandardItem("brand"));
    model.setHorizontalHeaderItem(6, new QStandardItem("Ordered Quantity"));

    auto row = 0;
    //loop over the productList vector
    for (const Product &product : productList)
    {
        //conditions for filters to work
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
            //list named rowData to store the attributes
            QList<QStandardItem *> rowData;
            rowData << new QStandardItem(product.Name);
            rowData << new QStandardItem(product.Category);
            rowData << new QStandardItem(QString::number(product.UnitPrice));
            rowData << new QStandardItem(product.IsNew ? "Yes" : "No");
            rowData << new QStandardItem(QString::number(product.DiscountRate));
            rowData << new QStandardItem(product.Brand);
            //Quantity by default is 0
            rowData << new QStandardItem("0");

            model.appendRow(rowData);
            //to move to the next row
            row++;
        }
    }

    ui->tableView->horizontalHeader()->setStretchLastSection(true); // Stretch the last column

    //To display the model in the table view
    ui->tableView->setModel(&model);
    //show updated table
    ui->tableView->show();
}

void UserWindow::on_pushButtonApplyFilter_clicked()
{
    //display the updated table
    this->displayProducts(true);
}

void UserWindow::addToCartClicked(int row, int productId)
{
    //retrieves the sender of the signal (QPushButton) and casts it to a pointer of type
    //QPushButton
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton) //if not nullpointer
    {
        //retrieves productId and stores it as int
        int productId = clickedButton->property("productId").toInt();
    }
}

void UserWindow::on_pushButtonAddtoCart_clicked()
{
    //add to cart button
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    //loop to iterate over the rows
    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem* item = model->item(row, 6); //column with index 6
        if (item)
        {
            //retrieves quantity as a double
            double value = item->data(Qt::EditRole).toDouble();
            if (value != 0.0)
            {
                //model that represents name, unit price, discount
                QStandardItem* item0 = model->item(row, 0);
                QStandardItem* item2 = model->item(row, 2);
                QStandardItem* item4 = model->item(row, 4);
                //apply the new changes
                my_shooping_cart.append(ShoppingCartItem(item0->data(Qt::EditRole).toString(),
                                                         item2->data(Qt::EditRole).toDouble(),
                                                         value,
                                                         item4->data(Qt::EditRole).toDouble()));
            }
        }
    }
    //display new table
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
    //to start calculating the total price
    double total = 0;

    //loop to traverse my_shooping_cart
    for (const ShoppingCartItem &item : my_shooping_cart) {
        QList<QStandardItem *> rowData;
        rowData << new QStandardItem(item.ProductName);
        rowData << new QStandardItem(QString::number(item.UnitPrice));
        rowData << new QStandardItem(QString::number(item.Quantity));
        rowData << new QStandardItem(QString::number(item.DiscountRate));
        //formula to calculate the total price
        total += (item.Quantity * item.UnitPrice) * (100-item.DiscountRate) / 100.0;
        model.appendRow(rowData);
    }

    ui->tableView_2->horizontalHeader()->setStretchLastSection(true); // Stretch the last column

    ui->tableView_2->setModel(&model);
    ui->tableView_2->show();
    //to display the total price
    ui->label_3->setText("Total Amount = " + QString::number(total));
}

void UserWindow::on_pushButtonConfirm_clicked()
{
    //hide current window and show new new checkout page
    hide();
    Ckeckout *page = new Ckeckout(this);
    page->show();
}


void UserWindow::on_pushButtonUpdate_clicked()
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_2->model());
    QStack<int> rowsToRemove; // Use a stack instead of a list to remove
    double total = 0;

    for (int row = 0; row < model->rowCount(); ++row)
    {
        QStandardItem* item = model->item(row, 2); //quantity column
        if (item)
        {
            double value = item->data(Qt::EditRole).toDouble();
            if (value == 0) //ordered quantity=0
            {
                rowsToRemove.push(row); // Push row index onto the stack
            } else {
                QStandardItem* item1 = model->item(row, 1); // unit price
                QStandardItem* item3 = model->item(row, 3); // discount rate
                double uprice = item1->data(Qt::EditRole).toDouble();
                double disc = item3->data(Qt::EditRole).toDouble();
                //calculate total
                total += (uprice * value) * (100 - disc) / 100;
                //ipdates Quantity at my_shooping_cart at this index to be equal to value (ordere quantity)
                this->my_shooping_cart[row].Quantity = value;
            }
        }
    }

    // Remove the marked rows from the model (pop from the stack)
    while (!rowsToRemove.isEmpty())
    {
        int rowToRemove = rowsToRemove.pop();
        //remove from model as well
        model->removeRow(rowToRemove);
        //removes item at this index from shopping cart
        this->my_shooping_cart.removeAt(rowToRemove);
    }
//to display total amount
    ui->label_3->setText("Total Amount = " + QString::number(total));
}


