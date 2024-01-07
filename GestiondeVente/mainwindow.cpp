#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    populateProduitComboBox();
    stockModel = new QSqlQueryModel(this);
    updateStockModel();
    // Set the model for the QTableView

    ui->tableView->setModel(stockModel);
    ui->tableView->resizeColumnsToContents();
     nextFactureNumber = getNextFactureNumber();

    ui->lineEdit_3->setText(nextFactureNumber);
    facture = nextFactureNumber.toInt();
    stockModel2 = new QSqlQueryModel(this);

    // Provide a valid 'facture' value or adjust the function accordingly
    readChartWithProduit(nextFactureNumber, stockModel2);

    // Set the model for the second QTableView
    ui->tableView_2->setModel(stockModel2);
    ui->tableView_2->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateProduitComboBox() {
    QSqlQuery query("SELECT  id,nom FROM client");
    QStringList clientnom;

    while (query.next()) {
        int clientId = query.value("id").toInt();
        QString clientnom = query.value("nom").toString();

        // Add the product name to the ComboBox
        ui->comboBox->addItem(clientnom);

        // Set the product ID as UserRole for the corresponding item
        ui->comboBox->setItemData(ui->comboBox->count() - 1, clientId, Qt::UserRole);
    }
}

QString MainWindow::getNextFactureNumber() {
    QSqlQuery query("SELECT MAX(facture) AS max_facture FROM chart");
    if (query.exec() && query.next()) {
        QString maxFacture = query.value("max_facture").toString();
        int nextFacture = maxFacture.toInt() + 1;
        return QString::number(nextFacture);
    } else {
        qDebug() << "Error fetching max facture number:" << query.lastError().text();
        return QString();  // Return an empty string in case of an error
    }
}


QString MainWindow::getFactureNumber() {
    QSqlQuery query("SELECT MAX(facture) AS max_facture FROM chart");
    if (query.exec() && query.next()) {
        QString maxFacture = query.value("max_facture").toString();
        int nextFacture = maxFacture.toInt() ;
        return QString::number(nextFacture);
    } else {
        qDebug() << "Error fetching max facture number:" << query.lastError().text();
        return QString();  // Return an empty string in case of an error
    }
}

bool MainWindow::createChartEntry(int productId, int clientId, int quantite, double price, int facture) {
    QSqlQuery query;

    query.prepare("INSERT INTO chart (product_id, client_id, quantite, price, facture) "
                  "VALUES (:product_id, :client_id, :quantite, :price, :facture)");

    query.bindValue(":product_id", productId);
    query.bindValue(":client_id", clientId);
    query.bindValue(":quantite", quantite);
    query.bindValue(":price", price);
    query.bindValue(":facture", facture);

    if (query.exec()) {
        qDebug() << "Chart entry created successfully!";
        return true;
    } else {
        qDebug() << "Failed to create chart entry:" << query.lastError().text();
        return false;
    }
}




void MainWindow::updateStockModel() {
    if (stockModel) {
        // Perform the SELECT query with a WHERE condition
        stockModel->setQuery("SELECT produit.id, produit.nom , produit.prix, stock.quantite "
                             "FROM stock, produit "
                             "WHERE stock.produit_id = produit.id");

        const QSqlError error = stockModel->lastError();
        if (error.isValid()) {
            qDebug() << "Error executing stock query:" << error.text();
        }
    }
}

void MainWindow::readChartWithProduit(const QString &facture, QSqlQueryModel *model) {
    QSqlQuery query;
    query.prepare("SELECT chart.id, chart.client_id, "
                  "chart.quantite, chart.price, chart.facture, "
                  "produit.nom AS produit_nom, produit.prix AS produit_prix "
                  "FROM chart "
                  "JOIN produit ON chart.product_id = produit.id "
                  "WHERE chart.facture = :facture");


    query.bindValue(":facture", facture);

    if (query.exec()) {
        model->setQuery(query);

    } else {
        qDebug() << "Error fetching chart data:" << query.lastError().text();

    }
}


void MainWindow::on_pushButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    int clientId = handleComboBoxIndexChanged(index);

    qDebug()<<clientId;

    int quantite = ui->lineEdit->text().toInt();

    facture =  nextFactureNumber.toInt();
    FactureNumber = nextFactureNumber;
   if ( createChartEntry(selectedId, clientId, quantite, selectedprix, facture)) {
        qDebug() << "chart created successfully!";

         readChartWithProduit(FactureNumber, stockModel2);
    } else {
        qDebug() << "failed to create chard!";

    }

    int sum =getSumForFacture(facture);

    ui->lineEdit_2->setText(QString::number(sum));

}


