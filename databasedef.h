#ifndef DATABASEDEF_H
#define DATABASEDEF_H

/***************************************************************
   功能:定义数据表的字段顺序

   创建人:殷宇辰

   创建时间:2017-6-20
**************************************************************/

namespace DAtABASEDEF
{

//用户数据库表
enum USER
{
    USERID,
    USERNO,
    USERNAME,
    PASSWORD,
    ISADMINISTRATOR,
    UNUSED,
    REMARK,
};

//登记数据库表
enum REG
{
    REGID,
    REGPCODE,
    REGSN,
    REGPRINTQUANTITY,
    REGPRINTED,
    REGCREATETIME,
    REGUSERID,
};

//起始病理号设置数据库表
enum CODEBEGINSET
{
    CODEBEGINNAME,
    CODEBEGINVALUE,
};

//标本类别设置
enum CODETYPESET
{
    CODETYPEID,
    CODETYPEABBR,
    CODETYPENAME,
};


}




#endif // DATABASEDEF_H
