#include "qreadini.h"
#include <QDebug>
#include "globaldef.h"
QReadIni*QReadIni::instance = NULL;

QReadIni *QReadIni::getInstance()
{
    if(instance == NULL)
    {
        instance = new QReadIni();
    }
    return instance;
}

QReadIni::QReadIni()
{
    this->readIni();
}

QString QReadIni::getStartNumber() const
{
    return startNumber;
}

LoginConfig QReadIni::getLoginConfig() const
{
    return loginConfig;
}

void QReadIni::readIni()
{
    QSettings * configIniRead  = new QSettings("config.ini",QSettings::IniFormat);          //初始化读取Ini文件对象
    dataConfig.ip              = configIniRead->value("conn/ip").toString();                //IP地址
    dataConfig.port            = configIniRead->value("conn/port").toString();              //端口
    dataConfig.dataBaseVersion = configIniRead->value("conn/databaseversion").toString();   //数据库版本
    dataConfig.dataBaseName    = configIniRead->value("conn/databasename").toString();      //数据库名称
    dataConfig.userName        = configIniRead->value("conn/username").toString();          //用户名
    dataConfig.passWord        = configIniRead->value("conn/password").toString();          //密码
    loginConfig.userName       = configIniRead->value("login/username").toString();         //登录用户名
    loginConfig.passWord       = configIniRead->value("login/password").toString();         //登录密码
    startNumber                = configIniRead->value("init/startNumber").toString();       //开始编号
    SAFEDELETE(configIniRead);
}

/****************写入配置文件***************/
void QReadIni::writeIni(QString userName, QString passWord)
{
    QSettings * configIniWrite=new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    configIniWrite->setValue("login/username", userName);                       //用户名
    configIniWrite->setValue("login/password", passWord);                       //密码
    SAFEDELETE(configIniWrite);
}

void QReadIni::writeIni(QString startNumber)
{
    QSettings * configIniWrite=new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    configIniWrite->setValue("init/startNumber", startNumber);                  //用户名
    this->startNumber = startNumber;
    SAFEDELETE(configIniWrite);
}

const DataConfig &QReadIni::getDataConfig()
{
    return dataConfig;
}


