#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "stock.h"
#include "produit.h"
#include <QSqlQueryModel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_tableView_clicked(const QModelIndex &index);



    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *stockModel2;
    QSqlQueryModel *stockModel;
    void populateProduitComboBox();
    void updateStockModel();
    Client *client;
    Stock *stock;
    Produit *produit;
    int handleComboBoxIndexChanged(int index);
    void readChartWithProduit(const QString &facture, QSqlQueryModel *model);
    QString getNextFactureNumber();
    QString getFactureNumber();
    int selectedId; // Member variable to store the selected product ID
    double selectedprix;  // Member variable to store the selected price
    bool createChartEntry(int productId, int clientId, int quantite, double price, int facture);
    int facture;
    int charpos;
    void updateChartEntry(int chartId, int quantite);
    void deleteChartEntry(int chartId);
    int getSumForFacture(int facture);
    QString nextFactureNumber;
     QString FactureNumber;
};
#endif // MAINWINDOW_H
