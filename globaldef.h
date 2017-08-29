#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP
#include <QString>

#define  DATA(str)   new QTableWidgetItem(str)

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

enum TYPE
{
    ALLDATA,
    BLDATA,
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

//导出Excel
const static QString PCODE         = "序号";
const static QString SN            = "病理号";
const static QString PRINTQUANTITY = "打印数量";
const static QString PRINTED       = "已打印";
const static QString CREATETIME    = "创建日期";


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


namespace GLOBALDEF
{
const static int     ERROR        = -1;                           //数据库查询失败
const static QString UNUSED       = "1";                          //不用使用密码登录
const static QString PRINTFLAGE   = "1";                          //已经打印
const static QString SUCCESSIMAGE = ":/image/image/ok.png";       //成功图片
const static QString FAILIMAGE    = ":/image/image/fail.png";     //失败图片
const static QString PRINTICON    = ":/image/image/print.jpg";    //打印图片
const static QString REFRESHICON  = ":/image/image/refresh.png";  //刷新图片
const static QString DELETEICON   = ":/image/image/critical.png"; //删除图片
const static QString SYSTEMINFO   = "系统提示";                    //系统提示
const static int     REFRESHTIME  = 3500;                         //刷新时间


enum DATATYPE
{
    TYPEINSERT,
    TYPEUPDATE,
};


}




#endif // GLOBALDEF_HPP
