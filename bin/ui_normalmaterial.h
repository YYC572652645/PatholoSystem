/********************************************************************************
** Form generated from reading UI file 'normalmaterial.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALMATERIAL_H
#define UI_NORMALMATERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_normalmaterial
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
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_9;
    QSpinBox *spinBoxMaterialNumber;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_3;
    QLineEdit *lineEditNumber;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_4;
    QLineEdit *lineEditSize;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEditWeight;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_6;
    QComboBox *comboBoxPeople;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QTextEdit *textEditRecord;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QComboBox *comboBoxRegPeople;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *normalmaterial)
    {
        if (normalmaterial->objectName().isEmpty())
            normalmaterial->setObjectName(QStringLiteral("normalmaterial"));
        normalmaterial->resize(670, 498);
        normalmaterial->setMinimumSize(QSize(670, 498));
        normalmaterial->setMaximumSize(QSize(670, 498));
        centralwidget = new QWidget(normalmaterial);
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
        lineEditBlNumber->setMinimumSize(QSize(250, 0));
        lineEditBlNumber->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(lineEditBlNumber);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        spinBoxMaterialNumber = new QSpinBox(groupBox);
        spinBoxMaterialNumber->setObjectName(QStringLiteral("spinBoxMaterialNumber"));
        spinBoxMaterialNumber->setMinimumSize(QSize(100, 0));
        spinBoxMaterialNumber->setMaximumSize(QSize(100, 16777215));
        spinBoxMaterialNumber->setMinimum(1);
        spinBoxMaterialNumber->setMaximum(1000000000);

        horizontalLayout->addWidget(spinBoxMaterialNumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setMinimumSize(QSize(150, 0));
        lineEditName->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(lineEditName);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditNumber = new QLineEdit(groupBox);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));
        lineEditNumber->setMinimumSize(QSize(150, 0));
        lineEditNumber->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(lineEditNumber);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEditSize = new QLineEdit(groupBox);
        lineEditSize->setObjectName(QStringLiteral("lineEditSize"));
        lineEditSize->setMinimumSize(QSize(100, 0));
        lineEditSize->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(lineEditSize);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEditWeight = new QLineEdit(groupBox);
        lineEditWeight->setObjectName(QStringLiteral("lineEditWeight"));
        lineEditWeight->setMinimumSize(QSize(250, 0));
        lineEditWeight->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_4->addWidget(lineEditWeight);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        comboBoxPeople = new QComboBox(groupBox);
        comboBoxPeople->setObjectName(QStringLiteral("comboBoxPeople"));
        comboBoxPeople->setMinimumSize(QSize(100, 0));
        comboBoxPeople->setMaximumSize(QSize(100, 16777215));
        comboBoxPeople->setEditable(true);

        horizontalLayout_4->addWidget(comboBoxPeople);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        textEditRecord = new QTextEdit(groupBox);
        textEditRecord->setObjectName(QStringLiteral("textEditRecord"));
        textEditRecord->setMaximumSize(QSize(16777215, 100));

        horizontalLayout_5->addWidget(textEditRecord);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        comboBoxRegPeople = new QComboBox(groupBox);
        comboBoxRegPeople->setObjectName(QStringLiteral("comboBoxRegPeople"));
        comboBoxRegPeople->setMinimumSize(QSize(100, 0));
        comboBoxRegPeople->setMaximumSize(QSize(100, 16777215));
        comboBoxRegPeople->setEditable(true);

        horizontalLayout_6->addWidget(comboBoxRegPeople);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_13);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonOk = new QPushButton(centralwidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(150, 0));
        pushButtonOk->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButtonOk);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonCancel = new QPushButton(centralwidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(150, 0));
        pushButtonCancel->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButtonCancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        normalmaterial->setCentralWidget(centralwidget);

        retranslateUi(normalmaterial);

        QMetaObject::connectSlotsByName(normalmaterial);
    } // setupUi

    void retranslateUi(QMainWindow *normalmaterial)
    {
        normalmaterial->setWindowTitle(QApplication::translate("normalmaterial", "MainWindow", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("normalmaterial", "  \347\227\205\347\220\206\345\217\267\357\274\232", 0));
        label_9->setText(QApplication::translate("normalmaterial", "\345\217\226\346\235\220\346\200\273\346\225\260\357\274\232", 0));
        label_2->setText(QApplication::translate("normalmaterial", "\346\240\207\346\234\254\345\220\215\347\247\260\357\274\232", 0));
        label_3->setText(QApplication::translate("normalmaterial", "\346\240\207\346\234\254\346\225\260\351\207\217\357\274\232", 0));
        label_4->setText(QApplication::translate("normalmaterial", "\346\240\207\346\234\254\345\244\247\345\260\217\357\274\232", 0));
        label_5->setText(QApplication::translate("normalmaterial", "\346\240\207\346\234\254\351\207\215\351\207\217\357\274\232", 0));
        label_6->setText(QApplication::translate("normalmaterial", "  \345\217\226\346\235\220\344\272\272\357\274\232", 0));
        label_7->setText(QApplication::translate("normalmaterial", "\346\243\200\346\237\245\350\256\260\345\275\225\357\274\232", 0));
        label_8->setText(QApplication::translate("normalmaterial", "  \350\256\260\345\275\225\344\272\272\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("normalmaterial", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("normalmaterial", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class normalmaterial: public Ui_normalmaterial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALMATERIAL_H
