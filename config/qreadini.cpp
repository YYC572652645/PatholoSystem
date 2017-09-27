#include "qreadini.h"
#include <QDebug>
#include "globaldef.h"
#include <QTextCodec>
QReadIni *QReadIni::instance = NULL;

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

void QReadIni::setTemplateList(const QList<QString> &value)
{
    templateList = value;
}

QList<QString> QReadIni::getTemplateList() const
{
    return templateList;
}

QString QReadIni::getRecentNumber() const
{
    return recentNumber;
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
    templateList.clear();
    configIniRead->setIniCodec(QTextCodec::codecForName("GB2312"));
    dataConfig.ip              = configIniRead->value("conn/ip").toString();                //IP地址
    dataConfig.port            = configIniRead->value("conn/port").toString();              //端口
    dataConfig.dataBaseVersion = configIniRead->value("conn/databaseversion").toString();   //数据库版本
    dataConfig.dataBaseName    = configIniRead->value("conn/databasename").toString();      //数据库名称
    dataConfig.userName        = configIniRead->value("conn/username").toString();          //用户名
    dataConfig.passWord        = configIniRead->value("conn/password").toString();          //密码
    loginConfig.userName       = configIniRead->value("login/username").toString();         //登录用户名
    loginConfig.passWord       = configIniRead->value("login/password").toString();         //登录密码
    startNumber                = configIniRead->value("init/startNumber").toString();       //开始编号
    recentNumber               = configIniRead->value("init/recentNumber").toString();      //最近编号
    startNumber                = configIniRead->value("init/startNumber").toString();       //开始编号
    recentNumber               = configIniRead->value("init/recentNumber").toString();      //最近编号
    templateList.append(configIniRead->value("template/templateFirst").toString());
    templateList.append(configIniRead->value("template/templateSecond").toString());
    templateList.append(configIniRead->value("template/templateThird").toString());
    templateList.append(configIniRead->value("template/templateFourth").toString());
    templateList.append(configIniRead->value("template/templateFiveth").toString());
    templateList.append(configIniRead->value("template/templateSixth").toString());

    SAFEDELETE(configIniRead);
}

/****************          写入配置文件          ***************/
void QReadIni::writeIni(QString userName, QString passWord)
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));
    configIniWrite->setValue("login/username", userName);                         //用户名
    configIniWrite->setValue("login/password", passWord);                         //密码
    SAFEDELETE(configIniWrite);
}

/****************          写入配置文件          ***************/
void QReadIni::writeIni(QString startNumber)
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));
    configIniWrite->setValue("init/startNumber", startNumber);                  //用户名
    this->startNumber = startNumber;
    SAFEDELETE(configIniWrite);
}

/****************          写入配置文件           ***************/
void QReadIni::writeQCIni(QString recentNumber)
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));
    configIniWrite->setValue("init/recentNumber", recentNumber);                  //用户名
    this->recentNumber = recentNumber;
    SAFEDELETE(configIniWrite);
}

/****************          写入模板配置文件           ***************/
void QReadIni::writeTemplateIni()
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));

    if(templateList.size() < 6) return;

    configIniWrite->setValue("template/templateFirst", templateList.at(0));
    configIniWrite->setValue("template/templateSecond",templateList.at(1));
    configIniWrite->setValue("template/templateThird", templateList.at(2));
    configIniWrite->setValue("template/templateFourth",templateList.at(3));
    configIniWrite->setValue("template/templateFiveth",templateList.at(4));
    configIniWrite->setValue("template/templateSixth", templateList.at(5));

    SAFEDELETE(configIniWrite);
}

const DataConfig &QReadIni::getDataConfig()
{
    return dataConfig;
}


