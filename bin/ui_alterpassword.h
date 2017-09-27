/********************************************************************************
** Form generated from reading UI file 'alterpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTERPASSWORD_H
#define UI_ALTERPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_alterpassword
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditOldPsd;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditNewPsd;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditPsdMore;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QMainWindow *alterpassword)
    {
        if (alterpassword->objectName().isEmpty())
            alterpassword->setObjectName(QStringLiteral("alterpassword"));
        alterpassword->resize(400, 300);
        alterpassword->setMinimumSize(QSize(400, 300));
        alterpassword->setMaximumSize(QSize(400, 300));
        centralWidget = new QWidget(alterpassword);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditOldPsd = new QLineEdit(centralWidget);
        lineEditOldPsd->setObjectName(QStringLiteral("lineEditOldPsd"));
        lineEditOldPsd->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(lineEditOldPsd);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditNewPsd = new QLineEdit(centralWidget);
        lineEditNewPsd->setObjectName(QStringLiteral("lineEditNewPsd"));
        lineEditNewPsd->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditNewPsd);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditPsdMore = new QLineEdit(centralWidget);
        lineEditPsdMore->setObjectName(QStringLiteral("lineEditPsdMore"));
        lineEditPsdMore->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEditPsdMore);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButtonOk = new QPushButton(centralWidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_4->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(centralWidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_4->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        alterpassword->setCentralWidget(centralWidget);

        retranslateUi(alterpassword);

        QMetaObject::connectSlotsByName(alterpassword);
    } // setupUi

    void retranslateUi(QMainWindow *alterpassword)
    {
        alterpassword->setWindowTitle(QApplication::translate("alterpassword", "MainWindow", 0));
        label->setText(QApplication::translate("alterpassword", "  \346\227\247\345\257\206\347\240\201\357\274\232", 0));
        label_2->setText(QApplication::translate("alterpassword", "  \346\226\260\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("alterpassword", "\345\257\206\347\240\201\347\241\256\350\256\244\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("alterpassword", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("alterpassword", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class alterpassword: public Ui_alterpassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERPASSWORD_H
