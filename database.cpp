#include "database.h"

//DataBase::DataBase() {}

DataBase::DataBase()
{
    this->path = "C:\\DB\\ShoppingDB.db";
}

QVector<UserInfo> DataBase::getUserInfo()
{
    //open database
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    query.exec("select * from Users");
    QVector<UserInfo> userlist;
    while(query.next())
    {
        int id= query.value(0).toInt();
        QString username = query.value(1).toString();
        QString password = query.value(2).toString();
        int isAdmin = query.value(3).toInt();
        userlist.append(UserInfo(id,username, password, isAdmin));
    }
    // Close database
    temp.close();
    return userlist;
}


void DataBase::updateUserInfo(const QVector<UserInfo>& userInfoList)
{
    //open database
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    temp.exec("delete from Users");

    // Insert updated user information into the database
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Users (Username, Password) VALUES (:username, :password, :isadmin)");
    for (const UserInfo& userInfo : userInfoList)
    {
        insertQuery.bindValue(":username", userInfo.username);
        insertQuery.bindValue(":password", userInfo.password);
        insertQuery.bindValue(":isadmin", userInfo.isAdmin);
        insertQuery.exec();
    }

    temp.close();
}


QVector<Product> DataBase::getProducts()
{
    //open database
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    query.exec("select Id, Name, UnitPrice, Category, IsNew, DiscountRate, brand from Products");
    QVector<Product> productlist;
    while(query.next())
    {
        int id= query.value(0).toInt();
        QString Name = query.value(1).toString();
        double UnitPrice = query.value(2).toDouble();
        auto category = query.value(3).toString();
        auto IsNew = query.value(4).toInt();
        auto DiscountRate = query.value(5).toDouble();
        QString brand= query.value(6).toString();
        productlist.append(Product(id,Name,UnitPrice, category, IsNew, DiscountRate, brand));
    }
     temp.close();
    return productlist;
}

QVector<Order> DataBase::getOrders(const QString& username)
{
    //open database
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    query.exec("select Orders.OrderId, Name, UnitPrice, Quantity, OrderDetails.TotalAmount, OrderDate, Username from Orders inner join OrderDetails on Orders.OrderId = OrderDetails.OrderId inner join Products on Products.Id = OrderDetails.ProductId where Username like '"+username+"' ");
    QVector<Order> orders;
    while(query.next())
    {
        auto orderId = query.value(0).toInt();
        auto productName = query.value(1).toString();
        auto UnitPrice = query.value(2).toDouble();
        auto Quantity = query.value(3).toDouble();
        auto TotalAmount = query.value(4).toDouble();
        auto date1 = query.value(5).toDateTime();
        auto user1 = query.value(6).toString();

        //find the order in orders list if found
        auto iter = orders.begin();
        while(iter != orders.end()){
            if ((*iter).orderId == orderId)
            {
                //just add the orderdetails
                (*iter).lines.append(OrderLine(productName,Quantity, TotalAmount));
                break;
            }
            iter++;
        }
        if (iter == orders.end()) {
            auto newOrder = Order(QVector<OrderLine>(), date1, user1, 0 );
            orders.append(newOrder);
            newOrder.lines.append(OrderLine(productName,Quantity, TotalAmount));
        }
    }
    temp.close();
    return orders;
}

QVector<Order> DataBase::getAllOrders()
{
    return getOrders("%");
}

bool DataBase::addNewUser(UserInfo& newUser)
{
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    bool returnValue = query.exec("insert into Users(Username, Password, IsAdmin) values('"+
                                  newUser.username+"', '"+newUser.password+"', "+ QString::number(newUser.isAdmin)+")");
    temp.close();
    return returnValue;
}

bool DataBase::updateUser(int id, QString& name, QString& password, int isAdmin)
{
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    bool returnValue = query.exec("update Users set Username='"+name+"', Password='"+password+
                                  "', IsAdmin="+QString::number(isAdmin)+" where Id = "+QString::number(id));
    temp.close();
    return returnValue;
}

bool DataBase::deleteUser(int id)
{
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    bool returnValue = query.exec("delete from Users where Id = "+QString::number(id));
    temp.close();
    return returnValue;
}

bool DataBase::addProduct(QString& name, QString& category, double unitPrice,int isNew, double discount, QString& brand)
{
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    bool returnValue = query.exec("insert into Products(Name, UnitPrice, Category, IsNew, DiscountRate, brand) values('"+
                                  name+"', "+QString::number(unitPrice)+", '"+ category+"', "+QString::number(isNew)+","+
                                  QString::number(discount)+", '"+brand+"')");
    temp.close();
    return returnValue;
}

bool DataBase::updateProduct(int id, const QString& name, const QString& category, double unitPrice,
                             int isNew, double discount, const QString& brand)
{
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);

    // Construct the SQL query for updating the product
    QString queryStr = QString("UPDATE Products SET "
                               "Name = '%1', "
                               "UnitPrice = %2, "
                               "Category = '%3', "
                               "IsNew = %4, "
                               "DiscountRate = %5, "
                               "brand = '%6' "
                               "WHERE Id = %7")
                           .arg(name)
                           .arg(unitPrice)
                           .arg(category)
                           .arg(isNew)
                           .arg(discount)
                           .arg(brand)
                           .arg(id);


    auto val = query.exec(queryStr);
    temp.close();
    return val;
}

bool DataBase::deleteProduct(int id)
{
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    bool returnValue = query.exec("delete from Products where Id = "+QString::number(id));
    temp.close();
    return returnValue;
}
