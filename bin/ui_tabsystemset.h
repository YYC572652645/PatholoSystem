/********************************************************************************
** Form generated from reading UI file 'tabsystemset.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABSYSTEMSET_H
#define UI_TABSYSTEMSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabsystemset
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QToolBar *toolBar;

    void setupUi(QMainWindow *tabsystemset)
    {
        if (tabsystemset->objectName().isEmpty())
            tabsystemset->setObjectName(QStringLiteral("tabsystemset"));
        tabsystemset->resize(800, 600);
        centralwidget = new QWidget(tabsystemset);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 40, 161, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 100, 81, 16));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(170, 100, 121, 22));
        pushButtonOk = new QPushButton(centralwidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(80, 170, 80, 20));
        pushButtonCancel = new QPushButton(centralwidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(200, 170, 80, 20));
        tabsystemset->setCentralWidget(centralwidget);
        toolBar = new QToolBar(tabsystemset);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        tabsystemset->addToolBar(Qt::LeftToolBarArea, toolBar);

        retranslateUi(tabsystemset);

        QMetaObject::connectSlotsByName(tabsystemset);
    } // setupUi

    void retranslateUi(QMainWindow *tabsystemset)
    {
        tabsystemset->setWindowTitle(QApplication::translate("tabsystemset", "MainWindow", 0));
        label->setText(QApplication::translate("tabsystemset", "\350\256\276\345\256\232\347\227\205\347\220\206\345\217\267\347\232\204\350\265\267\345\247\213\346\265\201\346\260\264\345\217\267", 0));
        label_2->setText(QApplication::translate("tabsystemset", "\350\265\267\345\247\213\346\265\201\346\260\264\345\217\267\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("tabsystemset", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("tabsystemset", "\345\217\226\346\266\210", 0));
        toolBar->setWindowTitle(QApplication::translate("tabsystemset", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class tabsystemset: public Ui_tabsystemset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABSYSTEMSET_H
