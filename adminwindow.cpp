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

    ui->setupUi(this);

    //To be able to display the tables of products and users in the two different tabs in the same window
    this->displayProducts();
    this->displayUsers();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
void AdminWindow::displayProducts()
{
    //To get the data from the database file
    DataBase db;

    //we call the getProducts() function that stores the Products information found in the
    //database file into a QVector of type Products
    //Then, productlist now holds the values stored from the vector returned from the function
    auto productList = db.getProducts();

    //We made this static to make sure the data doesnot change
    //We created an instance of the QStandardItemModel class and named it model to act as a model for the table view
    //it has rows equal to the size of the vector productList (the number of products basically) which is returned from the getProducts() function
    //it has 8 columns (Corresponding to the number of attributes of the products)
    static QStandardItemModel model(productList.size(), 8, this);

    //We clear the model before poplating it with the data
    model.clear();

    //Here, we  set headers for each column of the table
    model.setHorizontalHeaderItem(0, new QStandardItem("Id"));
    model.setHorizontalHeaderItem(1, new QStandardItem("Name"));
    model.setHorizontalHeaderItem(2, new QStandardItem("Category"));
    model.setHorizontalHeaderItem(3, new QStandardItem("Unit Price"));
    model.setHorizontalHeaderItem(4, new QStandardItem("Is New"));
    model.setHorizontalHeaderItem(5, new QStandardItem("Discount Rate"));
    model.setHorizontalHeaderItem(6, new QStandardItem("Brand"));
    model.setHorizontalHeaderItem(7, new QStandardItem("Mark Delete"));

    //Here, we start to populate the models
    auto row = 0;
    //we loop over the vector, and for each product, we create a list named
    //rowData that contains the QStandardItemModel objects representing the attributes of the products
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
        rowData << new QStandardItem("0"); //The quantity ordered is by default 0.

        model.appendRow(rowData);
        row++;
    }

    //We adjusted the table view settings by stretching the last column
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    //To display the model in the table view
    ui->tableView_2->setModel(&model);
    //showing the table view
    ui->tableView_2->show();
}

void AdminWindow::displayUsers ()
{
    DataBase db;
    //we call the getUserInfo() function that stores the User information found in the
    //database file into a QVector of type UserInfo
    //Then, userlist now holds the values stored from the vector returned from the function
    auto userlist = db.getUserInfo();

    //This is basically the same logic as the displayProducts() function
    //However, the models are now populated by the attributes of the UserInfo class instead
    static QStandardItemModel model(userlist.size(), 5, this);

    model.clear();
    //new titles for this table
    model.setHorizontalHeaderItem(0, new QStandardItem("id"));
    model.setHorizontalHeaderItem(1, new QStandardItem("username"));
    model.setHorizontalHeaderItem(2, new QStandardItem("password"));
    model.setHorizontalHeaderItem(3, new QStandardItem("isAdmin"));
    model.setHorizontalHeaderItem(4, new QStandardItem("Mark Delete"));
    auto row = 0;

    //Loop to store QStandardItemModel objects representing the attributes of the UserInfo in the list rowData
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
    //adjusting format
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    //To display the model in the table view
    ui->tableView->setModel(&model);
    //To show the table view
    ui->tableView->show();

}

//To handle the event that the push button titled "Add User"
void AdminWindow::on_pushButtonAddUser_clicked()
{
    //We got the model associated with tableView
    //We used qobject_cast to cast the model to a QStandardItemModel
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());

    //we create a QList of QStandardItem objects named rowData that
    //each QStandardItem objects represents a column in the table
    //We initiliazed each column with the following values
    QList<QStandardItem *> rowData;
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("No");
    rowData << new QStandardItem("0");

    //We append the rowData list to add a new entry to the table view
    model->appendRow(rowData);
}