void MainWindow::on_pushButton_5_clicked()
{

    stock = new Stock(this);
    stock->show();
}


void MainWindow::on_pushButton_7_clicked()
{

    client = new Client(this);
    client->show();

}


void MainWindow::on_pushButton_6_clicked()
{

    produit = new Produit(this);
    produit->show();

}




void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QModelIndex idIndex = stockModel->index(index.row(), 0);
     selectedId = stockModel->data(idIndex).toInt();

    // Get the quantity from the selected row's 'quantity' column (assuming 'quantity' is in the second column)
    QModelIndex quantityIndex = stockModel->index(index.row(), 3);
    int selectedQuantity = stockModel->data(quantityIndex).toInt();

    ui->lineEdit->setText(QString::number(selectedQuantity));

    // Update the lineEdit_2 with the selected quantity


    QModelIndex prixIndex = stockModel->index(index.row(), 2);
     selectedprix = stockModel->data(prixIndex).toInt();



}

int MainWindow::handleComboBoxIndexChanged(int index) {
    QVariant clientIdVariant = ui->comboBox->model()->data(ui->comboBox->model()->index(index, 0), Qt::UserRole);

    if (clientIdVariant.isValid()) {
        int produitId = clientIdVariant.toInt();
        qDebug() << "Selected produit ID:" << produitId;

        // Perform any additional actions if needed

        return produitId;
    } else {
        qDebug() << "Invalid produit ID";
        return -1;  // or any other value that indicates an invalid produit ID
    }
}

void MainWindow::updateChartEntry(int chartId, int quantite) {
    QSqlQuery query;
    query.prepare("UPDATE chart "
                  "SET quantite = :quantite "
                  "WHERE id = :chart_id");
    query.bindValue(":chart_id", chartId);
    query.bindValue(":quantite", quantite);
    if (query.exec()) {
        qDebug() << "Chart entry updated successfully!";
    } else {
        qDebug() << "Failed to update chart entry:" << query.lastError().text();
    }
}

void MainWindow::deleteChartEntry(int chartId) {
    QSqlQuery query;
    query.prepare("DELETE FROM chart WHERE id = :chart_id");
    query.bindValue(":chart_id", chartId);

    if (query.exec()) {
        qDebug() << "Chart entry deleted successfully!";
    } else {
        qDebug() << "Failed to delete chart entry:" << query.lastError().text();
    }
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    QModelIndex idIndex = stockModel2->index(index.row(), 0);
    charpos = stockModel2->data(idIndex).toInt();
    qDebug()<<charpos;



}


void MainWindow::on_pushButton_3_clicked()
{
     int quantite = ui->lineEdit->text().toInt();
     updateChartEntry(charpos,  quantite);
     qDebug()<<charpos<<" "<<quantite;
      QString FactureNumber = getFactureNumber();
       readChartWithProduit(FactureNumber, stockModel2);


}


void MainWindow::on_pushButton_4_clicked()
{
    deleteChartEntry(charpos);
   QString FactureN = getFactureNumber();
    readChartWithProduit(FactureN, stockModel2);

}


void MainWindow::on_pushButton_8_clicked()
{


    // Set the model for the QTableView
    nextFactureNumber = getNextFactureNumber();

    ui->lineEdit_3->setText(nextFactureNumber);
    stockModel2 = new QSqlQueryModel(this);
    // Provide a valid 'facture' value or adjust the function accordingly
    readChartWithProduit(nextFactureNumber, stockModel2);
    // Set the model for the second QTableView
    ui->tableView_2->setModel(stockModel2);
    ui->tableView_2->resizeColumnsToContents();

}

int MainWindow::getSumForFacture(int facture) {
    QSqlQuery query;
    query.prepare("SELECT SUM(quantite * price) AS total FROM chart WHERE facture = :facture");
    query.bindValue(":facture", facture);

    if (query.exec() && query.next()) {
        int totalSum = query.value("total").toInt();
        return totalSum;
    } else {
        qDebug() << "Error fetching sum for facture:" << query.lastError().text();
        return -1;  // Return -1 in case of an error
    }
}


