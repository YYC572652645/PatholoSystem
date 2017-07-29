/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIcoImage;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidgetTotal;
    QWidget *tabRegister;
    QWidget *tabMaterial;
    QWidget *tabRegularSlices;
    QWidget *tabImmuneSlices;
    QWidget *tabSpecialSlices;
    QWidget *tabDrawStatics;
    QWidget *tabSystemSettings;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1038, 719);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelIcoImage = new QLabel(centralWidget);
        labelIcoImage->setObjectName(QStringLiteral("labelIcoImage"));
        labelIcoImage->setMinimumSize(QSize(491, 78));
        labelIcoImage->setMaximumSize(QSize(16777215, 78));
        labelIcoImage->setStyleSheet(QStringLiteral("image: url(:/image/image/header.png);"));

        horizontalLayout->addWidget(labelIcoImage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tabWidgetTotal = new QTabWidget(centralWidget);
        tabWidgetTotal->setObjectName(QStringLiteral("tabWidgetTotal"));
        tabWidgetTotal->setMinimumSize(QSize(0, 0));
        tabWidgetTotal->setMaximumSize(QSize(16777215, 16777215));
        tabRegister = new QWidget();
        tabRegister->setObjectName(QStringLiteral("tabRegister"));
        tabWidgetTotal->addTab(tabRegister, QString());
        tabMaterial = new QWidget();
        tabMaterial->setObjectName(QStringLiteral("tabMaterial"));
        tabWidgetTotal->addTab(tabMaterial, QString());
        tabRegularSlices = new QWidget();
        tabRegularSlices->setObjectName(QStringLiteral("tabRegularSlices"));
        tabWidgetTotal->addTab(tabRegularSlices, QString());
        tabImmuneSlices = new QWidget();
        tabImmuneSlices->setObjectName(QStringLiteral("tabImmuneSlices"));
        tabWidgetTotal->addTab(tabImmuneSlices, QString());
        tabSpecialSlices = new QWidget();
        tabSpecialSlices->setObjectName(QStringLiteral("tabSpecialSlices"));
        tabWidgetTotal->addTab(tabSpecialSlices, QString());
        tabDrawStatics = new QWidget();
        tabDrawStatics->setObjectName(QStringLiteral("tabDrawStatics"));
        tabWidgetTotal->addTab(tabDrawStatics, QString());
        tabSystemSettings = new QWidget();
        tabSystemSettings->setObjectName(QStringLiteral("tabSystemSettings"));
        tabWidgetTotal->addTab(tabSystemSettings, QString());

        verticalLayout->addWidget(tabWidgetTotal);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1038, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidgetTotal->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelIcoImage->setText(QString());
        tabWidgetTotal->setTabText(tabWidgetTotal->indexOf(tabRegister), QApplication::translate("MainWindow", "\347\231\273\350\256\260", 0));
        tabWidgetTotal->setTabText(tabWidgetTotal->indexOf(tabMaterial), QApplication::translate("MainWindow", "\345\217\226\346\235\220", 0));
        tabWidgetTotal->setTabText(tabWidgetTotal->indexOf(tabRegularSlices), QApplication::translate("MainWindow", "\345\270\270\350\247\204\345\210\207\347\211\207", 0));
        tabWidgetTotal->setTabText(tabWidgetTotal->indexOf(tabImmuneSlices), QApplication::translate("MainWindow", "\345\205\215\347\226\253\347\273\204\345\214\226\345\210\207\347\211\207", 0));
        tabWidgetTotal->setTabText(tabWidgetTotal->indexOf(tabSpecialSlices), QApplication::translate("MainWindow", "\347\211\271\346\237\223\345\210\207\347\211\207", 0));
        tabWidgetTotal->setTabText(tabWidgetTotal->indexOf(tabDrawStatics), QApplication::translate("MainWindow", "\345\217\226\346\235\220\347\273\237\350\256\241", 0));
        tabWidgetTotal->setTabText(tabWidgetTotal->indexOf(tabSystemSettings), QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
