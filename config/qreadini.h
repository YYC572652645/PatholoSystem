#ifndef QREADINI_H
#define QREADINI_H
#include<QSettings>

/***************************************************************
   功能:读取INI配置文件

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#define DATACONFIG  QReadIni::getInstance()->getIniConfig()

typedef struct IniConfig
{
    QString ip;                //IP地址
    QString port;              //端口
    QString dataBaseVersion;   //数据库版本
    QString dataBaseName;      //数据库名称
    QString userName;          //用户名
    QString passWord;          //密码
}IniConfig;

class QReadIni
{
public:
    static QReadIni*getInstance();

    void readIni();

    const IniConfig &getIniConfig();

private:
    QReadIni();

    IniConfig iniConfig;

    static QReadIni*instance;
};

#endif // QREADINI_H
