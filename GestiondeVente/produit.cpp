#include "produit.h"
#include "ui_produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

Produit::Produit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Produit)
{
    ui->setupUi(this);
    produitModel = new QSqlQueryModel(this);
    updateProduitModel();

    ui->tableView->setModel(produitModel);
    ui->tableView->resizeColumnsToContents();
}

Produit::~Produit()
{
    delete ui;
}

void Produit::updateProduitModel() {
    if (produitModel) {
        produitModel->setQuery("SELECT id, nom, prix FROM produit");
        if (produitModel->lastError().isValid()) {
            qDebug() << "Error updating produit model:" << produitModel->lastError().text();
        }
    }
}

bool Produit::createProduit(const QString& nom, double prix) {
    QSqlQuery query;
    query.prepare("INSERT INTO produit (nom, prix) VALUES (:nom, :prix)");
    qDebug() << "Creating Produit with nom:" << nom << "prix:" << prix;
    query.bindValue(":nom", nom);
    query.bindValue(":prix", prix);

    if (query.exec()) {
        qDebug() << "Produit created successfully!";
        return true;
    } else {
        qDebug() << "Failed to create produit:" << query.lastError().text();
        return false;
    }
}

bool Produit::updateProduit(int produitId, const QString& newNom, double newPrix) {
    QSqlQuery query;
    query.prepare("UPDATE produit SET nom = :newNom, prix = :newPrix WHERE id = :produitId");
    query.bindValue(":newNom", newNom);
    query.bindValue(":newPrix", newPrix);
    query.bindValue(":produitId", produitId);

    if (query.exec()) {
        qDebug() << "Produit updated successfully!";
        return true;
    } else {
        qDebug() << "Failed to update produit:" << query.lastError().text();
        return false;
    }
}

bool Produit::deleteProduit(int produitId) {
    QSqlQuery query;
    query.prepare("DELETE FROM produit WHERE id = :produitId");
    query.bindValue(":produitId", produitId);

    if (query.exec()) {
        qDebug() << "Produit deleted successfully!";
        return true;
    } else {
        qDebug() << "Failed to delete produit:" << query.lastError().text();
        return false;
    }
}

void Produit::on_pushButton_clicked()
{
    QString nom = ui->nomprd->text();
    double prix = ui->prix->text().toDouble();

    if (createProduit(nom, prix)) {
        qDebug() << "Produit created successfully!";
        updateProduitModel();
    } else {
        qDebug() << "Failed to create produit!";
    }
}


void Produit::on_pushButton_3_clicked()
{
    QSqlQuery query;
    QString newNom = ui->nomprd->text();
    double newPrix = ui->prix->text().toDouble();
    // Assuming the id column is autoincremented, you don't update it explicitly
    query.prepare("UPDATE produit SET nom = :newNom, prix = :newPrix WHERE id = :produitId");
    query.bindValue(":newNom", newNom);
    query.bindValue(":newPrix", newPrix);
    query.bindValue(":produitId", produitId);

    if (query.exec()) {
        qDebug() << "Produit updated successfully!";
         updateProduitModel();
    } else {
     qDebug() << "Produit update failed!";

    }
}


void Produit::on_tableView_clicked(const QModelIndex &index)
{
    int selectedRow = index.row();

    // Assuming the id column is at index 0, and nom and prix are at indices 1 and 2
    QModelIndex idIndex = ui->tableView->model()->index(selectedRow, 0);
    produitId = idIndex.data().toInt();

    QModelIndex nomIndex = ui->tableView->model()->index(selectedRow, 1);
    QModelIndex prixIndex = ui->tableView->model()->index(selectedRow, 2);

    ui->nomprd->setText(nomIndex.data().toString());
    ui->prix->setText(QString::number(prixIndex.data().toDouble()));
}


void Produit::on_pushButton_4_clicked()
{
    if (deleteProduit(produitId)) {
        qDebug() << "Produit created successfully!";
        updateProduitModel();
    } else {
        qDebug() << "Failed to create produit!";
    }
}

