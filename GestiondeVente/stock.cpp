#include "stock.h"
#include "ui_stock.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

Stock::Stock(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Stock)
{
    ui->setupUi(this);
    populateProduitComboBox();
    stockModel = new QSqlQueryModel(this);
    updateStockModel();
    // Set the model for the QTableView

    ui->tableView->setModel(stockModel);
    ui->tableView->resizeColumnsToContents();
}

Stock::~Stock()
{
    delete ui;

}

void Stock::populateProduitComboBox() {
    QSqlQuery query("SELECT id, nom FROM produit");
    QStringList produitNames;

    while (query.next()) {
        int produitId = query.value("id").toInt();
        QString produitNom = query.value("nom").toString();

        // Add the product name to the ComboBox
        ui->comboBox->addItem(produitNom);

        // Set the product ID as UserRole for the corresponding item
        ui->comboBox->setItemData(ui->comboBox->count() - 1, produitId, Qt::UserRole);
    }
}


void Stock::updateStockModel() {
    if (stockModel) {
        // Perform the SELECT query with a WHERE condition
        stockModel->setQuery("SELECT stock.id, produit.nom, stock.quantite "
                             "FROM stock, produit "
                             "WHERE stock.produit_id = produit.id");

        const QSqlError error = stockModel->lastError();
        if (error.isValid()) {
            qDebug() << "Error executing stock query:" << error.text();
        }
    }
}



bool Stock::createStock(int produitId, int quantity) {
    QSqlQuery query;
    query.prepare("INSERT INTO stock (produit_id, quantite) VALUES (:produitId, :quantity)");
    query.bindValue(":produitId", produitId);
    query.bindValue(":quantity", quantity);

    if (query.exec()) {
        qDebug() << "Stock created successfully!";
        return true;
    } else {
        qDebug() << "Failed to create stock:" << query.lastError().text();
        return false;
    }
}


bool Stock::updateStock(int stockId, int quantity) {
    QSqlQuery query;
    query.prepare("UPDATE stock SET quantite = :quantity WHERE id = :stockId");
    query.bindValue(":quantity", quantity);
    query.bindValue(":stockId", stockId);

    if (query.exec()) {
        qDebug() << "Stock updated successfully!";
        return true;
    } else {
        qDebug()<<quantity << " "<<stockId;
        qDebug() << "Failed to update stock record:" << query.lastError().text();
        return false;
    }
}

bool Stock::deleteStock(int stockId) {
    QSqlQuery query;
    query.prepare("DELETE FROM stock WHERE id = :stockId");
    query.bindValue(":stockId", stockId);

    if (query.exec()) {
        qDebug() << "Stock deleted successfully!";
        return true;
    } else {
        qDebug() << "Stock deleted failed!";
        return false;
    }
}

void Stock::on_pushButton_clicked()
{
    int quantity = ui->lineEdit_2->text().toInt();  // Adjust this line based on your UI elements

    int index = ui->comboBox->currentIndex();
    int produitId = handleComboBoxIndexChanged(index);

    // Call the createStock function with the retrieved values
    if (createStock(produitId, quantity)) {
        qDebug() << "Stock created successfully!";
        updateStockModel();
    } else {
        qDebug() << produitId << " " <<quantity;
        qDebug() << "Failed to create stock!";

}
}

int Stock::handleComboBoxIndexChanged(int index) {
    QVariant produitIdVariant = ui->comboBox->model()->data(ui->comboBox->model()->index(index, 0), Qt::UserRole);

    if (produitIdVariant.isValid()) {
        int produitId = produitIdVariant.toInt();
        qDebug() << "Selected produit ID:" << produitId;

        // Perform any additional actions if needed

        return produitId;
    } else {
        qDebug() << "Invalid produit ID";
        return -1;  // or any other value that indicates an invalid produit ID
    }
}



void Stock::on_pushButton_3_clicked()
{

    QModelIndex selectedIndex = ui->tableView->currentIndex();
    int quantity = ui->lineEdit_2->text().toInt();
    if (selectedIndex.isValid()) {
        // Retrieve the ID from the selected row
        QModelIndex idIndex = stockModel->index(selectedIndex.row(), 0);  // Assuming 'id' is in the first column
        int id = stockModel->data(idIndex).toInt();

        // Perform the update operation
        if (updateStock(id, quantity)) {
            qDebug() << "Stock update successfully!";
            updateStockModel();
        } else {
           qDebug() << "Stock update failed!";
        }
    } else {
        qDebug() << "No row selected for update.";
    }
}


void Stock::on_tableView_clicked(const QModelIndex &index)
{
    // Get the selected ID from the first column (assuming 'id' is in the first column)
    QModelIndex idIndex = stockModel->index(index.row(), 0);
    int selectedId = stockModel->data(idIndex).toInt();

    // Get the quantity from the selected row's 'quantity' column (assuming 'quantity' is in the second column)
    QModelIndex quantityIndex = stockModel->index(index.row(), 2);
    int selectedQuantity = stockModel->data(quantityIndex).toInt();

    ui->lineEdit_2->setText(QString::number(selectedQuantity));

    // Update the lineEdit_2 with the selected quantity
    ui->lineEdit_2->setText(QString::number(selectedQuantity));

    // Fetch the corresponding product name from the 'produit' table based on the selected ID
    QString selectedProductName;
    QSqlQuery query;
    query.prepare("SELECT produit.nom FROM produit INNER JOIN stock ON produit.id = stock.produit_id WHERE stock.id = :id");
    query.bindValue(":id", selectedId);

    if (query.exec() && query.next()) {
        selectedProductName = query.value("nom").toString();
    } else {
        qDebug() << "Error fetching product name:" << query.lastError().text();
        return;
    }

    // Update the combo box with the selected product name
    int comboBoxIndex = ui->comboBox->findText(selectedProductName);
    if (comboBoxIndex != -1) {
        ui->comboBox->setCurrentIndex(comboBoxIndex);
    }

}


void Stock::on_pushButton_4_clicked()
{
    QModelIndex selectedIndex = ui->tableView->currentIndex();

    if (selectedIndex.isValid()) {
        // Retrieve the ID from the selected row
        QModelIndex idIndex = stockModel->index(selectedIndex.row(), 0);  // Assuming 'id' is in the first column
        int id = stockModel->data(idIndex).toInt();

        // Perform the update operation
        if (deleteStock(id)) {
            qDebug() << "Stock update successfully!";
            updateStockModel();
        } else {
            qDebug() << "Stock update failed!";
        }
    } else {
        qDebug() << "No row selected for update.";
    }
}




