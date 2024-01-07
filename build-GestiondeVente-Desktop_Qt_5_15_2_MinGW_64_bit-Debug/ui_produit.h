/********************************************************************************
** Form generated from reading UI file 'produit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUIT_H
#define UI_PRODUIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Produit
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QLineEdit *prix;
    QLabel *label;
    QLineEdit *nomprd;
    QTableView *tableView;

    void setupUi(QDialog *Produit)
    {
        if (Produit->objectName().isEmpty())
            Produit->setObjectName(QString::fromUtf8("Produit"));
        Produit->resize(716, 451);
        pushButton_3 = new QPushButton(Produit);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 350, 80, 24));
        pushButton = new QPushButton(Produit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 350, 80, 24));
        label_2 = new QLabel(Produit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 180, 49, 16));
        label_3 = new QLabel(Produit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 40, 161, 31));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label_3->setFont(font);
        pushButton_4 = new QPushButton(Produit);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 350, 80, 24));
        prix = new QLineEdit(Produit);
        prix->setObjectName(QString::fromUtf8("prix"));
        prix->setGeometry(QRect(60, 210, 113, 24));
        label = new QLabel(Produit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 110, 111, 16));
        nomprd = new QLineEdit(Produit);
        nomprd->setObjectName(QString::fromUtf8("nomprd"));
        nomprd->setGeometry(QRect(60, 140, 113, 24));
        tableView = new QTableView(Produit);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(275, 110, 371, 192));

        retranslateUi(Produit);

        QMetaObject::connectSlotsByName(Produit);
    } // setupUi

    void retranslateUi(QDialog *Produit)
    {
        Produit->setWindowTitle(QCoreApplication::translate("Produit", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Produit", "Modifier", nullptr));
        pushButton->setText(QCoreApplication::translate("Produit", "Ajouter", nullptr));
        label_2->setText(QCoreApplication::translate("Produit", "prix", nullptr));
        label_3->setText(QCoreApplication::translate("Produit", "Produit", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Produit", "Supprimer", nullptr));
        label->setText(QCoreApplication::translate("Produit", "Nom produit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Produit: public Ui_Produit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUIT_H
