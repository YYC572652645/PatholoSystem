/********************************************************************************
** Form generated from reading UI file 'newmoreimmuneslice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMOREIMMUNESLICE_H
#define UI_NEWMOREIMMUNESLICE_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newmoreimmuneslice
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
    QLineEdit *lineEditBlNumber;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_2;
    QSpinBox *spinBoxNumber;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonAddBLNumber;
    QRadioButton *radioButtonAddBlAndCode;
    QRadioButton *radioButtonAddBlAndCancel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonAddAll;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_4;
    QSpinBox *spinBoxPrintNumber;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBoxColorType;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_6;
    QComboBox *comboBoxColorIndex;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLineEdit *lineEditClone;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *comboBoxQPPeople;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_9;
    QDateEdit *dateEditQPTime;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *comboBoxRSPeople;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_10;
    QDateEdit *dateEditRSTime;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QMainWindow *newmoreimmuneslice)
    {
        if (newmoreimmuneslice->objectName().isEmpty())
            newmoreimmuneslice->setObjectName(QStringLiteral("newmoreimmuneslice"));
        newmoreimmuneslice->resize(627, 512);
        newmoreimmuneslice->setMinimumSize(QSize(627, 512));
        newmoreimmuneslice->setMaximumSize(QSize(627, 512));
        centralwidget = new QWidget(newmoreimmuneslice);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
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

        lineEditBlNumber = new QLineEdit(groupBox);
        lineEditBlNumber->setObjectName(QStringLiteral("lineEditBlNumber"));
        lineEditBlNumber->setMinimumSize(QSize(180, 0));
        lineEditBlNumber->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(lineEditBlNumber);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxNumber = new QSpinBox(groupBox);
        spinBoxNumber->setObjectName(QStringLiteral("spinBoxNumber"));
        spinBoxNumber->setMinimumSize(QSize(180, 0));
        spinBoxNumber->setMaximumSize(QSize(180, 16777215));
        spinBoxNumber->setMinimum(1);
        spinBoxNumber->setMaximum(1000000000);

        horizontalLayout->addWidget(spinBoxNumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButtonAddBLNumber = new QRadioButton(groupBox);
        radioButtonAddBLNumber->setObjectName(QStringLiteral("radioButtonAddBLNumber"));
        radioButtonAddBLNumber->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonAddBLNumber);

        radioButtonAddBlAndCode = new QRadioButton(groupBox);
        radioButtonAddBlAndCode->setObjectName(QStringLiteral("radioButtonAddBlAndCode"));

        horizontalLayout_2->addWidget(radioButtonAddBlAndCode);

        radioButtonAddBlAndCancel = new QRadioButton(groupBox);
        radioButtonAddBlAndCancel->setObjectName(QStringLiteral("radioButtonAddBlAndCancel"));
        radioButtonAddBlAndCancel->setMinimumSize(QSize(180, 0));

        horizontalLayout_2->addWidget(radioButtonAddBlAndCancel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButtonAddAll = new QRadioButton(groupBox);
        radioButtonAddAll->setObjectName(QStringLiteral("radioButtonAddAll"));
        radioButtonAddAll->setMinimumSize(QSize(180, 0));
        radioButtonAddAll->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_3->addWidget(radioButtonAddAll);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        spinBoxPrintNumber = new QSpinBox(groupBox);
        spinBoxPrintNumber->setObjectName(QStringLiteral("spinBoxPrintNumber"));
        spinBoxPrintNumber->setMinimumSize(QSize(180, 0));
        spinBoxPrintNumber->setMaximumSize(QSize(180, 16777215));
        spinBoxPrintNumber->setMinimum(1);
        spinBoxPrintNumber->setMaximum(1000000000);

        horizontalLayout_3->addWidget(spinBoxPrintNumber);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        comboBoxColorType = new QComboBox(groupBox);
        comboBoxColorType->setObjectName(QStringLiteral("comboBoxColorType"));
        comboBoxColorType->setMinimumSize(QSize(180, 0));
        comboBoxColorType->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_5->addWidget(comboBoxColorType);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        comboBoxColorIndex = new QComboBox(groupBox);
        comboBoxColorIndex->setObjectName(QStringLiteral("comboBoxColorIndex"));
        comboBoxColorIndex->setMinimumSize(QSize(180, 0));
        comboBoxColorIndex->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_5->addWidget(comboBoxColorIndex);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        lineEditClone = new QLineEdit(groupBox);
        lineEditClone->setObjectName(QStringLiteral("lineEditClone"));

        horizontalLayout_4->addWidget(lineEditClone);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        comboBoxQPPeople = new QComboBox(groupBox);
        comboBoxQPPeople->setObjectName(QStringLiteral("comboBoxQPPeople"));
        comboBoxQPPeople->setMinimumSize(QSize(180, 0));
        comboBoxQPPeople->setMaximumSize(QSize(180, 16777215));
        comboBoxQPPeople->setEditable(true);

        horizontalLayout_6->addWidget(comboBoxQPPeople);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        dateEditQPTime = new QDateEdit(groupBox);
        dateEditQPTime->setObjectName(QStringLiteral("dateEditQPTime"));
        dateEditQPTime->setMinimumSize(QSize(180, 0));
        dateEditQPTime->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_6->addWidget(dateEditQPTime);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        comboBoxRSPeople = new QComboBox(groupBox);
        comboBoxRSPeople->setObjectName(QStringLiteral("comboBoxRSPeople"));
        comboBoxRSPeople->setMinimumSize(QSize(180, 0));
        comboBoxRSPeople->setMaximumSize(QSize(180, 16777215));
        comboBoxRSPeople->setEditable(true);

        horizontalLayout_7->addWidget(comboBoxRSPeople);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_15);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        dateEditRSTime = new QDateEdit(groupBox);
        dateEditRSTime->setObjectName(QStringLiteral("dateEditRSTime"));
        dateEditRSTime->setMinimumSize(QSize(180, 0));
        dateEditRSTime->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_7->addWidget(dateEditRSTime);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        pushButtonOk = new QPushButton(centralwidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_8->addWidget(pushButtonOk);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        pushButtonCancel = new QPushButton(centralwidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_8->addWidget(pushButtonCancel);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(verticalLayout_3);

        newmoreimmuneslice->setCentralWidget(centralwidget);
        QWidget::setTabOrder(pushButtonOk, spinBoxNumber);
        QWidget::setTabOrder(spinBoxNumber, radioButtonAddBLNumber);
        QWidget::setTabOrder(radioButtonAddBLNumber, radioButtonAddBlAndCode);
        QWidget::setTabOrder(radioButtonAddBlAndCode, radioButtonAddBlAndCancel);
        QWidget::setTabOrder(radioButtonAddBlAndCancel, radioButtonAddAll);
        QWidget::setTabOrder(radioButtonAddAll, spinBoxPrintNumber);
        QWidget::setTabOrder(spinBoxPrintNumber, comboBoxColorType);
        QWidget::setTabOrder(comboBoxColorType, comboBoxColorIndex);
        QWidget::setTabOrder(comboBoxColorIndex, lineEditClone);
        QWidget::setTabOrder(lineEditClone, comboBoxQPPeople);
        QWidget::setTabOrder(comboBoxQPPeople, dateEditQPTime);
        QWidget::setTabOrder(dateEditQPTime, comboBoxRSPeople);
        QWidget::setTabOrder(comboBoxRSPeople, dateEditRSTime);
        QWidget::setTabOrder(dateEditRSTime, lineEditBlNumber);
        QWidget::setTabOrder(lineEditBlNumber, pushButtonCancel);

        retranslateUi(newmoreimmuneslice);

        QMetaObject::connectSlotsByName(newmoreimmuneslice);
    } // setupUi

    void retranslateUi(QMainWindow *newmoreimmuneslice)
    {
        newmoreimmuneslice->setWindowTitle(QApplication::translate("newmoreimmuneslice", "MainWindow", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("newmoreimmuneslice", "\347\227\205\347\220\206\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("newmoreimmuneslice", "\345\242\236\345\212\240\346\225\260\351\207\217\357\274\232", 0));
        spinBoxNumber->setPrefix(QString());
        radioButtonAddBLNumber->setText(QApplication::translate("newmoreimmuneslice", "\344\273\205\351\200\222\345\242\236\345\272\217\345\217\267", 0));
        radioButtonAddBlAndCode->setText(QApplication::translate("newmoreimmuneslice", "\344\273\205\351\200\222\345\242\236\347\227\205\347\220\206\345\217\267\344\270\224\345\270\246\345\272\217\345\217\267", 0));
        radioButtonAddBlAndCancel->setText(QApplication::translate("newmoreimmuneslice", "\344\273\205\351\200\222\345\242\236\347\227\205\347\220\206\345\217\267\357\274\214\344\270\224\345\217\226\346\266\210\345\272\217\345\217\267", 0));
        radioButtonAddAll->setText(QApplication::translate("newmoreimmuneslice", "\347\227\205\347\220\206\345\217\267\345\217\212\345\272\217\345\217\267\345\220\214\346\227\266\345\242\236\345\212\240", 0));
        label_4->setText(QApplication::translate("newmoreimmuneslice", "\346\211\223\345\215\260\346\225\260\351\207\217\357\274\232", 0));
        label_5->setText(QApplication::translate("newmoreimmuneslice", "\346\237\223\350\211\262\347\261\273\345\236\213\357\274\232", 0));
        label_6->setText(QApplication::translate("newmoreimmuneslice", "\346\237\223\350\211\262\346\214\207\346\240\207\357\274\232", 0));
        label_11->setText(QApplication::translate("newmoreimmuneslice", "\345\205\213\351\232\206\345\217\267\347\240\201\357\274\232", 0));
        label_7->setText(QApplication::translate("newmoreimmuneslice", "\345\210\207\347\211\207\344\272\272\357\274\232", 0));
        label_9->setText(QApplication::translate("newmoreimmuneslice", "\345\210\207\347\211\207\346\227\266\351\227\264\357\274\232", 0));
        label_8->setText(QApplication::translate("newmoreimmuneslice", "\346\237\223\350\211\262\344\272\272\357\274\232", 0));
        label_10->setText(QApplication::translate("newmoreimmuneslice", "\346\237\223\350\211\262\346\227\266\351\227\264\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("newmoreimmuneslice", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("newmoreimmuneslice", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class newmoreimmuneslice: public Ui_newmoreimmuneslice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMOREIMMUNESLICE_H
