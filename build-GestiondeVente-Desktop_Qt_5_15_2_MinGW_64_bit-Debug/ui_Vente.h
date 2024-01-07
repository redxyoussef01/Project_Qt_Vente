/********************************************************************************
** Form generated from reading UI file 'vente.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTE_H
#define UI_VENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton_8;
    QLabel *label_2;
    QLabel *label_4;
    QListView *listView_2;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QListView *listView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(815, 521);
        pushButton_8 = new QPushButton(Dialog);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(330, 360, 111, 24));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 400, 91, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        label_2->setFont(font);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 90, 91, 41));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        label_4->setFont(font1);
        listView_2 = new QListView(Dialog);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setGeometry(QRect(50, 130, 256, 261));
        pushButton_5 = new QPushButton(Dialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 460, 111, 24));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(600, 90, 91, 41));
        label_3->setFont(font1);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 190, 111, 24));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 40, 91, 41));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        label->setFont(font2);
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(620, 410, 113, 24));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 250, 111, 24));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(330, 280, 111, 24));
        pushButton_6 = new QPushButton(Dialog);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(260, 460, 111, 24));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(330, 160, 113, 24));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(330, 130, 111, 24));
        listView = new QListView(Dialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(480, 130, 261, 261));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 220, 111, 24));
        pushButton_7 = new QPushButton(Dialog);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(140, 460, 111, 24));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dialog", "Valider", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "total", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Stock", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Dialog", "Stock", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Panier", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Ajouter", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Ventes", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "modifier", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "supprimer", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Dialog", "products", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Annuler", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Dialog", "client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTE_H
