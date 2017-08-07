#include "tabsystemset.h"
#include "ui_tabsystemset.h"
#include "globaldef.h"
#include <QDebug>

TabSystemSet::TabSystemSet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabsystemset)
{
    ui->setupUi(this);

    this->initControl();
}

TabSystemSet::~TabSystemSet()
{
    delete ui;
}

void TabSystemSet::initControl()
{

    ui->centralwidget->hide();

    listWidget = new QListWidget(this);
    ui->toolBar->addWidget(listWidget);

    listWidget->addItem(new QListWidgetItem("起始病理号设置"));
    listWidget->addItem(new QListWidgetItem("标本类别设置"));
    listWidget->addItem(new QListWidgetItem("打印参数设置"));
    listWidget->addItem(new QListWidgetItem("编码规则设置"));
    listWidget->addItem(new QListWidgetItem("免疫组化染色类型设置"));
    listWidget->addItem(new QListWidgetItem("免疫组化染色指标设置"));
    listWidget->addItem(new QListWidgetItem("特染染色类型设置"));
    listWidget->addItem(new QListWidgetItem("特染染色指标设置"));
    listWidget->addItem(new QListWidgetItem("用户设置"));

    listWidget->setGridSize(QSize(80, 30));  //设置显示间隔

    listWidget->setFont(QFont("ZYSong", 12)); //设置字体大小

    listWidget->setStyleSheet("QListWidget{background-color: rgb(134,183,200);}");

    //连接信号和槽
    connect(listWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(listWidgetClicked(QModelIndex)));
}

void TabSystemSet::listWidgetClicked(const QModelIndex &index)
{
    switch(index.row())
    {
    case 0: SETCENTRALWIDGET(ui->centralwidget); ui->centralwidget->show(); break;
    case 1: SETCENTRALWIDGET(&typeSet);break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    case 8: break;
    }

}

void TabSystemSet::on_pushButtonOk_clicked()
{
    ui->centralwidget->hide();
}

void TabSystemSet::on_pushButtonCancel_clicked()
{
    ui->centralwidget->hide();
}
