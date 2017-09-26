/********************************************************************************
** Form generated from reading UI file 'printset.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTSET_H
#define UI_PRINTSET_H

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

class Ui_printset
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *printset)
    {
        if (printset->objectName().isEmpty())
            printset->setObjectName(QStringLiteral("printset"));
        printset->resize(409, 451);
        verticalLayout_2 = new QVBoxLayout(printset);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(printset);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(printset);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonOk = new QPushButton(printset);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout->addWidget(pushButtonOk);

        pushButtonDelete = new QPushButton(printset);
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

        pushButtonCancel = new QPushButton(printset);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(printset);

        QMetaObject::connectSlotsByName(printset);
    } // setupUi

    void retranslateUi(QWidget *printset)
    {
        printset->setWindowTitle(QApplication::translate("printset", "Form", 0));
        label->setText(QApplication::translate("printset", "\350\256\276\347\275\256\345\220\204\345\217\260\350\256\241\347\256\227\346\234\272\346\211\200\350\277\236\346\216\245\347\232\204\346\211\223\345\215\260\346\234\272\345\217\202\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("printset", "\350\256\241\347\256\227\346\234\272IP", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("printset", "\350\256\241\347\256\227\346\234\272\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("printset", "\346\211\223\345\215\260\346\234\272\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("printset", "\350\277\236\346\216\245\346\226\271\345\274\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("printset", "\346\211\223\345\215\260\346\234\272IP", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("printset", "\347\253\257\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("printset", "\345\244\207\346\263\250", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("printset", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("printset", "\346\226\260\345\273\272\350\241\214", 0));
        pushButtonOk->setText(QApplication::translate("printset", "\347\241\256\345\256\232", 0));
        pushButtonDelete->setText(QApplication::translate("printset", "\345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("printset", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class printset: public Ui_printset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTSET_H
