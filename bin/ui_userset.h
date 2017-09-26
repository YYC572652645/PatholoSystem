/********************************************************************************
** Form generated from reading UI file 'userset.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSET_H
#define UI_USERSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userset
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonExit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *userset)
    {
        if (userset->objectName().isEmpty())
            userset->setObjectName(QStringLiteral("userset"));
        userset->resize(409, 451);
        verticalLayout_2 = new QVBoxLayout(userset);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(userset);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(userset);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonNew = new QPushButton(userset);
        pushButtonNew->setObjectName(QStringLiteral("pushButtonNew"));
        pushButtonNew->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    border-radius:5px;\n"
"    border:2px solid gray;\n"
"    color:black;\n"
"    height:20px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgb(0,130,150);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"    background-color:rgb(85,170,255);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}"));

        horizontalLayout->addWidget(pushButtonNew);

        pushButtonUpdate = new QPushButton(userset);
        pushButtonUpdate->setObjectName(QStringLiteral("pushButtonUpdate"));
        pushButtonUpdate->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    border-radius:5px;\n"
"    border:2px solid gray;\n"
"    color:black;\n"
"    height:20px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgb(0,130,150);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"    background-color:rgb(85,170,255);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}"));

        horizontalLayout->addWidget(pushButtonUpdate);

        pushButtonDelete = new QPushButton(userset);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    border-radius:5px;\n"
"    border:2px solid gray;\n"
"    color:black;\n"
"    height:20px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgb(0,130,150);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"    background-color:rgb(85,170,255);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}"));

        horizontalLayout->addWidget(pushButtonDelete);

        pushButtonExit = new QPushButton(userset);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));
        pushButtonExit->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background-color: transparent;\n"
"    border-radius:5px;\n"
"    border:2px solid gray;\n"
"    color:black;\n"
"    height:20px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgb(0,130,150);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"    background-color:rgb(85,170,255);\n"
"    border-radius:5px;\n"
"    color:white;\n"
"}"));

        horizontalLayout->addWidget(pushButtonExit);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(userset);

        QMetaObject::connectSlotsByName(userset);
    } // setupUi

    void retranslateUi(QWidget *userset)
    {
        userset->setWindowTitle(QApplication::translate("userset", "Form", 0));
        label->setText(QApplication::translate("userset", "\350\256\276\347\275\256\347\224\250\346\210\267\345\217\212\346\223\215\344\275\234\346\235\203\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("userset", "\347\224\250\346\210\267\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("userset", "\347\256\241\347\220\206\345\221\230", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("userset", "\347\231\273\350\256\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("userset", "\345\217\226\346\235\220", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("userset", "\345\270\270\350\247\204\345\210\207\347\211\207", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("userset", "\345\205\215\347\226\253\347\273\204\345\214\226", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("userset", "\347\211\271\346\256\212\346\237\223\350\211\262", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("userset", "\346\237\245\350\257\242", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("userset", "\345\244\207\346\263\250", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("userset", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("userset", "\346\226\260\345\273\272\350\241\214", 0));
        pushButtonNew->setText(QApplication::translate("userset", "\346\226\260\345\273\272", 0));
        pushButtonUpdate->setText(QApplication::translate("userset", "\344\277\256\346\224\271", 0));
        pushButtonDelete->setText(QApplication::translate("userset", "\345\210\240\351\231\244", 0));
        pushButtonExit->setText(QApplication::translate("userset", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class userset: public Ui_userset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSET_H
