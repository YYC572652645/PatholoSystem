/********************************************************************************
** Form generated from reading UI file 'newspecialslice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSPECIALSLICE_H
#define UI_NEWSPECIALSLICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newspecialslice
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditCodeNumber;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpinBox *spinBoxPrintNumber;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBoxColorType;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QComboBox *comboBoxColorIndex;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditClone;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *comboBoxQPPeople;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_7;
    QDateEdit *dateEditQPTime;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QComboBox *comboBoxRSPeople;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QDateEdit *dateEditRSTime;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QMainWindow *newspecialslice)
    {
        if (newspecialslice->objectName().isEmpty())
            newspecialslice->setObjectName(QStringLiteral("newspecialslice"));
        newspecialslice->resize(600, 496);
        newspecialslice->setMinimumSize(QSize(600, 496));
        newspecialslice->setMaximumSize(QSize(600, 496));
        centralwidget = new QWidget(newspecialslice);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 400));
        groupBox->setMaximumSize(QSize(16777215, 400));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditCodeNumber = new QLineEdit(groupBox);
        lineEditCodeNumber->setObjectName(QStringLiteral("lineEditCodeNumber"));
        lineEditCodeNumber->setMinimumSize(QSize(180, 0));
        lineEditCodeNumber->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(lineEditCodeNumber);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxPrintNumber = new QSpinBox(groupBox);
        spinBoxPrintNumber->setObjectName(QStringLiteral("spinBoxPrintNumber"));
        spinBoxPrintNumber->setMinimumSize(QSize(180, 0));
        spinBoxPrintNumber->setMaximumSize(QSize(180, 16777215));
        spinBoxPrintNumber->setMinimum(1);
        spinBoxPrintNumber->setMaximum(1000000000);

        horizontalLayout->addWidget(spinBoxPrintNumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        comboBoxColorType = new QComboBox(groupBox);
        comboBoxColorType->setObjectName(QStringLiteral("comboBoxColorType"));
        comboBoxColorType->setMinimumSize(QSize(180, 0));
        comboBoxColorType->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_2->addWidget(comboBoxColorType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        comboBoxColorIndex = new QComboBox(groupBox);
        comboBoxColorIndex->setObjectName(QStringLiteral("comboBoxColorIndex"));
        comboBoxColorIndex->setMinimumSize(QSize(180, 0));
        comboBoxColorIndex->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_2->addWidget(comboBoxColorIndex);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        lineEditClone = new QLineEdit(groupBox);
        lineEditClone->setObjectName(QStringLiteral("lineEditClone"));

        horizontalLayout_3->addWidget(lineEditClone);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        comboBoxQPPeople = new QComboBox(groupBox);
        comboBoxQPPeople->setObjectName(QStringLiteral("comboBoxQPPeople"));
        comboBoxQPPeople->setMinimumSize(QSize(180, 0));
        comboBoxQPPeople->setMaximumSize(QSize(180, 16777215));
        comboBoxQPPeople->setEditable(true);

        horizontalLayout_4->addWidget(comboBoxQPPeople);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        dateEditQPTime = new QDateEdit(groupBox);
        dateEditQPTime->setObjectName(QStringLiteral("dateEditQPTime"));
        dateEditQPTime->setMinimumSize(QSize(180, 0));
        dateEditQPTime->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_4->addWidget(dateEditQPTime);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        comboBoxRSPeople = new QComboBox(groupBox);
        comboBoxRSPeople->setObjectName(QStringLiteral("comboBoxRSPeople"));
        comboBoxRSPeople->setMinimumSize(QSize(180, 0));
        comboBoxRSPeople->setMaximumSize(QSize(180, 16777215));
        comboBoxRSPeople->setEditable(true);

        horizontalLayout_5->addWidget(comboBoxRSPeople);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        dateEditRSTime = new QDateEdit(groupBox);
        dateEditRSTime->setObjectName(QStringLiteral("dateEditRSTime"));
        dateEditRSTime->setMinimumSize(QSize(180, 0));
        dateEditRSTime->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_5->addWidget(dateEditRSTime);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        pushButtonOk = new QPushButton(centralwidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_6->addWidget(pushButtonOk);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        pushButtonCancel = new QPushButton(centralwidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_6->addWidget(pushButtonCancel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_3);

        newspecialslice->setCentralWidget(centralwidget);

        retranslateUi(newspecialslice);

        QMetaObject::connectSlotsByName(newspecialslice);
    } // setupUi

    void retranslateUi(QMainWindow *newspecialslice)
    {
        newspecialslice->setWindowTitle(QApplication::translate("newspecialslice", "MainWindow", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("newspecialslice", "\346\235\220\345\235\227\347\274\226\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("newspecialslice", "\346\211\223\345\215\260\346\225\260\351\207\217\357\274\232", 0));
        label_3->setText(QApplication::translate("newspecialslice", "\346\237\223\350\211\262\347\261\273\345\236\213\357\274\232", 0));
        label_4->setText(QApplication::translate("newspecialslice", "\346\237\223\350\211\262\346\214\207\346\240\207\357\274\232", 0));
        label_5->setText(QApplication::translate("newspecialslice", "\345\205\213\351\232\206\345\217\267\347\240\201\357\274\232", 0));
        label_6->setText(QApplication::translate("newspecialslice", "\345\210\207\347\211\207\344\272\272\357\274\232", 0));
        label_7->setText(QApplication::translate("newspecialslice", "\345\210\207\347\211\207\346\227\266\351\227\264\357\274\232", 0));
        label_9->setText(QApplication::translate("newspecialslice", "\346\237\223\350\211\262\344\272\272\357\274\232", 0));
        label_8->setText(QApplication::translate("newspecialslice", "\346\237\223\350\211\262\346\227\266\351\227\264\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("newspecialslice", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("newspecialslice", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class newspecialslice: public Ui_newspecialslice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSPECIALSLICE_H
