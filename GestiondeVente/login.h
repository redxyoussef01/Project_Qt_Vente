#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    MainWindow *main;
};

#endif // LOGIN_H
