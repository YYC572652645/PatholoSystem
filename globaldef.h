#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP
#include <QString>
#include <windows.h>


#define  DATA(str)          new QTableWidgetItem(str)
#define  TREEDATA(widget)   new QTreeWidgetItem(widget)
#define  TREEITEM()         new QTreeWidgetItem()


#define SETCENTRALWIDGET(widget)               \
{                                              \
    if(this->centralWidget())                  \
{                                          \
    this->centralWidget()->setParent(NULL);\
    }                                          \
    this->setCentralWidget(widget);            \
    }

#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
{                       \
    delete pointer;     \
    }                       \
    pointer = NULL;         \
    }

#define LOADQSS(qssFile)                      \
{                                             \
    QString strQss;                           \
    QFile file(qssFile);                      \
    file.open(QFile::ReadOnly);               \
    if(file.isOpen())                         \
{                                         \
    strQss=QLatin1String(file.readAll()); \
    qApp->setStyleSheet(strQss);          \
    file.close();                         \
    }                                         \
    }

enum TYPE
{
    ALLDATA,
    BLDATA,
    CHILDDATA,
};

enum MATRIALCOLUMN
{
    NUMBERING,
    SERIALNUMBER,
    ORGANIZATIONNAME,
    ISPRINTED,
    PRINTTIME,
    ISMATERIAL,
    MATERIALTIME,
    MATERIALPEOPLE,
    MATRIALCOLUMNMAX,
};

enum NUMBERFIGERTYPE
{
    CAPITAL,  //大写
    LOWER,    //小写
};

//界面
enum WIDGETTYPE
{
    FIRSTWIDGET,
    SECONDWIDGET,
    THIRDWIDGET,
    FOURTHWIDGET,
    FIVETHWIDGET,
    SIXTHWIDGET,
    SEVENTHWIDGET,
};

typedef struct RegisterInfo
{
    QString id;           //id号
    QString pCode;        //序号
    QString sn;           //病理号
    QString printQuantity;//打印数量
    QString printed;      //是否打印
    QString createTime;   //创建时间
}RegisterInfo;

//导出登记信息Excel
const static QString PCODE         = "序号";
const static QString SN            = "病理号";
const static QString PRINTQUANTITY = "打印数量";
const static QString PRINTED       = "已打印";
const static QString CREATETIME    = "创建日期";

//导出取材信息Excel
namespace MATERALINFO
{
const static QString SN            = "编号";
const static QString PCODE         = "序号";
const static QString TISSUE        = "组织名称";
const static QString PRINTED       = "已打印";
const static QString PRINTTIME     = "打印时间";
const static QString SAMPLED       = "已取材";
const static QString SAMPLEDTIME   = "取材日期";
const static QString SAMPLEDPEOPLE = "取材人";
}

//导出取材统计信息Excel
namespace STATISTICSINFO
{
const static QString DATE           = "日期";
const static QString MATERIALTOTAL  = "取材总例数";
const static QString EMBEDDINGTOTAL = "包埋总数";
const static QString NORMALMTLTOTAL = "常规取材例数";
const static QString NORMALEDDTOTAL = "常规包埋数";
const static QString FROZENMTLTOTAL = "冰冻取材例数";
const static QString FROZENMEDDOTAL = "冰冻包埋数";
}


//Map键值
const static QString CUSTOMPREFIX  = "CustomPrefix";
const static QString USERPREFIX    = "UsePrefix"   ;
const static QString USEYEAR       = "UseYear"     ;
const static QString YEARTYPE      = "YearType"    ;
const static QString USEMONTH      = "UseMonth"    ;
const static QString USEDAY        = "UseDay"      ;
const static QString SPIN          = "Spin"        ;
const static QString SNLENGTH      = "SnLength"    ;
const static QString BLNUMBER      = "BLNumber"    ;
const static QString HYPHEN        = "Hyphen"      ;
const static QString NUMBERTYPE    = "NumberType"  ;
const static QString PCODEBEGINSN  = "PCodeBeginSn";
const static QString ITEMSPLIT     = "ItemSplit"   ;


namespace GLOBALDEF
{
const static int     DATAERROR        = -1;                           //数据库查询失败
const static QString UNUSED           = "1";                          //不用使用密码登录
const static QString PRINTFLAGE       = "1";                          //已经打印
const static QString SUCCESSIMAGE     = ":/image/image/ok.png";       //成功图片
const static QString FAILIMAGE        = ":/image/image/fail.png";     //失败图片
const static QString PRINTICON        = ":/image/image/print.jpg";    //打印图片
const static QString REFRESHICON      = ":/image/image/refresh.png";  //刷新图片
const static QString DELETEICON       = ":/image/image/critical.png"; //删除图片
const static QString EXCELICON        = ":/image/image/excel.png";    //Excel图片
const static QString SYSTEMINFO       = "系统提示";                    //系统提示
const static int     REFRESHTIME      = 3500;                         //刷新时间
const static BYTE    SHOWALL          = 0XFF;                         //显示所有窗口
const static BYTE    SHOWREG          = 0X01;                         //显示登记窗口
const static BYTE    SHOWMATERIAL     = 0X02;                         //显示取材窗口
const static BYTE    SHOWNORMALSLICE  = 0X04;                         //显示常规切片窗口
const static BYTE    SHOWIMMUNESLICE  = 0X08;                         //显示免疫组化切片窗口
const static BYTE    SHOWSPECIALSLICE = 0X10;                         //显示特染切片窗口
const static BYTE    SHOWSATISTICS    = 0X20;                         //显示统计数据窗口
const static BYTE    SHOWSYSTEMSET    = 0X40;                         //显示系统设置


//数据操作
enum DATATYPE
{
    TYPEINSERT,
    TYPEUPDATE,
};

//导出类型
enum EXTENDTYPE
{
    REGTYPE,
    MATERIALTYPE,
    STATISTICSTYPE,
};

//系统设置的类型设置和指标设置
enum IMMUNESPECIAL
{
    FIRSTTYPE,
    SECONDTYPE,
};

}




#endif // GLOBALDEF_HPP
