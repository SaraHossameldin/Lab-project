#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QVector>
#include <QtSql>

// Define a struct to hold username and password
class UserInfo
{
public:

    int id;
    QString username;
    QString password;
    int isAdmin;

    //Constructor
    UserInfo(int userid, const QString& uname, const QString& pwd, int admin) :
        id(userid), username(uname), password(pwd), isAdmin(admin) {}
};

class Product {
public:
    int id;
    QString Name;
    double UnitPrice;
    QString Category;
    int IsNew;
    double DiscountRate;
    QString Brand;

    Product(int productid, const QString& pname, double productUnitPrice, QString& CategoryName, int New, double discountRate, QString &brand) :
        id(productid), Name(pname), UnitPrice(productUnitPrice), Category(CategoryName), IsNew(New), DiscountRate(discountRate), Brand(brand) {}
};

struct OrderLine
{
    QString productName;
    double Quantity;
    double TotalAmount;
    OrderLine(QString orderlineproduct,double quantity, double totalamount) :
        productName(orderlineproduct), Quantity(quantity), TotalAmount(totalamount) {}
};

struct Order
{
    QVector<OrderLine> lines;
    QDateTime OrderDate;
    QString Username;
    double TotalAmount;
    int orderId;

    Order(QVector<OrderLine> orderlinevector, QDateTime date, QString username, double totalamount): lines(orderlinevector),OrderDate(date),Username(username),TotalAmount(totalamount){}
};

class DataBase
{
public:
    DataBase();
    DataBase(const QString& pth);
    QVector<UserInfo> getUserInfo();
    QVector<Product> getProducts();
    QVector<Order> getOrders(const QString& username);
    QVector<Order> getAllOrders();

    void updateUserInfo (const QVector<UserInfo>&);
    bool addNewUser(UserInfo& newUser);
    bool updateUser(int id, QString& name, QString& password, int isAdmin);
    bool deleteUser(int id);
    bool checkUser(const QString& username, const QString& password);

    bool addProduct(QString& name, QString& category, double unitPrice,int isNew, double discount,  QString& brand);
    bool updateProduct(int id, const QString& name, const QString& category, double unitPrice,
                       int isNew, double discount, const QString& brand);
    bool deleteProduct(int id);

private:
    QString path;
};

#endif // DATABASE_H



