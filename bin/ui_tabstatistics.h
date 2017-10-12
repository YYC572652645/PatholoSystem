/********************************************************************************
** Form generated from reading UI file 'tabstatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABSTATISTICS_H
#define UI_TABSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabstatistics
{
public:
    QAction *actionReferesh;
    QAction *actionExtend;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateTimeEditBeginTime;
    QLabel *label;
    QDateEdit *dateTimeEditEndTime;
    QPushButton *pushButtonSum;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *tabstatistics)
    {
        if (tabstatistics->objectName().isEmpty())
            tabstatistics->setObjectName(QStringLiteral("tabstatistics"));
        tabstatistics->resize(800, 600);
        actionReferesh = new QAction(tabstatistics);
        actionReferesh->setObjectName(QStringLiteral("actionReferesh"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReferesh->setIcon(icon);
        actionExtend = new QAction(tabstatistics);
        actionExtend->setObjectName(QStringLiteral("actionExtend"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExtend->setIcon(icon1);
        centralwidget = new QWidget(tabstatistics);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dateTimeEditBeginTime = new QDateEdit(centralwidget);
        dateTimeEditBeginTime->setObjectName(QStringLiteral("dateTimeEditBeginTime"));

        horizontalLayout->addWidget(dateTimeEditBeginTime);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        dateTimeEditEndTime = new QDateEdit(centralwidget);
        dateTimeEditEndTime->setObjectName(QStringLiteral("dateTimeEditEndTime"));

        horizontalLayout->addWidget(dateTimeEditEndTime);

        pushButtonSum = new QPushButton(centralwidget);
        pushButtonSum->setObjectName(QStringLiteral("pushButtonSum"));
        pushButtonSum->setMinimumSize(QSize(120, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/tc.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSum->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonSum);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(centralwidget);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral("*{outline:0px;}"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);

        tabstatistics->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(tabstatistics);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        tabstatistics->setStatusBar(statusbar);
        toolBar = new QToolBar(tabstatistics);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabstatistics->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(tableWidget, dateTimeEditBeginTime);
        QWidget::setTabOrder(dateTimeEditBeginTime, dateTimeEditEndTime);
        QWidget::setTabOrder(dateTimeEditEndTime, pushButtonSum);

        toolBar->addAction(actionReferesh);
        toolBar->addAction(actionExtend);

        retranslateUi(tabstatistics);

        QMetaObject::connectSlotsByName(tabstatistics);
    } // setupUi

    void retranslateUi(QMainWindow *tabstatistics)
    {
        tabstatistics->setWindowTitle(QApplication::translate("tabstatistics", "MainWindow", 0));
        actionReferesh->setText(QApplication::translate("tabstatistics", "\345\210\267\346\226\260", 0));
#ifndef QT_NO_TOOLTIP
        actionReferesh->setToolTip(QApplication::translate("tabstatistics", "\345\210\267\346\226\260", 0));
#endif // QT_NO_TOOLTIP
        actionExtend->setText(QApplication::translate("tabstatistics", "\345\257\274\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        actionExtend->setToolTip(QApplication::translate("tabstatistics", "\345\257\274\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("tabstatistics", "\350\207\263\357\274\232", 0));
        pushButtonSum->setText(QApplication::translate("tabstatistics", "   \347\273\237\350\256\241", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tabstatistics", "\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("tabstatistics", "\345\217\226\346\235\220\346\200\273\344\276\213\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("tabstatistics", "\345\214\205\345\237\213\346\200\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("tabstatistics", "\345\270\270\350\247\204\345\217\226\346\235\220\344\276\213\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("tabstatistics", "\345\270\270\350\247\204\345\214\205\345\237\213\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("tabstatistics", "\345\206\260\345\206\273\345\217\226\346\235\220\344\276\213\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("tabstatistics", "\345\206\260\345\206\273\345\214\205\345\237\213\346\225\260", 0));
        toolBar->setWindowTitle(QApplication::translate("tabstatistics", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class tabstatistics: public Ui_tabstatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABSTATISTICS_H
