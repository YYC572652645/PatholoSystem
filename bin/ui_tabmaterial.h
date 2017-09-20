/********************************************************************************
** Form generated from reading UI file 'tabmaterial.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABMATERIAL_H
#define UI_TABMATERIAL_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabmaterial
{
public:
    QAction *actionNormalMaterial;
    QAction *actionAddBaoMai;
    QAction *actionPrintLabel;
    QAction *actionPrintMoreLabel;
    QAction *actionDeleteInfo;
    QAction *actionClearInfo;
    QAction *actionExtendExcel;
    QAction *actionPrintTemplate;
    QAction *actionAddBingLiNumber;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *widgetTable;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNumber;
    QPushButton *pushButtonFind;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget;
    QWidget *widgetInfo;
    QToolBar *toolBar;

    void setupUi(QMainWindow *tabmaterial)
    {
        if (tabmaterial->objectName().isEmpty())
            tabmaterial->setObjectName(QStringLiteral("tabmaterial"));
        tabmaterial->resize(952, 672);
        actionNormalMaterial = new QAction(tabmaterial);
        actionNormalMaterial->setObjectName(QStringLiteral("actionNormalMaterial"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNormalMaterial->setIcon(icon);
        actionAddBaoMai = new QAction(tabmaterial);
        actionAddBaoMai->setObjectName(QStringLiteral("actionAddBaoMai"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/addto.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddBaoMai->setIcon(icon1);
        actionPrintLabel = new QAction(tabmaterial);
        actionPrintLabel->setObjectName(QStringLiteral("actionPrintLabel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/print.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintLabel->setIcon(icon2);
        actionPrintMoreLabel = new QAction(tabmaterial);
        actionPrintMoreLabel->setObjectName(QStringLiteral("actionPrintMoreLabel"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/printmore.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintMoreLabel->setIcon(icon3);
        actionDeleteInfo = new QAction(tabmaterial);
        actionDeleteInfo->setObjectName(QStringLiteral("actionDeleteInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/critical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteInfo->setIcon(icon4);
        actionClearInfo = new QAction(tabmaterial);
        actionClearInfo->setObjectName(QStringLiteral("actionClearInfo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/image/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearInfo->setIcon(icon5);
        actionExtendExcel = new QAction(tabmaterial);
        actionExtendExcel->setObjectName(QStringLiteral("actionExtendExcel"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/image/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExtendExcel->setIcon(icon6);
        actionPrintTemplate = new QAction(tabmaterial);
        actionPrintTemplate->setObjectName(QStringLiteral("actionPrintTemplate"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/image/tempalte.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintTemplate->setIcon(icon7);
        actionAddBingLiNumber = new QAction(tabmaterial);
        actionAddBingLiNumber->setObjectName(QStringLiteral("actionAddBingLiNumber"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/image/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddBingLiNumber->setIcon(icon8);
        centralwidget = new QWidget(tabmaterial);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        widgetTable = new QWidget(splitter);
        widgetTable->setObjectName(QStringLiteral("widgetTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetTable->sizePolicy().hasHeightForWidth());
        widgetTable->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(widgetTable);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widgetTable);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditNumber = new QLineEdit(widgetTable);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));

        horizontalLayout->addWidget(lineEditNumber);

        pushButtonFind = new QPushButton(widgetTable);
        pushButtonFind->setObjectName(QStringLiteral("pushButtonFind"));
        pushButtonFind->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/image/image/serch.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonFind->setIcon(icon9);

        horizontalLayout->addWidget(pushButtonFind);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(widgetTable);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_2->addWidget(treeWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter->addWidget(widgetTable);
        widgetInfo = new QWidget(splitter);
        widgetInfo->setObjectName(QStringLiteral("widgetInfo"));
        splitter->addWidget(widgetInfo);

        verticalLayout->addWidget(splitter);

        tabmaterial->setCentralWidget(centralwidget);
        toolBar = new QToolBar(tabmaterial);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabmaterial->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionNormalMaterial);
        toolBar->addAction(actionAddBaoMai);
        toolBar->addAction(actionAddBingLiNumber);
        toolBar->addSeparator();
        toolBar->addAction(actionPrintLabel);
        toolBar->addAction(actionPrintMoreLabel);
        toolBar->addSeparator();
        toolBar->addAction(actionDeleteInfo);
        toolBar->addAction(actionClearInfo);
        toolBar->addSeparator();
        toolBar->addAction(actionExtendExcel);
        toolBar->addAction(actionPrintTemplate);
        toolBar->addSeparator();

        retranslateUi(tabmaterial);

        QMetaObject::connectSlotsByName(tabmaterial);
    } // setupUi

    void retranslateUi(QMainWindow *tabmaterial)
    {
        tabmaterial->setWindowTitle(QApplication::translate("tabmaterial", "MainWindow", 0));
        actionNormalMaterial->setText(QApplication::translate("tabmaterial", "\345\270\270\350\247\204\345\217\226\346\235\220", 0));
#ifndef QT_NO_TOOLTIP
        actionNormalMaterial->setToolTip(QApplication::translate("tabmaterial", "\345\270\270\350\247\204\345\217\226\346\235\220", 0));
#endif // QT_NO_TOOLTIP
        actionAddBaoMai->setText(QApplication::translate("tabmaterial", "\346\267\273\345\212\240\345\214\205\345\237\213", 0));
#ifndef QT_NO_TOOLTIP
        actionAddBaoMai->setToolTip(QApplication::translate("tabmaterial", "\346\267\273\345\212\240\345\214\205\345\237\213", 0));
#endif // QT_NO_TOOLTIP
        actionPrintLabel->setText(QApplication::translate("tabmaterial", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintLabel->setToolTip(QApplication::translate("tabmaterial", "\346\211\223\345\215\260\346\240\207\347\255\276", 0));
#endif // QT_NO_TOOLTIP
        actionPrintMoreLabel->setText(QApplication::translate("tabmaterial", "\346\211\271\351\207\217\346\211\223\345\215\260", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintMoreLabel->setToolTip(QApplication::translate("tabmaterial", "\346\211\271\351\207\217\346\211\223\345\215\260", 0));
#endif // QT_NO_TOOLTIP
        actionDeleteInfo->setText(QApplication::translate("tabmaterial", "\345\210\240\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionDeleteInfo->setToolTip(QApplication::translate("tabmaterial", "\345\210\240\351\231\244", 0));
#endif // QT_NO_TOOLTIP
        actionClearInfo->setText(QApplication::translate("tabmaterial", "\346\270\205\347\251\272", 0));
#ifndef QT_NO_TOOLTIP
        actionClearInfo->setToolTip(QApplication::translate("tabmaterial", "\346\270\205\347\251\272", 0));
#endif // QT_NO_TOOLTIP
        actionExtendExcel->setText(QApplication::translate("tabmaterial", "\345\257\274\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        actionExtendExcel->setToolTip(QApplication::translate("tabmaterial", "\345\257\274\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        actionPrintTemplate->setText(QApplication::translate("tabmaterial", "\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintTemplate->setToolTip(QApplication::translate("tabmaterial", "\346\211\223\345\215\260\346\250\241\346\235\277", 0));
#endif // QT_NO_TOOLTIP
        actionAddBingLiNumber->setText(QApplication::translate("tabmaterial", "\346\267\273\345\212\240\347\227\205\347\220\206\345\217\267", 0));
#ifndef QT_NO_TOOLTIP
        actionAddBingLiNumber->setToolTip(QApplication::translate("tabmaterial", "\346\267\273\345\212\240\347\227\205\347\220\206\345\217\267", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("tabmaterial", "\347\274\226\345\217\267\357\274\232", 0));
        pushButtonFind->setText(QApplication::translate("tabmaterial", "    \346\237\245\346\211\276", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(7, QApplication::translate("tabmaterial", "\345\217\226\346\235\220\344\272\272", 0));
        ___qtreewidgetitem->setText(6, QApplication::translate("tabmaterial", "\345\217\226\346\235\220\346\227\245\346\234\237", 0));
        ___qtreewidgetitem->setText(5, QApplication::translate("tabmaterial", "\345\267\262\345\217\226\346\235\220", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("tabmaterial", "\346\211\223\345\215\260\346\227\266\351\227\264", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("tabmaterial", "\345\267\262\346\211\223\345\215\260", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("tabmaterial", "\347\273\204\347\273\207\345\220\215\347\247\260", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("tabmaterial", "\345\272\217\345\217\267", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("tabmaterial", "\347\274\226\345\217\267", 0));
        toolBar->setWindowTitle(QApplication::translate("tabmaterial", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class tabmaterial: public Ui_tabmaterial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABMATERIAL_H
