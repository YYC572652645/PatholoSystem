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

    //连接信号和槽
    connect(listWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(listWidgetClicked(QModelIndex)));
}

void TabSystemSet::listWidgetClicked(const QModelIndex &index)
{
    switch(index.row())
    {
    case 0: SETCENTRALWIDGET(ui->centralwidget); ui->centralwidget->show(); break;  //起始病理号设置
    case 1: SETCENTRALWIDGET(&typeSet) typeSet.showDialog();                break;  //标本类别设置
    case 2:                                                                 break;  //打印参数设置
    case 3: SETCENTRALWIDGET(&codeRole);                                    break;  //编码规则设置
    case 4:                                                                 break;  //免疫组化染色类型设置
    case 5:                                                                 break;  //免疫组化染色指标设置
    case 6:                                                                 break;  //特染染色类型设置
    case 7:                                                                 break;  //特染染色指标设置
    case 8:                                                                 break;  //用户设置
    }

}

void TabSystemSet::on_pushButtonOk_clicked()
{
    SYSTEMDATA->codeBeginUpdateData("PCodeBeginSn", QString::number(ui->spinBox->value()));  //更新数据库数据

    ui->centralwidget->hide();                                                                //将该界面隐藏
}

void TabSystemSet::on_pushButtonCancel_clicked()
{
    ui->centralwidget->hide();
}
