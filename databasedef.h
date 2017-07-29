#ifndef DATABASEDEF_H
#define DATABASEDEF_H

/***************************************************************
   功能:定义数据表的字段顺序

   创建人:殷宇辰

   创建时间:2017-6-20
**************************************************************/

namespace DAtABASEDEF
{

    //user数据库表
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





}




#endif // DATABASEDEF_H
