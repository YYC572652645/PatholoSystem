#include "qreadini.h"
#include <QDebug>
#include "globaldef.h"
#include <QTextCodec>

QReadIni *QReadIni::instance = NULL;

/****************          单例模式              ***************/
QReadIni *QReadIni::getInstance()
{
    if(instance == NULL)
    {
        instance = new QReadIni();
    }
    return instance;
}

/****************          构造函数              ***************/
QReadIni::QReadIni()
{
    this->readIni();
}

/****************          读取配置文件           ***************/
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
    templateList.append(configIniRead->value("template/templateFirst").toString());         //登记模板
    templateList.append(configIniRead->value("template/templateSecond").toString());        //取材模板
    templateList.append(configIniRead->value("template/templateThird").toString());         //常规切片模板
    templateList.append(configIniRead->value("template/templateFourth").toString());        //免疫组化切片模板
    templateList.append(configIniRead->value("template/templateFiveth").toString());        //特染切片模板
    templateList.append(configIniRead->value("template/templateSixth").toString());         //免疫组化指标模板
    templateList.append(configIniRead->value("template/templateSeventh").toString());       //特染染色指标模板

    SAFEDELETE(configIniRead);
}

/****************          写入用户信息           ***************/
void QReadIni::writeIni(QString userName, QString passWord)
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);

    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));

    configIniWrite->setValue("login/username", userName);
    configIniWrite->setValue("login/password", passWord);

    SAFEDELETE(configIniWrite);
}

/****************          写入开始病理号          ***************/
void QReadIni::writeIni(QString startNumber)
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);

    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));

    configIniWrite->setValue("init/startNumber", startNumber);

    this->startNumber = startNumber;

    SAFEDELETE(configIniWrite);
}

/****************          写入最新病理号          ***************/
void QReadIni::writeQCIni(QString recentNumber)
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);

    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));

    configIniWrite->setValue("init/recentNumber", recentNumber);

    this->recentNumber = recentNumber;

    SAFEDELETE(configIniWrite);
}

/****************          写入模板信息            ***************/
void QReadIni::writeTemplateIni()
{
    QSettings * configIniWrite = new QSettings("config.ini",QSettings::IniFormat);

    configIniWrite->setIniCodec(QTextCodec::codecForName("GB2312"));

    if(templateList.size() < 7) return;

    configIniWrite->setValue("template/templateFirst",   templateList.at(0));
    configIniWrite->setValue("template/templateSecond",  templateList.at(1));
    configIniWrite->setValue("template/templateThird",   templateList.at(2));
    configIniWrite->setValue("template/templateFourth",  templateList.at(3));
    configIniWrite->setValue("template/templateFiveth",  templateList.at(4));
    configIniWrite->setValue("template/templateSixth",   templateList.at(5));
    configIniWrite->setValue("template/templateSeventh", templateList.at(6));

    SAFEDELETE(configIniWrite);
}

/****************          获取数据库配置信息       ***************/
const DataConfig &QReadIni::getDataConfig()
{
    return dataConfig;
}

/****************          设置模板信息            ***************/
void QReadIni::setTemplateList(const QList<QString> &value)
{
    templateList = value;
}

/****************          获取模板信息            ***************/
QList<QString> QReadIni::getTemplateList() const
{
    return templateList;
}

/****************          获取最新病理号          ***************/
QString QReadIni::getRecentNumber() const
{
    return recentNumber;
}

/****************          获取开始病理号          ***************/
QString QReadIni::getStartNumber() const
{
    return startNumber;
}

/****************          获取用户信息            ***************/
LoginConfig QReadIni::getLoginConfig() const
{
    return loginConfig;
}
