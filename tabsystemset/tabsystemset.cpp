#include "tabsystemset.h"
#include "ui_tabsystemset.h"
#include "globaldef.h"
#include "config/qreadini.h"
#include <QDebug>

/***************************               构造函数                   ***********************/
TabSystemSet::TabSystemSet(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::tabsystemset)
  ,listWidget(NULL)
{
    ui->setupUi(this);

    this->initControl();
}

/***************************               析构函数                    ***********************/
TabSystemSet::~TabSystemSet()
{
    delete ui;
}

/***************************               初始化控件                   ***********************/
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
    listWidget->setFrameStyle(QFrame::NoFrame);

    listWidget->setFont(QFont("ZYSong", 12)); //设置字体大小

    //连接信号和槽
    connect(listWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(listWidgetClicked(QModelIndex)));

    listWidget->setObjectName("systemList");
}

/***************************               点击列表控件                 ***********************/
void TabSystemSet::listWidgetClicked(const QModelIndex &index)
{
    switch(index.row())
    {
    case 0:  showCentralwidget();              break;  //起始病理号设置
    case 1:  showTypeSet();                    break;  //标本类别设置
    case 2:  showPrintSet();                   break;  //打印参数设置
    case 3:  showCodeRule();                   break;  //编码规则设置
    case 4:  showImmuneTypeSet();              break;  //免疫组化染色类型设置
    case 5:  showImmuneIndexSet();             break;  //免疫组化染色指标设置
    case 6:  showSpecialTypeSet();             break;  //特染染色类型设置
    case 7:  showSpecialIndexSet();            break;  //特染染色指标设置
    case 8:  showUserSet();                    break;  //用户设置
    }
}

/***************************               确定按钮                    ***********************/
void TabSystemSet::on_pushButtonOk_clicked()
{
    INICONFIG->writeIni(QString::number(ui->spinBox->value()));
    SYSTEMDATA->codeBeginUpdateData("PCodeBeginSn", QString::number(ui->spinBox->value()));  //更新数据库数据

    ui->centralwidget->hide();                                                                //将该界面隐藏
}

/***************************               取消按钮                    ***********************/
void TabSystemSet::on_pushButtonCancel_clicked()
{
    ui->centralwidget->hide();
}

/***************************               显示中心窗口                 ***********************/
void TabSystemSet::showCentralwidget()
{
    SYSTEMDATA->codeBeginSelectData();
    QMap<QString, QString> mapData = SYSTEMDATA->getCodeBeginSnSetInfo();

    ui->spinBox->setValue(mapData.value("PCodeBeginSn").toInt());

    SETCENTRALWIDGET(ui->centralwidget);

    ui->centralwidget->show();
}

/***************************               显示标本类别设置              ***********************/
void TabSystemSet::showTypeSet()
{
    SETCENTRALWIDGET(&typeSet);
    typeSet.showDialog();
}

/***************************               显示编码规则设置              ***********************/
void TabSystemSet::showCodeRule()
{
    SETCENTRALWIDGET(&codeRole);
    codeRole.show();
}

/***************************               打印设置                     ***********************/
void TabSystemSet::showPrintSet()
{
    SETCENTRALWIDGET(&printSet);
    printSet.show();
}

/***************************               用户设置                     ***********************/
void TabSystemSet::showUserSet()
{
    SETCENTRALWIDGET(&userSet);
    userSet.show();
}

/***************************               免疫组化类型设置               ***********************/
void TabSystemSet::showImmuneTypeSet()
{
    SETCENTRALWIDGET(&immuneTypeSet);
    immuneTypeSet.show();
}

/***************************               免疫组化指标设置               ***********************/
void TabSystemSet::showImmuneIndexSet()
{
    SETCENTRALWIDGET(&immuneIndexSet);
    immuneIndexSet.show();
}

/***************************               特染组化类型设置               ***********************/
void TabSystemSet::showSpecialTypeSet()
{
    SETCENTRALWIDGET(&speciaTypeSet);
    speciaTypeSet.show();
}

/***************************               特染组化指标设置               ***********************/
void TabSystemSet::showSpecialIndexSet()
{
    SETCENTRALWIDGET(&speciaIndexSet);
    speciaIndexSet.show();
}
