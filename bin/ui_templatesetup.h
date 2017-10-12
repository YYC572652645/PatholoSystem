/********************************************************************************
** Form generated from reading UI file 'templatesetup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATESETUP_H
#define UI_TEMPLATESETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "printtemplate/movewidgetcontrol/movewidgetcontrol.h"

QT_BEGIN_NAMESPACE

class Ui_templatesetup
{
public:
    QAction *actionDelete;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_7;
    MoveWidgetControl *widgetControl;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSave;
    QSpacerItem *horizontalSpacer;
    QLabel *labelInfo;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonSub;
    QLabel *labelTemplateTitle;
    QListWidget *listWidgetTemplate;
    QLabel *labelTitle;
    QListWidget *listWidgetControl;
    QLabel *labelTitle_2;
    QTableWidget *tableWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *templatesetup)
    {
        if (templatesetup->objectName().isEmpty())
            templatesetup->setObjectName(QStringLiteral("templatesetup"));
        templatesetup->resize(904, 630);
        templatesetup->setMinimumSize(QSize(904, 630));
        templatesetup->setMaximumSize(QSize(906, 630));
        actionDelete = new QAction(templatesetup);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/critical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon);
        centralWidget = new QWidget(templatesetup);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(680, 520));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"border-radius: 5px;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color: darkCyan;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
"padding: 0 3px;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(groupBox_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        widgetControl = new MoveWidgetControl(groupBox_2);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(650, 500));
        widgetControl->setMaximumSize(QSize(650, 500));
        widgetControl->setStyleSheet(QStringLiteral("background-color:white"));
        verticalLayout_9 = new QVBoxLayout(widgetControl);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));

        verticalLayout_7->addWidget(widgetControl);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 50));
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"border-radius: 5px;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color: darkCyan;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
"padding: 0 3px;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonSave = new QPushButton(groupBox_3);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(131, 0));
        pushButtonSave->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout_2->addWidget(pushButtonSave);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelInfo = new QLabel(groupBox_3);
        labelInfo->setObjectName(QStringLiteral("labelInfo"));
        labelInfo->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:darkred;\n"
"font-size:14px;\n"
"}"));

        horizontalLayout_2->addWidget(labelInfo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addWidget(groupBox_3);


        horizontalLayout_3->addLayout(verticalLayout_5);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(250, 16777215));
        groupBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"border-radius: 5px;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color: darkCyan;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
"padding: 0 3px;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonAdd = new QPushButton(groupBox);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonAdd->sizePolicy().hasHeightForWidth());
        pushButtonAdd->setSizePolicy(sizePolicy);
        pushButtonAdd->setStyleSheet(QLatin1String("QPushButton\n"
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/plus.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon1);
        pushButtonAdd->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonSub = new QPushButton(groupBox);
        pushButtonSub->setObjectName(QStringLiteral("pushButtonSub"));
        sizePolicy.setHeightForWidth(pushButtonSub->sizePolicy().hasHeightForWidth());
        pushButtonSub->setSizePolicy(sizePolicy);
        pushButtonSub->setStyleSheet(QLatin1String("QPushButton\n"
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/delete.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSub->setIcon(icon2);
        pushButtonSub->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButtonSub);


        verticalLayout->addLayout(horizontalLayout);

        labelTemplateTitle = new QLabel(groupBox);
        labelTemplateTitle->setObjectName(QStringLiteral("labelTemplateTitle"));
        labelTemplateTitle->setMinimumSize(QSize(0, 25));
        labelTemplateTitle->setStyleSheet(QLatin1String("background-color:#2c3e50;\n"
"color:white;\n"
"\n"
"QLabel\n"
"{\n"
"    height:40px;\n"
"    font-size:28px;\n"
"}"));
        labelTemplateTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTemplateTitle);

        listWidgetTemplate = new QListWidget(groupBox);
        listWidgetTemplate->setObjectName(QStringLiteral("listWidgetTemplate"));
        listWidgetTemplate->setStyleSheet(QLatin1String("QListWidget::item\n"
"{\n"
"    height:40px;\n"
"    font-size:20px;\n"
"}\n"
"\n"
"QListWidget::item::hover\n"
"{\n"
"    background-color:rgb(9,150,200,100);\n"
"}\n"
"\n"
"QListWidget::item:selected\n"
"{\n"
"    background-color:rgb(9,150,200,255);\n"
"}"));

        verticalLayout->addWidget(listWidgetTemplate);

        labelTitle = new QLabel(groupBox);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setMinimumSize(QSize(0, 25));
        labelTitle->setStyleSheet(QLatin1String("background-color:#2c3e50;\n"
"\n"
"color:white;\n"
"\n"
"\n"
"QLabel\n"
"{\n"
"    height:40px;\n"
"    font-size:28px;\n"
"}"));
        labelTitle->setLineWidth(1);
        labelTitle->setAlignment(Qt::AlignCenter);
        labelTitle->setWordWrap(false);

        verticalLayout->addWidget(labelTitle);

        listWidgetControl = new QListWidget(groupBox);
        listWidgetControl->setObjectName(QStringLiteral("listWidgetControl"));
        listWidgetControl->setMinimumSize(QSize(0, 120));
        listWidgetControl->setStyleSheet(QLatin1String("QListWidget::item\n"
"{\n"
"    height:40px;\n"
"    font-size:20px;\n"
"}\n"
"\n"
"QListWidget::item::hover\n"
"{\n"
"    background-color:rgb(9,150,200,100);\n"
"}\n"
"\n"
"QListWidget::item:selected\n"
"{\n"
"    background-color:rgb(9,150,200,255);\n"
"}"));
        listWidgetControl->setLineWidth(1);

        verticalLayout->addWidget(listWidgetControl);

        labelTitle_2 = new QLabel(groupBox);
        labelTitle_2->setObjectName(QStringLiteral("labelTitle_2"));
        labelTitle_2->setMinimumSize(QSize(0, 25));
        labelTitle_2->setStyleSheet(QLatin1String("background-color:#2c3e50;\n"
"\n"
"color:white;\n"
"\n"
"\n"
"QLabel\n"
"{\n"
"    height:40px;\n"
"    font-size:28px;\n"
"}"));
        labelTitle_2->setLineWidth(1);
        labelTitle_2->setAlignment(Qt::AlignCenter);
        labelTitle_2->setWordWrap(false);

        verticalLayout->addWidget(labelTitle_2);

        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_8->addLayout(verticalLayout_2);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_6->addLayout(horizontalLayout_3);

        templatesetup->setCentralWidget(centralWidget);
        toolBar = new QToolBar(templatesetup);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        templatesetup->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(pushButtonSave, tableWidget);
        QWidget::setTabOrder(tableWidget, pushButtonAdd);
        QWidget::setTabOrder(pushButtonAdd, pushButtonSub);
        QWidget::setTabOrder(pushButtonSub, listWidgetControl);
        QWidget::setTabOrder(listWidgetControl, listWidgetTemplate);

        toolBar->addAction(actionDelete);

        retranslateUi(templatesetup);

        QMetaObject::connectSlotsByName(templatesetup);
    } // setupUi

    void retranslateUi(QMainWindow *templatesetup)
    {
        templatesetup->setWindowTitle(QApplication::translate("templatesetup", "MainWindow", 0));
        actionDelete->setText(QApplication::translate("templatesetup", "\345\210\240\351\231\244\346\216\247\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("templatesetup", "\345\210\240\351\231\244\346\216\247\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        widgetControl->setToolTip(QApplication::translate("templatesetup", "\346\211\223\345\215\260\345\214\272\345\237\237", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        widgetControl->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        widgetControl->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_3->setTitle(QString());
        pushButtonSave->setText(QApplication::translate("templatesetup", "\344\277\235\345\255\230", 0));
        labelInfo->setText(QString());
        groupBox->setTitle(QString());
        pushButtonAdd->setText(QApplication::translate("templatesetup", "  \346\267\273\345\212\240\346\250\241\346\235\277", 0));
        pushButtonSub->setText(QApplication::translate("templatesetup", "  \345\210\240\351\231\244\346\250\241\346\235\277", 0));
        labelTemplateTitle->setText(QApplication::translate("templatesetup", "\346\250\241\346\235\277\345\220\215\347\247\260", 0));
        labelTitle->setText(QApplication::translate("templatesetup", "\345\267\245\345\205\267\347\256\261", 0));
        labelTitle_2->setText(QApplication::translate("templatesetup", "\350\256\276\347\275\256", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("templatesetup", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("templatesetup", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("templatesetup", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("templatesetup", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("templatesetup", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("templatesetup", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("templatesetup", "\346\226\260\345\273\272\350\241\214", 0));
        toolBar->setWindowTitle(QApplication::translate("templatesetup", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class templatesetup: public Ui_templatesetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATESETUP_H
