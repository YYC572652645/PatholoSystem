/********************************************************************************
** Form generated from reading UI file 'typesetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYPESETDIALOG_H
#define UI_TYPESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_typesetdialog
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditTypeAbbreviation;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditTypeName;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonCancel;

    void setupUi(QMainWindow *typesetdialog)
    {
        if (typesetdialog->objectName().isEmpty())
            typesetdialog->setObjectName(QStringLiteral("typesetdialog"));
        typesetdialog->resize(350, 231);
        typesetdialog->setMinimumSize(QSize(350, 231));
        typesetdialog->setMaximumSize(QSize(350, 231));
        centralwidget = new QWidget(typesetdialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditTypeAbbreviation = new QLineEdit(groupBox);
        lineEditTypeAbbreviation->setObjectName(QStringLiteral("lineEditTypeAbbreviation"));
        lineEditTypeAbbreviation->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(lineEditTypeAbbreviation);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditTypeName = new QLineEdit(groupBox);
        lineEditTypeName->setObjectName(QStringLiteral("lineEditTypeName"));
        lineEditTypeName->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(lineEditTypeName);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(groupBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonOk = new QPushButton(centralwidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_3->addWidget(pushButtonOk);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonCancel = new QPushButton(centralwidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_3->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        typesetdialog->setCentralWidget(centralwidget);

        retranslateUi(typesetdialog);

        QMetaObject::connectSlotsByName(typesetdialog);
    } // setupUi

    void retranslateUi(QMainWindow *typesetdialog)
    {
        typesetdialog->setWindowTitle(QApplication::translate("typesetdialog", "MainWindow", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("typesetdialog", "\347\261\273\345\210\253\347\274\251\345\206\231\357\274\232", 0));
        label_2->setText(QApplication::translate("typesetdialog", "\347\261\273\345\210\253\345\220\215\347\247\260\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("typesetdialog", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("typesetdialog", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class typesetdialog: public Ui_typesetdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYPESETDIALOG_H
