/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userwidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditUserName;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditPassWord;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditPassWordMore;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditRemark;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBoxAdminster;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxReg;
    QCheckBox *checkBoxMateral;
    QCheckBox *checkBoxNormal;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBoxImmune;
    QCheckBox *checkBoxSpecial;
    QCheckBox *checkBoxSelect;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *userwidget)
    {
        if (userwidget->objectName().isEmpty())
            userwidget->setObjectName(QStringLiteral("userwidget"));
        userwidget->resize(475, 534);
        userwidget->setMinimumSize(QSize(475, 534));
        userwidget->setMaximumSize(QSize(475, 534));
        verticalLayout_7 = new QVBoxLayout(userwidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox = new QGroupBox(userwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditUserName = new QLineEdit(groupBox);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));

        horizontalLayout->addWidget(lineEditUserName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditPassWord = new QLineEdit(groupBox);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEditPassWord);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditPassWordMore = new QLineEdit(groupBox);
        lineEditPassWordMore->setObjectName(QStringLiteral("lineEditPassWordMore"));
        lineEditPassWordMore->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEditPassWordMore);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEditRemark = new QLineEdit(groupBox);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));

        horizontalLayout_5->addWidget(lineEditRemark);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_5);

        checkBoxAdminster = new QCheckBox(groupBox);
        checkBoxAdminster->setObjectName(QStringLiteral("checkBoxAdminster"));

        verticalLayout_2->addWidget(checkBoxAdminster);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_6->addWidget(groupBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_6);

        groupBox_2 = new QGroupBox(userwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxReg = new QCheckBox(groupBox_2);
        checkBoxReg->setObjectName(QStringLiteral("checkBoxReg"));

        horizontalLayout_2->addWidget(checkBoxReg);

        checkBoxMateral = new QCheckBox(groupBox_2);
        checkBoxMateral->setObjectName(QStringLiteral("checkBoxMateral"));

        horizontalLayout_2->addWidget(checkBoxMateral);

        checkBoxNormal = new QCheckBox(groupBox_2);
        checkBoxNormal->setObjectName(QStringLiteral("checkBoxNormal"));

        horizontalLayout_2->addWidget(checkBoxNormal);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        checkBoxImmune = new QCheckBox(groupBox_2);
        checkBoxImmune->setObjectName(QStringLiteral("checkBoxImmune"));

        horizontalLayout_6->addWidget(checkBoxImmune);

        checkBoxSpecial = new QCheckBox(groupBox_2);
        checkBoxSpecial->setObjectName(QStringLiteral("checkBoxSpecial"));

        horizontalLayout_6->addWidget(checkBoxSpecial);

        checkBoxSelect = new QCheckBox(groupBox_2);
        checkBoxSelect->setObjectName(QStringLiteral("checkBoxSelect"));

        horizontalLayout_6->addWidget(checkBoxSelect);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_6->addWidget(groupBox_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonOk = new QPushButton(userwidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_7->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(userwidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_7->addWidget(pushButtonCancel);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_7->addLayout(verticalLayout_6);


        retranslateUi(userwidget);

        QMetaObject::connectSlotsByName(userwidget);
    } // setupUi

    void retranslateUi(QWidget *userwidget)
    {
        userwidget->setWindowTitle(QApplication::translate("userwidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("userwidget", "\344\270\252\344\272\272\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("userwidget", "\347\231\273\345\275\225\345\220\215\347\247\260\357\274\232", 0));
        label_3->setText(QApplication::translate("userwidget", "\347\231\273\345\275\225\345\257\206\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("userwidget", "\345\257\206\347\240\201\347\241\256\350\256\244\357\274\232", 0));
        label_5->setText(QApplication::translate("userwidget", "    \345\244\207\346\263\250\357\274\232", 0));
        checkBoxAdminster->setText(QApplication::translate("userwidget", "\347\256\241\347\220\206\345\221\230\350\272\253\344\273\275", 0));
        groupBox_2->setTitle(QApplication::translate("userwidget", "\346\223\215\344\275\234\346\235\203\351\231\220", 0));
        checkBoxReg->setText(QApplication::translate("userwidget", "\347\231\273\350\256\260", 0));
        checkBoxMateral->setText(QApplication::translate("userwidget", "\345\217\226\346\235\220", 0));
        checkBoxNormal->setText(QApplication::translate("userwidget", "\345\270\270\350\247\204\345\210\207\347\211\207", 0));
        checkBoxImmune->setText(QApplication::translate("userwidget", "\345\205\215\347\226\253\347\273\204\345\214\226", 0));
        checkBoxSpecial->setText(QApplication::translate("userwidget", "\347\211\271\346\256\212\346\237\223\350\211\262", 0));
        checkBoxSelect->setText(QApplication::translate("userwidget", "\346\237\245\350\257\242", 0));
        pushButtonOk->setText(QApplication::translate("userwidget", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("userwidget", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class userwidget: public Ui_userwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
