#ifndef CLIENT_H
#define CLIENT_H

#include <QSqlQueryModel>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

private:
    int clientId;  // Declare clientId as a member variable
public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::Client *ui;
    QSqlQueryModel *clientModel;  // Declare QSqlQueryModel as a member variable
    void updateClientModel();
};


#endif // CLIENT_H
