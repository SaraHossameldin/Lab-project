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
    //SQL query to retrieve all records from the Users table in the database file
    QSqlQuery query(temp);
    query.exec("select * from Users");
    //vector of type UserInfo
    QVector<UserInfo> userlist;
    while(query.next())
    {
        //store the data from the query in variables
        int id= query.value(0).toInt();
        QString username = query.value(1).toString();
        QString password = query.value(2).toString();
        int isAdmin = query.value(3).toInt();
        //adds a new element intilized by the data stored from the table
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
    //SQL query to retrieve all records from the Users table in the database file
    QSqlQuery query(temp);
    query.exec("select Id, Name, UnitPrice, Category, IsNew, DiscountRate, brand from Products");
    QVector<Product> productlist;
    while(query.next())
    {
         //store the data from the query in variables
        int id= query.value(0).toInt();
        QString Name = query.value(1).toString();
        double UnitPrice = query.value(2).toDouble();
        auto category = query.value(3).toString();
        auto IsNew = query.value(4).toInt();
        auto DiscountRate = query.value(5).toDouble();
        QString brand= query.value(6).toString();
        //adds a new element intilized by the data stored from the table
        productlist.append(Product(id,Name,UnitPrice, category, IsNew, DiscountRate, brand));
    }
     temp.close();
    return productlist;
}

bool DataBase::addNewUser(UserInfo& newUser)
{
    //open database file
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);

    //to insert a new user into the Users table in the database with the
    //username, password, and isAdmin
    //and stores the success or failure in the returnValue variable.
    bool returnValue = query.exec("insert into Users(Username, Password, IsAdmin) values('"+
                                  newUser.username+"', '"+newUser.password+"', "+ QString::number(newUser.isAdmin)+")");
    temp.close();
    //return if the operation is successful
    return returnValue;
}

bool DataBase::updateUser(int id, QString& name, QString& password, int isAdmin)
{
    //open database file
    auto temp = QSqlDatabase::addDatabase("QSQLITE", "dbconn1");
    temp.setDatabaseName(this->path);
    temp.open();
    QSqlQuery query(temp);
    //to update a user of a specfic id in the Users table in the database with the
    //username, password, and isAdmin
    //and stores the success or failure in the returnValue variable.
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
    //to delete a user of a specfic id from the Users table in the database
    //and stores the success or failure in the returnValue variable.
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
    //to insert a new product into the Products table in the database
    //and stores the success or failure in the returnValue variable.
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
    //to update a product of any id in the Products table in the database
    //'%' retrieves all
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
    //to delete a product of a specfic id from the Products table in the database
    //and stores the success or failure in the returnValue variable.
    bool returnValue = query.exec("delete from Products where Id = "+QString::number(id));
    temp.close();
    return returnValue;
}
