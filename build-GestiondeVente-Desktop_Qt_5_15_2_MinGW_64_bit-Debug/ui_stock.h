/********************************************************************************
** Form generated from reading UI file 'stock.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCK_H
#define UI_STOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Stock
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QComboBox *comboBox;
    QTableView *tableView;

    void setupUi(QDialog *Stock)
    {
        if (Stock->objectName().isEmpty())
            Stock->setObjectName(QString::fromUtf8("Stock"));
        Stock->resize(696, 453);
        pushButton_3 = new QPushButton(Stock);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 350, 80, 24));
        pushButton = new QPushButton(Stock);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 350, 80, 24));
        label_2 = new QLabel(Stock);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 180, 49, 16));
        label_3 = new QLabel(Stock);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 40, 161, 31));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label_3->setFont(font);
        pushButton_4 = new QPushButton(Stock);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 350, 80, 24));
        lineEdit_2 = new QLineEdit(Stock);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 210, 113, 24));
        label = new QLabel(Stock);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 110, 49, 16));
        comboBox = new QComboBox(Stock);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 140, 111, 24));
        tableView = new QTableView(Stock);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(220, 90, 421, 211));

        retranslateUi(Stock);

        QMetaObject::connectSlotsByName(Stock);
    } // setupUi

    void retranslateUi(QDialog *Stock)
    {
        Stock->setWindowTitle(QCoreApplication::translate("Stock", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Stock", "Modifier", nullptr));
        pushButton->setText(QCoreApplication::translate("Stock", "Ajouter", nullptr));
        label_2->setText(QCoreApplication::translate("Stock", "Quantite", nullptr));
        label_3->setText(QCoreApplication::translate("Stock", "Stock", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Stock", "Supprimer", nullptr));
        label->setText(QCoreApplication::translate("Stock", "Produit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stock: public Ui_Stock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCK_H
