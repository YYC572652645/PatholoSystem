/********************************************************************************
** Form generated from reading UI file 'coderole.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEROLE_H
#define UI_CODEROLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_coderole
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBoxBingLi;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditPrefix;
    QCheckBox *checkBoxType;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxYear;
    QRadioButton *radioButtonTwo;
    QRadioButton *radioButtonFour;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBoxMonth;
    QCheckBox *checkBoxDay;
    QLabel *label_2;
    QLineEdit *lineEditSpin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *spinBoxLength;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEditBingLiCodeDemo;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBoxQuCai;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBoxBingLiNumber;
    QCheckBox *checkBoxHyphen;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QComboBox *comboBoxNumberType;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QLineEdit *lineEditQuCaiCodeDemo;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_21;
    QGroupBox *groupBoxImport;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEditSpilt;
    QRadioButton *radioButtonUseMaterial;
    QRadioButton *radioButtonUseSlice;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *coderole)
    {
        if (coderole->objectName().isEmpty())
            coderole->setObjectName(QStringLiteral("coderole"));
        coderole->resize(1068, 801);
        verticalLayout_8 = new QVBoxLayout(coderole);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBoxBingLi = new QGroupBox(coderole);
        groupBoxBingLi->setObjectName(QStringLiteral("groupBoxBingLi"));
        verticalLayout_3 = new QVBoxLayout(groupBoxBingLi);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_12);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBoxBingLi);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEditPrefix = new QLineEdit(groupBoxBingLi);
        lineEditPrefix->setObjectName(QStringLiteral("lineEditPrefix"));

        horizontalLayout_2->addWidget(lineEditPrefix);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        checkBoxType = new QCheckBox(groupBoxBingLi);
        checkBoxType->setObjectName(QStringLiteral("checkBoxType"));
        checkBoxType->setChecked(true);

        horizontalLayout_6->addWidget(checkBoxType);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(groupBoxBingLi);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxYear = new QCheckBox(groupBox_2);
        checkBoxYear->setObjectName(QStringLiteral("checkBoxYear"));
        checkBoxYear->setChecked(true);

        horizontalLayout->addWidget(checkBoxYear);

        radioButtonTwo = new QRadioButton(groupBox_2);
        radioButtonTwo->setObjectName(QStringLiteral("radioButtonTwo"));
        radioButtonTwo->setChecked(true);

        horizontalLayout->addWidget(radioButtonTwo);

        radioButtonFour = new QRadioButton(groupBox_2);
        radioButtonFour->setObjectName(QStringLiteral("radioButtonFour"));

        horizontalLayout->addWidget(radioButtonFour);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addWidget(groupBox_2);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBoxMonth = new QCheckBox(groupBoxBingLi);
        checkBoxMonth->setObjectName(QStringLiteral("checkBoxMonth"));
        checkBoxMonth->setChecked(true);

        horizontalLayout_5->addWidget(checkBoxMonth);

        checkBoxDay = new QCheckBox(groupBoxBingLi);
        checkBoxDay->setObjectName(QStringLiteral("checkBoxDay"));
        checkBoxDay->setChecked(true);

        horizontalLayout_5->addWidget(checkBoxDay);

        label_2 = new QLabel(groupBoxBingLi);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEditSpin = new QLineEdit(groupBoxBingLi);
        lineEditSpin->setObjectName(QStringLiteral("lineEditSpin"));

        horizontalLayout_5->addWidget(lineEditSpin);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBoxBingLi);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        spinBoxLength = new QSpinBox(groupBoxBingLi);
        spinBoxLength->setObjectName(QStringLiteral("spinBoxLength"));
        spinBoxLength->setMinimum(1);

        horizontalLayout_4->addWidget(spinBoxLength);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_8);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(groupBoxBingLi);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        lineEditBingLiCodeDemo = new QLineEdit(groupBoxBingLi);
        lineEditBingLiCodeDemo->setObjectName(QStringLiteral("lineEditBingLiCodeDemo"));
        lineEditBingLiCodeDemo->setEnabled(false);
        lineEditBingLiCodeDemo->setStyleSheet(QLatin1String("QLineEdit:!enabled\n"
"{\n"
"color:black;\n"
"}"));

        horizontalLayout_7->addWidget(lineEditBingLiCodeDemo);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_15);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_17);


        verticalLayout_6->addWidget(groupBoxBingLi);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_2);

        groupBoxQuCai = new QGroupBox(coderole);
        groupBoxQuCai->setObjectName(QStringLiteral("groupBoxQuCai"));
        verticalLayout_5 = new QVBoxLayout(groupBoxQuCai);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_13);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkBoxBingLiNumber = new QCheckBox(groupBoxQuCai);
        checkBoxBingLiNumber->setObjectName(QStringLiteral("checkBoxBingLiNumber"));
        checkBoxBingLiNumber->setEnabled(false);
        checkBoxBingLiNumber->setChecked(true);

        horizontalLayout_9->addWidget(checkBoxBingLiNumber);

        checkBoxHyphen = new QCheckBox(groupBoxQuCai);
        checkBoxHyphen->setObjectName(QStringLiteral("checkBoxHyphen"));
        checkBoxHyphen->setChecked(true);

        horizontalLayout_9->addWidget(checkBoxHyphen);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(groupBoxQuCai);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        comboBoxNumberType = new QComboBox(groupBoxQuCai);
        comboBoxNumberType->setObjectName(QStringLiteral("comboBoxNumberType"));

        horizontalLayout_8->addWidget(comboBoxNumberType);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_11);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_10);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(groupBoxQuCai);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineEditQuCaiCodeDemo = new QLineEdit(groupBoxQuCai);
        lineEditQuCaiCodeDemo->setObjectName(QStringLiteral("lineEditQuCaiCodeDemo"));
        lineEditQuCaiCodeDemo->setEnabled(false);
        lineEditQuCaiCodeDemo->setStyleSheet(QLatin1String("QLineEdit:!enabled\n"
"{\n"
"color:black;\n"
"}"));

        horizontalLayout_10->addWidget(lineEditQuCaiCodeDemo);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_18);


        verticalLayout_6->addWidget(groupBoxQuCai);


        verticalLayout_7->addLayout(verticalLayout_6);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_19);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_21);

        groupBoxImport = new QGroupBox(coderole);
        groupBoxImport->setObjectName(QStringLiteral("groupBoxImport"));
        groupBoxImport->setMinimumSize(QSize(0, 100));
        verticalLayout_9 = new QVBoxLayout(groupBoxImport);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        lineEditSpilt = new QLineEdit(groupBoxImport);
        lineEditSpilt->setObjectName(QStringLiteral("lineEditSpilt"));

        horizontalLayout_13->addWidget(lineEditSpilt);

        radioButtonUseMaterial = new QRadioButton(groupBoxImport);
        radioButtonUseMaterial->setObjectName(QStringLiteral("radioButtonUseMaterial"));
        radioButtonUseMaterial->setChecked(true);

        horizontalLayout_13->addWidget(radioButtonUseMaterial);

        radioButtonUseSlice = new QRadioButton(groupBoxImport);
        radioButtonUseSlice->setObjectName(QStringLiteral("radioButtonUseSlice"));

        horizontalLayout_13->addWidget(radioButtonUseSlice);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_22);


        verticalLayout_9->addLayout(horizontalLayout_13);


        verticalLayout_7->addWidget(groupBoxImport);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_20);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        pushButtonOk = new QPushButton(coderole);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(150, 0));
        pushButtonOk->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout_11->addWidget(pushButtonOk);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);

        pushButtonCancel = new QPushButton(coderole);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(150, 0));
        pushButtonCancel->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout_11->addWidget(pushButtonCancel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);


        verticalLayout_7->addLayout(horizontalLayout_11);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_12->addLayout(verticalLayout_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        verticalLayout_8->addLayout(horizontalLayout_12);


        retranslateUi(coderole);

        QMetaObject::connectSlotsByName(coderole);
    } // setupUi

    void retranslateUi(QWidget *coderole)
    {
        coderole->setWindowTitle(QApplication::translate("coderole", "Form", 0));
        groupBoxBingLi->setTitle(QApplication::translate("coderole", "\347\227\205\347\220\206\345\217\267\347\274\226\347\240\201\350\247\204\345\210\231\357\274\232", 0));
        label->setText(QApplication::translate("coderole", "\345\211\215\347\274\200\357\274\232", 0));
        lineEditPrefix->setText(QApplication::translate("coderole", "F", 0));
        checkBoxType->setText(QApplication::translate("coderole", "\347\261\273\345\210\253", 0));
        groupBox_2->setTitle(QString());
        checkBoxYear->setText(QApplication::translate("coderole", "\345\271\264\344\273\275", 0));
        radioButtonTwo->setText(QApplication::translate("coderole", "2\344\275\215", 0));
        radioButtonFour->setText(QApplication::translate("coderole", "4\344\275\215", 0));
        checkBoxMonth->setText(QApplication::translate("coderole", "\346\234\210\344\273\275", 0));
        checkBoxDay->setText(QApplication::translate("coderole", "\346\227\245", 0));
        label_2->setText(QApplication::translate("coderole", "\351\227\264\351\232\224\347\254\246\357\274\232", 0));
        lineEditSpin->setText(QApplication::translate("coderole", "-", 0));
        label_3->setText(QApplication::translate("coderole", "\346\265\201\346\260\264\345\217\267\351\225\277\345\272\246\357\274\232", 0));
        label_4->setText(QApplication::translate("coderole", "\347\274\226\347\240\201\346\240\267\344\276\213\357\274\232", 0));
        groupBoxQuCai->setTitle(QApplication::translate("coderole", "\345\217\226\346\235\220\347\274\226\347\240\201\350\247\204\345\210\231\357\274\232", 0));
        checkBoxBingLiNumber->setText(QApplication::translate("coderole", "\347\227\205\347\220\206\345\217\267", 0));
        checkBoxHyphen->setText(QApplication::translate("coderole", "\350\277\236\345\255\227\347\254\246", 0));
        label_5->setText(QApplication::translate("coderole", "\346\265\201\346\260\264\345\217\267\347\261\273\345\236\213\357\274\232", 0));
        comboBoxNumberType->clear();
        comboBoxNumberType->insertItems(0, QStringList()
         << QApplication::translate("coderole", "0 \346\225\260\345\255\227", 0)
         << QApplication::translate("coderole", "1 \345\260\217\345\206\231\345\255\227\346\257\215", 0)
         << QApplication::translate("coderole", "2 \345\244\247\345\206\231\345\255\227\346\257\215", 0)
        );
        label_6->setText(QApplication::translate("coderole", "\347\274\226\347\240\201\346\240\267\344\276\213\357\274\232", 0));
        groupBoxImport->setTitle(QApplication::translate("coderole", "\350\207\252\345\212\250\345\257\274\345\205\245\350\256\276\347\275\256", 0));
        radioButtonUseMaterial->setText(QApplication::translate("coderole", "\347\224\250\344\272\216\345\217\226\346\235\220", 0));
        radioButtonUseSlice->setText(QApplication::translate("coderole", "\347\224\250\344\272\216\345\210\207\347\211\207", 0));
        pushButtonOk->setText(QApplication::translate("coderole", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("coderole", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class coderole: public Ui_coderole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEROLE_H
