/********************************************************************************
** Form generated from reading UI file 'tabimmuneslice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABIMMUNESLICE_H
#define UI_TABIMMUNESLICE_H

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

class Ui_tabimmuneslice
{
public:
    QAction *actionNewSlice;
    QAction *actionNewMore;
    QAction *actionPrintLabel;
    QAction *actionDeleteInfo;
    QAction *actionPrintTemplate;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *widgetTable;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNumber;
    QPushButton *pushButtonFind;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelMovie;
    QPushButton *pushButtonRefresh;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *tabimmuneslice)
    {
        if (tabimmuneslice->objectName().isEmpty())
            tabimmuneslice->setObjectName(QStringLiteral("tabimmuneslice"));
        tabimmuneslice->resize(1207, 705);
        actionNewSlice = new QAction(tabimmuneslice);
        actionNewSlice->setObjectName(QStringLiteral("actionNewSlice"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewSlice->setIcon(icon);
        actionNewMore = new QAction(tabimmuneslice);
        actionNewMore->setObjectName(QStringLiteral("actionNewMore"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/newmore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewMore->setIcon(icon1);
        actionPrintLabel = new QAction(tabimmuneslice);
        actionPrintLabel->setObjectName(QStringLiteral("actionPrintLabel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/print.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintLabel->setIcon(icon2);
        actionDeleteInfo = new QAction(tabimmuneslice);
        actionDeleteInfo->setObjectName(QStringLiteral("actionDeleteInfo"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/critical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteInfo->setIcon(icon3);
        actionPrintTemplate = new QAction(tabimmuneslice);
        actionPrintTemplate->setObjectName(QStringLiteral("actionPrintTemplate"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/tempalte.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintTemplate->setIcon(icon4);
        centralwidget = new QWidget(tabimmuneslice);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        widgetTable = new QWidget(splitter);
        widgetTable->setObjectName(QStringLiteral("widgetTable"));
        verticalLayout_3 = new QVBoxLayout(widgetTable);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widgetTable);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditNumber = new QLineEdit(widgetTable);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));

        horizontalLayout->addWidget(lineEditNumber);

        pushButtonFind = new QPushButton(widgetTable);
        pushButtonFind->setObjectName(QStringLiteral("pushButtonFind"));
        pushButtonFind->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/image/serch.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonFind->setIcon(icon5);

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
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
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
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral("*{outline:0px;}"));

        verticalLayout_2->addWidget(tableWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter->addWidget(widgetTable);

        verticalLayout->addWidget(splitter);

        tabimmuneslice->setCentralWidget(centralwidget);
        toolBar = new QToolBar(tabimmuneslice);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabimmuneslice->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionNewSlice);
        toolBar->addAction(actionNewMore);
        toolBar->addSeparator();
        toolBar->addAction(actionPrintLabel);
        toolBar->addSeparator();
        toolBar->addAction(actionDeleteInfo);
        toolBar->addSeparator();
        toolBar->addAction(actionPrintTemplate);
        toolBar->addSeparator();

        retranslateUi(tabimmuneslice);

        QMetaObject::connectSlotsByName(tabimmuneslice);
    } // setupUi

    void retranslateUi(QMainWindow *tabimmuneslice)
    {
        tabimmuneslice->setWindowTitle(QApplication::translate("tabimmuneslice", "MainWindow", 0));
        actionNewSlice->setText(QApplication::translate("tabimmuneslice", "\346\226\260\345\273\272\345\210\207\347\211\207", 0));
#ifndef QT_NO_TOOLTIP
        actionNewSlice->setToolTip(QApplication::translate("tabimmuneslice", "\346\226\260\345\273\272\345\210\207\347\211\207", 0));
#endif // QT_NO_TOOLTIP
        actionNewMore->setText(QApplication::translate("tabimmuneslice", "\346\211\271\351\207\217\346\226\260\345\242\236", 0));
#ifndef QT_NO_TOOLTIP
        actionNewMore->setToolTip(QApplication::translate("tabimmuneslice", "\346\211\271\351\207\217\346\226\260\345\242\236", 0));
#endif // QT_NO_TOOLTIP
        actionPrintLabel->setText(QApplication::translate("tabimmuneslice", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintLabel->setToolTip(QApplication::translate("tabimmuneslice", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#endif // QT_NO_TOOLTIP
        actionDeleteInfo->setText(QApplication::translate("tabimmuneslice", "\345\210\240\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionDeleteInfo->setToolTip(QApplication::translate("tabimmuneslice", "\345\210\240\351\231\244", 0));
#endif // QT_NO_TOOLTIP
        actionPrintTemplate->setText(QApplication::translate("tabimmuneslice", "\346\240\207\347\255\276\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintTemplate->setToolTip(QApplication::translate("tabimmuneslice", "\346\240\207\347\255\276\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("tabimmuneslice", "\347\274\226\345\217\267\357\274\232", 0));
        pushButtonFind->setText(QApplication::translate("tabimmuneslice", "    \346\237\245\346\211\276", 0));
        labelMovie->setText(QString());
        pushButtonRefresh->setText(QApplication::translate("tabimmuneslice", "\345\210\267\346\226\260", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tabimmuneslice", "\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("tabimmuneslice", "\345\205\213\351\232\206\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("tabimmuneslice", "\345\267\262\346\211\223\345\215\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("tabimmuneslice", "\346\211\223\345\215\260\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("tabimmuneslice", "\346\237\223\350\211\262\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("tabimmuneslice", "\346\237\223\350\211\262\346\214\207\346\240\207", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("tabimmuneslice", "\345\210\207\347\211\207\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("tabimmuneslice", "\345\210\207\347\211\207\344\272\272", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("tabimmuneslice", "\346\237\223\350\211\262\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("tabimmuneslice", "\346\237\223\350\211\262\344\272\272", 0));
        toolBar->setWindowTitle(QApplication::translate("tabimmuneslice", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class tabimmuneslice: public Ui_tabimmuneslice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABIMMUNESLICE_H
