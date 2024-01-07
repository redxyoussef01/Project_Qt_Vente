#include "login.h"
#include "ui_login.h"

#include <QSqlQuery>
#include <QSqlRecord>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Program Files/SQLiteStudio/ProjectQt");

    if (!db.open()) {
        qDebug() << "Failed to connect to the database:";
        qDebug() << db.lastError().text();

    } else {
        qDebug() << "Connected to the database!";
    }
}
bool verifyLogin(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM account WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        // Login successful
        return true;
    } else {
        // Login failed
        return false;
    }
}


login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString enteredUsername = ui->usernameLineEdit->text();
    QString enteredPassword = ui->passwordLineEdit->text();

    if (verifyLogin(enteredUsername, enteredPassword)) {
        // Login successful, show the MainWindow and hide the login window
        MainWindow *main = new MainWindow(this);
        main->show();
        hide();
    } else {
        // Login failed, handle accordingly (show an error message, etc.)
        qDebug() << "Login failed!";
    }


}

