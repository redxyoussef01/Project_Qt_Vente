#include "client.h"
#include "ui_client.h"
#include <QStringListModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>




Client::Client(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);

    // Initialize clientModel
    clientModel = new QSqlQueryModel(this);
    updateClientModel();

    // Set the model for the QTableView
    ui->tableView->setModel(clientModel);
    ui->tableView->resizeColumnsToContents();
}

void Client::updateClientModel() {
    if (clientModel) {
        clientModel->setQuery("SELECT * FROM client");
        if (clientModel->lastError().isValid()) {
            qDebug() << "Error updating model:" << clientModel->lastError().text();
        }
    }
}

Client::~Client()
{
    delete ui;
}


// Function to create a new client
bool createClient(const QString& nom, const QString& coordonnees) {
    QSqlQuery query;
    query.prepare("INSERT INTO client (nom, coordonnees) "
                  "VALUES (:nom, :coordonnees)");
    query.bindValue(":nom", nom);
    query.bindValue(":coordonnees", coordonnees);



    if (query.exec()) {
        qDebug() << "Client created successfully!";
        return true;
    } else {
        qDebug() << "Failed to create client:" << query.lastError().text();
        return false;
    }
}

// Function to read client information


// Function to update client information
bool updateClient(int clientId, const QString& newNom, const QString& newCoordonnees) {
    QSqlQuery query;
    query.prepare("UPDATE client SET nom = :newNom, coordonnees = :newCoordonnees "
                  "WHERE id = :clientId");
    query.bindValue(":newNom", newNom);
    query.bindValue(":newCoordonnees", newCoordonnees);
    query.bindValue(":clientId", clientId);

    if (query.exec()) {
        qDebug() << "Client updated successfully!";
        return true;
    } else {
        qDebug() << "Failed to update client:" << query.lastError().text();
        return false;
    }
}

// Function to delete a client
bool deleteClient(int clientId) {
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id = :clientId");
    query.bindValue(":clientId", clientId);

    if (query.exec()) {
        qDebug() << "Client deleted successfully!";
        return true;
    } else {
        qDebug() << "Failed to delete client:" << query.lastError().text();
        return false;
    }
}


void Client::on_pushButton_clicked()
{

    QString nom = ui->lineEdit->text();
    QString coordonnees = ui->lineEdit_2->text();

    if (createClient(nom, coordonnees)) {
        // The client was created successfully, you can add any additional logic here
        qDebug() << "Client created successfully!";
        updateClientModel();
    } else {
        // Handle the case where client creation failed
        qDebug() << "Failed to create client!";
    }

}


void Client::on_pushButton_3_clicked()
{
    QString newNom = ui->lineEdit->text();
    QString newCoordonnees = ui->lineEdit_2->text();
     qDebug() <<clientId ;
    if (updateClient(clientId, newNom, newCoordonnees)) {
        qDebug() << "Client updated successfully!";
        updateClientModel();
    } else {
        qDebug() << "Failed to update client!";
    }
}

void Client::on_tableView_clicked(const QModelIndex &index)
{
    int selectedRow = index.row();

    // Assuming the "id" column is at index 0 in your model
    QModelIndex idIndex = ui->tableView->model()->index(selectedRow, 0);
    clientId = idIndex.data().toInt();
    qDebug() <<clientId ;
    // Assuming the other columns are "nom" and "coordonnees" at indices 1 and 2
    QModelIndex nomIndex = ui->tableView->model()->index(selectedRow, 1);
    QModelIndex coordonneesIndex = ui->tableView->model()->index(selectedRow, 2);

    // Update line edits with the selected data
    ui->lineEdit->setText(nomIndex.data().toString());
    ui->lineEdit_2->setText(coordonneesIndex.data().toString());
}


void Client::on_pushButton_4_clicked()
{
    if (deleteClient(clientId)) {
        qDebug() << "Client deleted successfully!";
        updateClientModel();
    } else {
        qDebug() << "Failed to delete client!";
    }
}

