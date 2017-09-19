/********************************************************************************
** Form generated from reading UI file 'newmoreslices.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMORESLICES_H
#define UI_NEWMORESLICES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newmoreslices
{
public:
    QPushButton *pushButtonCancel;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBoxType;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpinBox *spinBoxPrintNumber;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_4;
    QSpinBox *spinBoxBianMaNumber;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButtonOk;

    void setupUi(QMainWindow *newmoreslices)
    {
        if (newmoreslices->objectName().isEmpty())
            newmoreslices->setObjectName(QStringLiteral("newmoreslices"));
        newmoreslices->resize(232, 228);
        newmoreslices->setMinimumSize(QSize(232, 228));
        newmoreslices->setMaximumSize(QSize(232, 228));
        pushButtonCancel = new QPushButton(newmoreslices);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(130, 190, 80, 30));
        pushButtonCancel->setMinimumSize(QSize(0, 30));
        newmoreslices->setCentralWidget(pushButtonCancel);
        groupBox = new QGroupBox(newmoreslices);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 211, 161));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"     border-width:1px;  \n"
"   border-style:solid;\n"
"   border-color:darkCyan;  \n"
"\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));

        horizontalLayout->addWidget(label);

        comboBoxType = new QComboBox(groupBox);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));
        comboBoxType->setMinimumSize(QSize(90, 0));
        comboBoxType->setEditable(true);

        horizontalLayout->addWidget(comboBoxType);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 0));

        horizontalLayout_2->addWidget(label_2);

        spinBoxPrintNumber = new QSpinBox(groupBox);
        spinBoxPrintNumber->setObjectName(QStringLiteral("spinBoxPrintNumber"));
        spinBoxPrintNumber->setMinimumSize(QSize(90, 0));
        spinBoxPrintNumber->setValue(1);

        horizontalLayout_2->addWidget(spinBoxPrintNumber);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(60, 0));

        horizontalLayout_4->addWidget(label_4);

        spinBoxBianMaNumber = new QSpinBox(groupBox);
        spinBoxBianMaNumber->setObjectName(QStringLiteral("spinBoxBianMaNumber"));
        spinBoxBianMaNumber->setMinimumSize(QSize(90, 0));
        spinBoxBianMaNumber->setValue(1);

        horizontalLayout_4->addWidget(spinBoxBianMaNumber);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_10);

        newmoreslices->setCentralWidget(groupBox);
        pushButtonOk = new QPushButton(newmoreslices);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(20, 190, 80, 30));
        pushButtonOk->setMinimumSize(QSize(0, 30));
        newmoreslices->setCentralWidget(pushButtonOk);

        retranslateUi(newmoreslices);

        QMetaObject::connectSlotsByName(newmoreslices);
    } // setupUi

    void retranslateUi(QMainWindow *newmoreslices)
    {
        newmoreslices->setWindowTitle(QApplication::translate("newmoreslices", "Dialog", 0));
        pushButtonCancel->setText(QApplication::translate("newmoreslices", "\345\217\226\346\266\210", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("newmoreslices", "\347\261\273    \345\210\253:", 0));
        label_2->setText(QApplication::translate("newmoreslices", "\346\211\223\345\215\260\346\225\260\351\207\217:", 0));
        label_4->setText(QApplication::translate("newmoreslices", "\347\274\226\347\240\201\346\225\260\351\207\217:", 0));
        pushButtonOk->setText(QApplication::translate("newmoreslices", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class newmoreslices: public Ui_newmoreslices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMORESLICES_H
