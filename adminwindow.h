#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
    void displayProducts();
    void displayUsers();

private slots:
    void on_pushButtonAddUser_clicked();
    void on_pushButtonpushButtonApplyChangesProducts_clicked();
    void on_pushButtonAddProduct_clicked();
    void on_pushButtonApplyChanges_clicked();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
