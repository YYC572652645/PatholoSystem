#ifndef GLOBALDEF_H
#define GLOBALDEF_H
#include <QString>
#include <QPoint>
#include <QFont>
#include <QSize>


/*******************   字体       *******************/
const static QString FAMILY    = "Family";
const static QString POINTSIZE = "Point Size";
const static QString BOLD      = "Bold";
const static QString ITALIC    = "Italic";
const static QString UNDERLINE = "Underline";
const static QString STRIKEOUT = "Strikeout";
const static QString KERNING   = "Kerning";

/*******************   大小       *******************/
const static QString WIDTH   = "Width";
const static QString HEIGHT   = "Height";

const static int    INVALIDVALUE = -1;               //无用值
const static int    PAINTDATA =  32;                 //绘图补偿值
const static QPoint STARTPOINT = QPoint(40, 60);     //绘图开始点
const static QFont  STARTFONT = QFont("宋体", 16);    //开始字体
const static QSize  STARTSIZE = QSize(100, 100);     //开始大小


const static QString  labelType   = "labelType";
const static QString  labelText   = "labelText";
const static QString  fontType    = "fontType";
const static QString  fontSize    = "fontSize";
const static QString  fontColor   = "fontColor";
const static QString  labelWidth  = "labelWidth";
const static QString  labelHeight = "labelHeight";
const static QString  gemoryX     = "gemoryX";
const static QString  gemoryY     = "gemoryY";

#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
    {                       \
        delete pointer;     \
    }                       \
    pointer = NULL;         \
}

/*******************   label类型   *******************/
enum CONTROLTYPE
{
    TEXTTYPE,
    BINGLITYPE,
    QRCODETYPE,
    TYPEMAX,
};

enum PRINTDATA
{
    TEMPLATENAME,
    TEMPLATETEXT,
};

#endif // GLOBALDEF_H
