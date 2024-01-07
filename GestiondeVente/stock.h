#ifndef STOCK_H
#define STOCK_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class Stock;
}

class Stock : public QDialog
{
    Q_OBJECT

public:
    explicit Stock(QWidget *parent = nullptr);
    ~Stock();

private slots:
    void on_pushButton_clicked();
    void populateProduitComboBox();



    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();





private:
    Ui::Stock *ui;
    QSqlQueryModel *stockModel;

    void updateStockModel();
    bool createStock(int produitId, int quantity);
    bool updateStock(int stockId, int quantity);
    bool deleteStock(int stockId);
    void showError(const QString &message);
    int handleComboBoxIndexChanged(int index);

};

#endif // STOCK_H
