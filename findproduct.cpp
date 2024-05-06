/*#include "findproduct.h"
#include "product.h"
#include "ui_findproduct.h"
#include "shoppingcart.h"

#include <QVBoxLayout>
#include <QListWidget>

FindProduct::FindProduct(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::FindProduct)
{
    ui->setupUi(this); // Initialize UI elements defined in the .ui file

    // Create products
    m_products << Product("Pants", 19.99, "Medium", "Denim", "Red")
               << Product("Blouse", 29.99, "Small", "Silk", "White")
               << Product("Blouse", 15.99, "Large", "Polyester", "Blue")
               << Product("Pants", 39.99, "Large", "Denim", "Blue")
               << Product("Dress", 34.99, "Small", "Cotton", "Navy")
               << Product("Dress", 49.99, "Small", "Polyester", "Black")
               << Product("Blouse", 45.99, "Medium", "Fleece", "Gray")
               << Product("Blouse", 24.99, "Small", "Cotton", "Khaki")
               << Product("Pants", 39.99, "Large", "Wool", "Beige")
               << Product("Pants", 19.99, "Medium", "Denim", "Black")
               << Product("Blouse", 29.99, "Large", "Cotton", "Green")
               << Product("Maxi Dress", 59.99, "Medium", "Chiffon", "Pink");

    // Populate list widget with products
    updateProductList();

    // Connect signal-slot for search functionality
    connect(ui->SearchMe, &QLineEdit::textChanged, this, &FindProduct::searchProduct);
    // Connect signal-slot for search button
    connect(ui->SearchButton, &QPushButton::clicked, this, &FindProduct::on_SearchButton_clicked);
}

FindProduct::~FindProduct()
{
    delete ui;
}

void FindProduct::updateProductList()
{
    // Clear existing items from the list widget
    ui->products->clear();

    // Add products to the list widget
    for (const Product &product : m_products) {
        QString itemText = product.name() + " - Size: " + product.size() + " - Material: " + product.material() + " - Color: " + product.color() + " - $" + QString::number(product.price());
        ui->products->addItem(itemText);
    }
}

void FindProduct::searchProduct(const QString &query)
{
    // Clear existing items from the list widget
    ui->products->clear();

    for (const Product &product : m_products) {
        if (product.name().contains(query, Qt::CaseInsensitive) ||
            product.size().contains(query, Qt::CaseInsensitive) ||
            product.material().contains(query, Qt::CaseInsensitive) ||
            product.color().contains(query, Qt::CaseInsensitive)) {
            QString itemText = product.name() + " - Size: " + product.size() + " - Material: " + product.material() + " - Color: " + product.color() + " - $" + QString::number(product.price());
            // Add the item to the list widget
            ui->products->addItem(itemText);
        }
    }
}

void FindProduct::on_SearchButton_clicked()
{
    QList<QListWidgetItem *> selectedItems = ui->products->selectedItems();
    QStringList cartItems;

    // Iterate over the selected items
    for (QListWidgetItem *item : selectedItems) {
        // Retrieve the item's text (product details)
        QString productDetails = item->text();
        // Add the product details to the list of cart items
        cartItems << productDetails;
    }

    // Pass the cart items to the next window (replace "NextWindow" with the appropriate window class)
    ShoppingCart *shoppingCart = new ShoppingCart(cartItems, this);
    shoppingCart->show();
}
*/
