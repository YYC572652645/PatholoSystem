/********************************************************************************
** Form generated from reading UI file 'tabregister.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABREGISTER_H
#define UI_TABREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabregister
{
public:
    QAction *actionNewNumber;
    QAction *actionNewMoreNumber;
    QAction *actionPrintLabel;
    QAction *actionPrintMoreLabel;
    QAction *actionDeleteInfo;
    QAction *actionClearInfo;
    QAction *actionExtendExcel;
    QAction *actionPrintTemplate;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *widgetTable;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButtonFind;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelMovie;
    QPushButton *pushButtonRefresh;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QWidget *widgetInfo;
    QToolBar *toolBar;

    void setupUi(QMainWindow *tabregister)
    {
        if (tabregister->objectName().isEmpty())
            tabregister->setObjectName(QStringLiteral("tabregister"));
        tabregister->resize(952, 672);
        actionNewNumber = new QAction(tabregister);
        actionNewNumber->setObjectName(QStringLiteral("actionNewNumber"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewNumber->setIcon(icon);
        actionNewMoreNumber = new QAction(tabregister);
        actionNewMoreNumber->setObjectName(QStringLiteral("actionNewMoreNumber"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/newmore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewMoreNumber->setIcon(icon1);
        actionPrintLabel = new QAction(tabregister);
        actionPrintLabel->setObjectName(QStringLiteral("actionPrintLabel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/print.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintLabel->setIcon(icon2);
        actionPrintMoreLabel = new QAction(tabregister);
        actionPrintMoreLabel->setObjectName(QStringLiteral("actionPrintMoreLabel"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/printmore.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintMoreLabel->setIcon(icon3);
        actionDeleteInfo = new QAction(tabregister);
        actionDeleteInfo->setObjectName(QStringLiteral("actionDeleteInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/critical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteInfo->setIcon(icon4);
        actionClearInfo = new QAction(tabregister);
        actionClearInfo->setObjectName(QStringLiteral("actionClearInfo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/image/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearInfo->setIcon(icon5);
        actionExtendExcel = new QAction(tabregister);
        actionExtendExcel->setObjectName(QStringLiteral("actionExtendExcel"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/image/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExtendExcel->setIcon(icon6);
        actionPrintTemplate = new QAction(tabregister);
        actionPrintTemplate->setObjectName(QStringLiteral("actionPrintTemplate"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/image/tempalte.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintTemplate->setIcon(icon7);
        centralwidget = new QWidget(tabregister);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        widgetTable = new QWidget(splitter);
        widgetTable->setObjectName(QStringLiteral("widgetTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetTable->sizePolicy().hasHeightForWidth());
        widgetTable->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(widgetTable);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widgetTable);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widgetTable);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButtonFind = new QPushButton(widgetTable);
        pushButtonFind->setObjectName(QStringLiteral("pushButtonFind"));
        pushButtonFind->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/image/serch.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonFind->setIcon(icon8);

        horizontalLayout->addWidget(pushButtonFind);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelMovie = new QLabel(widgetTable);
        labelMovie->setObjectName(QStringLiteral("labelMovie"));
        labelMovie->setPixmap(QPixmap(QString::fromUtf8(":/image/image/refresh.png")));

        horizontalLayout->addWidget(labelMovie);

        pushButtonRefresh = new QPushButton(widgetTable);
        pushButtonRefresh->setObjectName(QStringLiteral("pushButtonRefresh"));
        pushButtonRefresh->setMinimumSize(QSize(40, 0));
        pushButtonRefresh->setMaximumSize(QSize(40, 16777215));
        pushButtonRefresh->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"    color:skyblue;\n"
"}\n"
"QPushButton\n"
"{\n"
"background-color:transparent;\n"
"}"));

        horizontalLayout->addWidget(pushButtonRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(widgetTable);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(tableWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter->addWidget(widgetTable);
        widgetInfo = new QWidget(splitter);
        widgetInfo->setObjectName(QStringLiteral("widgetInfo"));
        sizePolicy1.setHeightForWidth(widgetInfo->sizePolicy().hasHeightForWidth());
        widgetInfo->setSizePolicy(sizePolicy1);
        splitter->addWidget(widgetInfo);

        verticalLayout->addWidget(splitter);

        tabregister->setCentralWidget(centralwidget);
        toolBar = new QToolBar(tabregister);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabregister->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionNewNumber);
        toolBar->addAction(actionNewMoreNumber);
        toolBar->addSeparator();
        toolBar->addAction(actionPrintLabel);
        toolBar->addAction(actionPrintMoreLabel);
        toolBar->addSeparator();
        toolBar->addAction(actionDeleteInfo);
        toolBar->addAction(actionClearInfo);
        toolBar->addSeparator();
        toolBar->addAction(actionExtendExcel);
        toolBar->addAction(actionPrintTemplate);
        toolBar->addSeparator();

        retranslateUi(tabregister);

        QMetaObject::connectSlotsByName(tabregister);
    } // setupUi

    void retranslateUi(QMainWindow *tabregister)
    {
        tabregister->setWindowTitle(QApplication::translate("tabregister", "MainWindow", 0));
        actionNewNumber->setText(QApplication::translate("tabregister", "\346\226\260\347\274\226\345\217\267", 0));
#ifndef QT_NO_TOOLTIP
        actionNewNumber->setToolTip(QApplication::translate("tabregister", "\346\226\260\347\274\226\345\217\267", 0));
#endif // QT_NO_TOOLTIP
        actionNewMoreNumber->setText(QApplication::translate("tabregister", "\346\211\271\351\207\217\347\274\226\345\217\267", 0));
#ifndef QT_NO_TOOLTIP
        actionNewMoreNumber->setToolTip(QApplication::translate("tabregister", "\346\211\271\351\207\217\347\274\226\345\217\267", 0));
#endif // QT_NO_TOOLTIP
        actionPrintLabel->setText(QApplication::translate("tabregister", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintLabel->setToolTip(QApplication::translate("tabregister", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#endif // QT_NO_TOOLTIP
        actionPrintMoreLabel->setText(QApplication::translate("tabregister", "\346\211\271\351\207\217\346\211\223\345\215\260", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintMoreLabel->setToolTip(QApplication::translate("tabregister", "\346\211\271\351\207\217\346\211\223\345\215\260", 0));
#endif // QT_NO_TOOLTIP
        actionDeleteInfo->setText(QApplication::translate("tabregister", "\345\210\240\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionDeleteInfo->setToolTip(QApplication::translate("tabregister", "\345\210\240\351\231\244", 0));
#endif // QT_NO_TOOLTIP
        actionClearInfo->setText(QApplication::translate("tabregister", "\346\270\205\347\251\272", 0));
#ifndef QT_NO_TOOLTIP
        actionClearInfo->setToolTip(QApplication::translate("tabregister", "\346\270\205\347\251\272", 0));
#endif // QT_NO_TOOLTIP
        actionExtendExcel->setText(QApplication::translate("tabregister", "\345\257\274\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        actionExtendExcel->setToolTip(QApplication::translate("tabregister", "\345\257\274\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        actionPrintTemplate->setText(QApplication::translate("tabregister", "\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintTemplate->setToolTip(QApplication::translate("tabregister", "\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("tabregister", "\347\227\205\347\220\206\345\217\267\357\274\232", 0));
        pushButtonFind->setText(QApplication::translate("tabregister", "    \346\237\245\346\211\276", 0));
        labelMovie->setText(QString());
        pushButtonRefresh->setText(QApplication::translate("tabregister", "\345\210\267\346\226\260", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tabregister", "\345\272\217\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("tabregister", "\347\227\205\347\220\206\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("tabregister", "\346\211\223\345\215\260\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("tabregister", "\345\267\262\346\211\223\345\215\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("tabregister", "\345\210\233\345\273\272\346\227\245\346\234\237", 0));
        toolBar->setWindowTitle(QApplication::translate("tabregister", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class tabregister: public Ui_tabregister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABREGISTER_H
