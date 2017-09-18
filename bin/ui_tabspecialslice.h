/********************************************************************************
** Form generated from reading UI file 'tabspecialslice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABSPECIALSLICE_H
#define UI_TABSPECIALSLICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabspecialslice
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
    QLabel *label_2;
    QSpinBox *spinBoxPrintNumber;
    QCheckBox *checkBoxDyeingType;
    QComboBox *comboBoxDyeingType;
    QCheckBox *checkBoxDyeingIndex;
    QComboBox *comboBoxDyeingIndex;
    QCheckBox *checkBoxSlicePerson;
    QComboBox *comboBoxSlicePerson;
    QCheckBox *checkBoxDyeingPerson;
    QComboBox *comboBoxDyeingPerson;
    QCheckBox *checkBoxOther;
    QLineEdit *lineEditOther;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *tabspecialslice)
    {
        if (tabspecialslice->objectName().isEmpty())
            tabspecialslice->setObjectName(QStringLiteral("tabspecialslice"));
        tabspecialslice->resize(1207, 705);
        actionNewSlice = new QAction(tabspecialslice);
        actionNewSlice->setObjectName(QStringLiteral("actionNewSlice"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewSlice->setIcon(icon);
        actionNewMore = new QAction(tabspecialslice);
        actionNewMore->setObjectName(QStringLiteral("actionNewMore"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/newmore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewMore->setIcon(icon1);
        actionPrintLabel = new QAction(tabspecialslice);
        actionPrintLabel->setObjectName(QStringLiteral("actionPrintLabel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/print.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintLabel->setIcon(icon2);
        actionDeleteInfo = new QAction(tabspecialslice);
        actionDeleteInfo->setObjectName(QStringLiteral("actionDeleteInfo"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/critical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteInfo->setIcon(icon3);
        actionPrintTemplate = new QAction(tabspecialslice);
        actionPrintTemplate->setObjectName(QStringLiteral("actionPrintTemplate"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/tempalte.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintTemplate->setIcon(icon4);
        centralwidget = new QWidget(tabspecialslice);
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

        label_2 = new QLabel(widgetTable);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxPrintNumber = new QSpinBox(widgetTable);
        spinBoxPrintNumber->setObjectName(QStringLiteral("spinBoxPrintNumber"));

        horizontalLayout->addWidget(spinBoxPrintNumber);

        checkBoxDyeingType = new QCheckBox(widgetTable);
        checkBoxDyeingType->setObjectName(QStringLiteral("checkBoxDyeingType"));

        horizontalLayout->addWidget(checkBoxDyeingType);

        comboBoxDyeingType = new QComboBox(widgetTable);
        comboBoxDyeingType->setObjectName(QStringLiteral("comboBoxDyeingType"));

        horizontalLayout->addWidget(comboBoxDyeingType);

        checkBoxDyeingIndex = new QCheckBox(widgetTable);
        checkBoxDyeingIndex->setObjectName(QStringLiteral("checkBoxDyeingIndex"));

        horizontalLayout->addWidget(checkBoxDyeingIndex);

        comboBoxDyeingIndex = new QComboBox(widgetTable);
        comboBoxDyeingIndex->setObjectName(QStringLiteral("comboBoxDyeingIndex"));

        horizontalLayout->addWidget(comboBoxDyeingIndex);

        checkBoxSlicePerson = new QCheckBox(widgetTable);
        checkBoxSlicePerson->setObjectName(QStringLiteral("checkBoxSlicePerson"));

        horizontalLayout->addWidget(checkBoxSlicePerson);

        comboBoxSlicePerson = new QComboBox(widgetTable);
        comboBoxSlicePerson->setObjectName(QStringLiteral("comboBoxSlicePerson"));

        horizontalLayout->addWidget(comboBoxSlicePerson);

        checkBoxDyeingPerson = new QCheckBox(widgetTable);
        checkBoxDyeingPerson->setObjectName(QStringLiteral("checkBoxDyeingPerson"));

        horizontalLayout->addWidget(checkBoxDyeingPerson);

        comboBoxDyeingPerson = new QComboBox(widgetTable);
        comboBoxDyeingPerson->setObjectName(QStringLiteral("comboBoxDyeingPerson"));

        horizontalLayout->addWidget(comboBoxDyeingPerson);

        checkBoxOther = new QCheckBox(widgetTable);
        checkBoxOther->setObjectName(QStringLiteral("checkBoxOther"));

        horizontalLayout->addWidget(checkBoxOther);

        lineEditOther = new QLineEdit(widgetTable);
        lineEditOther->setObjectName(QStringLiteral("lineEditOther"));

        horizontalLayout->addWidget(lineEditOther);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(widgetTable);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter->addWidget(widgetTable);

        verticalLayout->addWidget(splitter);

        tabspecialslice->setCentralWidget(centralwidget);
        toolBar = new QToolBar(tabspecialslice);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabspecialslice->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionNewSlice);
        toolBar->addAction(actionNewMore);
        toolBar->addSeparator();
        toolBar->addAction(actionPrintLabel);
        toolBar->addSeparator();
        toolBar->addAction(actionDeleteInfo);
        toolBar->addSeparator();
        toolBar->addAction(actionPrintTemplate);
        toolBar->addSeparator();

        retranslateUi(tabspecialslice);

        QMetaObject::connectSlotsByName(tabspecialslice);
    } // setupUi

    void retranslateUi(QMainWindow *tabspecialslice)
    {
        tabspecialslice->setWindowTitle(QApplication::translate("tabspecialslice", "MainWindow", 0));
        actionNewSlice->setText(QApplication::translate("tabspecialslice", "\346\226\260\345\273\272\345\210\207\347\211\207", 0));
#ifndef QT_NO_TOOLTIP
        actionNewSlice->setToolTip(QApplication::translate("tabspecialslice", "\346\226\260\345\273\272\345\210\207\347\211\207", 0));
#endif // QT_NO_TOOLTIP
        actionNewMore->setText(QApplication::translate("tabspecialslice", "\346\211\271\351\207\217\346\226\260\345\242\236", 0));
#ifndef QT_NO_TOOLTIP
        actionNewMore->setToolTip(QApplication::translate("tabspecialslice", "\346\211\271\351\207\217\346\226\260\345\242\236", 0));
#endif // QT_NO_TOOLTIP
        actionPrintLabel->setText(QApplication::translate("tabspecialslice", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintLabel->setToolTip(QApplication::translate("tabspecialslice", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#endif // QT_NO_TOOLTIP
        actionDeleteInfo->setText(QApplication::translate("tabspecialslice", "\345\210\240\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionDeleteInfo->setToolTip(QApplication::translate("tabspecialslice", "\345\210\240\351\231\244", 0));
#endif // QT_NO_TOOLTIP
        actionPrintTemplate->setText(QApplication::translate("tabspecialslice", "\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintTemplate->setToolTip(QApplication::translate("tabspecialslice", "\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("tabspecialslice", "\347\274\226\345\217\267\357\274\232", 0));
        pushButtonFind->setText(QApplication::translate("tabspecialslice", "    \346\237\245\346\211\276", 0));
        label_2->setText(QApplication::translate("tabspecialslice", "\346\211\253\346\217\217\346\227\266\346\211\223\345\215\260\346\225\260\351\207\217;", 0));
        checkBoxDyeingType->setText(QApplication::translate("tabspecialslice", "\346\237\223\350\211\262\347\261\273\345\236\213", 0));
        checkBoxDyeingIndex->setText(QApplication::translate("tabspecialslice", "\346\237\223\350\211\262\346\214\207\346\240\207", 0));
        checkBoxSlicePerson->setText(QApplication::translate("tabspecialslice", "\345\210\207\347\211\207\344\272\272", 0));
        checkBoxDyeingPerson->setText(QApplication::translate("tabspecialslice", "\346\237\223\350\211\262\344\272\272", 0));
        checkBoxOther->setText(QApplication::translate("tabspecialslice", "\345\205\266\344\273\226", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tabspecialslice", "\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("tabspecialslice", "\346\237\223\350\211\262\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("tabspecialslice", "\346\237\223\350\211\262\346\214\207\346\240\207", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("tabspecialslice", "\346\211\223\345\215\260\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("tabspecialslice", "\345\210\207\347\211\207\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("tabspecialslice", "\345\210\207\347\211\207\344\272\272", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("tabspecialslice", "\346\237\223\350\211\262\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("tabspecialslice", "\346\237\223\350\211\262\344\272\272", 0));
        toolBar->setWindowTitle(QApplication::translate("tabspecialslice", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class tabspecialslice: public Ui_tabspecialslice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABSPECIALSLICE_H