//This is the event handler for when the button labeled "Apply Changes" is clicked
void AdminWindow::on_pushButtonApplyChanges_clicked()
{
    //apply changes in user table
    //add to cart button

    //Again a new QStandardItemModel initialized to the model of tableview
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    //Using a stack to be able to remove rows if a certain user was labeled to be deleted
    QStack<int> rowsToRemove;
    DataBase db;
    //loop
    for (int row = 0; row < model->rowCount(); ++row)
    {
        //we picked the column with inex 4 since this is the one holding the Mark deletion
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
                //id>0 means that this user exists already
                if (id > 0)
                    db.updateUser(id, username, password, IsAdmin);
                //less than zero is by default a new user
                else
                {
                    auto newUser = UserInfo(0, username, password, IsAdmin);
                    db.addNewUser(newUser);
                }

            }
        }
    }

    while (!rowsToRemove.isEmpty())
    {
        int rowToRemove = rowsToRemove.pop();
        QStandardItem* item1 = model->item(rowToRemove, 0);
        int id = item1->data(Qt::EditRole).toInt();
        db.deleteUser(id);
        model->removeRow(rowToRemove);
    }

//display the new list after the changes are applied
    this->displayUsers();
}


void AdminWindow::on_pushButtonAddProduct_clicked()
{
    //a function to add a new product (event handler)
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_2->model());
    //list named rowData of type QStandardItem initialized
    QList<QStandardItem *> rowData;
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("1");
    rowData << new QStandardItem("0");
    rowData << new QStandardItem("");
    rowData << new QStandardItem("0");
    //to add a new row
    model->appendRow(rowData);
}

void AdminWindow::on_pushButtonpushButtonApplyChangesProducts_clicked()
{
    //apply changes in products table
    //we used qobject_cast to cast a model to a pointer of type QStandardItemModel
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableView_2->model());

    //declare a stack called rowsToRemove that stores the indices of the rows that will be removed
    QStack<int> rowsToRemove;
    DataBase db;
    //loop to iterate over every row in the table
    for (int row = 0; row < model->rowCount(); ++row)
    {
        //to retrieve the items in column 7 (The one with the mark deleted title)
        QStandardItem* item = model->item(row, 7);
        if (item)
        {
            //To retreive the integer value of this item
            int value = item->data(Qt::EditRole).toInt();
            if (value == 1) //That means it is marked to be deleted as soon as the apply changes button is clicked
            {
                //push the idex into the stack
                rowsToRemove.push(row);
            } else
            {      // poulating the items with the attributes (presented by the columns)
                QStandardItem* item1 = model->item(row, 0);
                QStandardItem* item2 = model->item(row, 1);
                QStandardItem* item3 = model->item(row, 2);
                QStandardItem* item4 = model->item(row, 3);
                QStandardItem* item5 = model->item(row, 4);
                QStandardItem* item6 = model->item(row, 5);
                QStandardItem* item7 = model->item(row, 6);
                //item 1 to be retrieved as int
                int id = item1->data(Qt::EditRole).toInt();
                //item 2 to be retrieved as string
                QString name = item2->data(Qt::EditRole).toString();
                QString category = item3->data(Qt::EditRole).toString();
                //item 3 to be retrieved as double
                double unitPrice = item4->data(Qt::EditRole).toDouble();
                //if Yes, the int value is 1 and if No, the int value is 0
                int isNew = item5->data(Qt::EditRole).toString() == "Yes" ? 1 : 0;
                double discount = item6->data(Qt::EditRole).toDouble();
                QString Brand = item7->data(Qt::EditRole).toString();
                //if id>0, then this is an existing user
                if (id > 0)
                    db.updateProduct(id, name, category, unitPrice, isNew, discount, Brand);
                else //new user is created
                {
                    db.addProduct(name, category, unitPrice, isNew, discount, Brand);
                }
            }
        }
    }
    //when the stack is not empty (It contains indices to be deleted)
    while (!rowsToRemove.isEmpty())
    {
        //pops the index of the row to remove
        int rowToRemove = rowsToRemove.pop();
        //to remove the id from the first column to remove the user corresponding to this id
        QStandardItem* item1 = model->item(rowToRemove, 0);
        int id = item1->data(Qt::EditRole).toInt();
        //we call the deleteProduct function from Database class
        db.deleteProduct(id);
        model->removeRow(rowToRemove);
    }
       //new display after changes
       this->displayProducts();
}
