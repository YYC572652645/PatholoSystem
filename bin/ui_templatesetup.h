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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "printtemplate/movewidgetcontrol/movewidgetcontrol.h"
#include "printtemplate/qcustomplot/qcustomplot.h"
#include "qttreepropertybrowser.h"

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
    QCustomPlot *widgetPaint;
    QVBoxLayout *verticalLayout_3;
    MoveWidgetControl *widgetControl;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonCancel;
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
    QtTreePropertyBrowser *widgetProperty;
    QToolBar *toolBar;

    void setupUi(QMainWindow *templatesetup)
    {
        if (templatesetup->objectName().isEmpty())
            templatesetup->setObjectName(QStringLiteral("templatesetup"));
        templatesetup->resize(899, 612);
        templatesetup->setMinimumSize(QSize(899, 612));
        templatesetup->setMaximumSize(QSize(899, 612));
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
        groupBox_2->setMaximumSize(QSize(645, 520));
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
        widgetPaint = new QCustomPlot(groupBox_2);
        widgetPaint->setObjectName(QStringLiteral("widgetPaint"));
        widgetPaint->setMinimumSize(QSize(625, 500));
        widgetPaint->setMaximumSize(QSize(625, 500));
        verticalLayout_3 = new QVBoxLayout(widgetPaint);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widgetControl = new MoveWidgetControl(widgetPaint);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(625, 500));
        widgetControl->setMaximumSize(QSize(625, 500));
        verticalLayout_9 = new QVBoxLayout(widgetControl);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer = new QSpacerItem(20, 479, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        verticalLayout_3->addWidget(widgetControl);


        verticalLayout_7->addWidget(widgetPaint);


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

        pushButtonOk = new QPushButton(groupBox_3);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_2->addWidget(pushButtonOk);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButtonCancel = new QPushButton(groupBox_3);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);

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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/plus.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon1);
        pushButtonAdd->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonSub = new QPushButton(groupBox);
        pushButtonSub->setObjectName(QStringLiteral("pushButtonSub"));
        sizePolicy.setHeightForWidth(pushButtonSub->sizePolicy().hasHeightForWidth());
        pushButtonSub->setSizePolicy(sizePolicy);
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
        new QListWidgetItem(listWidgetControl);
        new QListWidgetItem(listWidgetControl);
        new QListWidgetItem(listWidgetControl);
        new QListWidgetItem(listWidgetControl);
        listWidgetControl->setObjectName(QStringLiteral("listWidgetControl"));
        listWidgetControl->setMinimumSize(QSize(0, 160));
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

        widgetProperty = new QtTreePropertyBrowser(groupBox);
        widgetProperty->setObjectName(QStringLiteral("widgetProperty"));

        verticalLayout->addWidget(widgetProperty);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_8->addLayout(verticalLayout_2);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_6->addLayout(horizontalLayout_3);

        templatesetup->setCentralWidget(centralWidget);
        toolBar = new QToolBar(templatesetup);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        templatesetup->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionDelete);

        retranslateUi(templatesetup);

        QMetaObject::connectSlotsByName(templatesetup);
    } // setupUi

    void retranslateUi(QMainWindow *templatesetup)
    {
        templatesetup->setWindowTitle(QApplication::translate("templatesetup", "MainWindow", 0));
        actionDelete->setText(QApplication::translate("templatesetup", "\345\210\240\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("templatesetup", "\345\210\240\351\231\244", 0));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        pushButtonOk->setText(QApplication::translate("templatesetup", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("templatesetup", "\345\217\226\346\266\210", 0));
        groupBox->setTitle(QString());
        pushButtonAdd->setText(QApplication::translate("templatesetup", "  \346\267\273\345\212\240\346\250\241\346\235\277", 0));
        pushButtonSub->setText(QApplication::translate("templatesetup", "  \345\210\240\351\231\244\346\250\241\346\235\277", 0));
        labelTemplateTitle->setText(QApplication::translate("templatesetup", "\346\250\241\346\235\277\345\220\215\347\247\260", 0));
        labelTitle->setText(QApplication::translate("templatesetup", "\345\267\245\345\205\267\347\256\261", 0));

        const bool __sortingEnabled = listWidgetControl->isSortingEnabled();
        listWidgetControl->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidgetControl->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("templatesetup", "\346\226\207\345\255\227", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidgetControl->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("templatesetup", "\347\227\205\347\220\206\345\217\267", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidgetControl->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("templatesetup", "\346\235\241\347\240\201", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidgetControl->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("templatesetup", "\344\272\214\347\273\264\346\235\241\347\240\201", 0));
        listWidgetControl->setSortingEnabled(__sortingEnabled);

        toolBar->setWindowTitle(QApplication::translate("templatesetup", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class templatesetup: public Ui_templatesetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATESETUP_H
