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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_typesetdialog
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditTypeAbbreviation;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditTypeName;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *typesetdialog)
    {
        if (typesetdialog->objectName().isEmpty())
            typesetdialog->setObjectName(QStringLiteral("typesetdialog"));
        typesetdialog->resize(350, 231);
        typesetdialog->setMinimumSize(QSize(350, 231));
        typesetdialog->setMaximumSize(QSize(350, 231));
        groupBox = new QGroupBox(typesetdialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 301, 171));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 268, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditTypeAbbreviation = new QLineEdit(layoutWidget);
        lineEditTypeAbbreviation->setObjectName(QStringLiteral("lineEditTypeAbbreviation"));
        lineEditTypeAbbreviation->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(lineEditTypeAbbreviation);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 110, 268, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditTypeName = new QLineEdit(layoutWidget1);
        lineEditTypeName->setObjectName(QStringLiteral("lineEditTypeName"));
        lineEditTypeName->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(lineEditTypeName);

        pushButtonOk = new QPushButton(typesetdialog);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(80, 200, 80, 20));
        pushButtonCancel = new QPushButton(typesetdialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(210, 200, 80, 20));

        retranslateUi(typesetdialog);

        QMetaObject::connectSlotsByName(typesetdialog);
    } // setupUi

    void retranslateUi(QDialog *typesetdialog)
    {
        typesetdialog->setWindowTitle(QApplication::translate("typesetdialog", "Dialog", 0));
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
