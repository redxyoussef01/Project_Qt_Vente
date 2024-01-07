#ifndef PRODUIT_H
#define PRODUIT_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class Produit;
}

class Produit : public QDialog
{
    Q_OBJECT

public:
    explicit Produit(QWidget *parent = nullptr);
    ~Produit();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::Produit *ui;
    QSqlQueryModel *produitModel;
    int produitId;

    void updateProduitModel();
    bool createProduit(const QString& nom, double prix);
    bool updateProduit(int produitId, const QString& newNom, double newPrix);
    bool deleteProduit(int produitId);
};

#endif // PRODUIT_H
