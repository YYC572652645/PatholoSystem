#ifndef QREADINI_H
#define QREADINI_H
#include<QSettings>

/***************************************************************
   功能:读取INI配置文件

   创建人:殷宇辰

   创建时间:2017-7-29
**************************************************************/

#define DATACONFIG  QReadIni::getInstance()->getDataConfig()
#define INICONFIG   QReadIni::getInstance()


typedef struct DataConfig
{
    QString ip;                //IP地址
    QString port;              //端口
    QString dataBaseVersion;   //数据库版本
    QString dataBaseName;      //数据库名称
    QString userName;          //用户名
    QString passWord;          //密码
}DataConfig;

typedef struct LoginConfig
{
    QString userName;          //登录用户名
    QString passWord;          //登录密码
}LoginConfig;

class QReadIni
{
public:
    static QReadIni*getInstance();

    void readIni();                                     //读取配置文件
    void writeIni(QString userName, QString passWord);  //写入配置文件
    void writeIni(QString startNumber);                 //写入配置文件
    void writeQCIni(QString recentNumber);              //写入配置文件
    void writeTemplateIni();                            //写入配置文件

    const DataConfig &getDataConfig();

    LoginConfig getLoginConfig() const;
    QString getStartNumber() const;
    QString getRecentNumber() const;
    QList<QString> getTemplateList() const;

    void setTemplateList(const QList<QString> &value);

private:
    QReadIni();

    DataConfig dataConfig;
    LoginConfig loginConfig;
    QString startNumber;
    QString recentNumber;
    QList<QString>templateList;
    static QReadIni*instance;

};

#endif // QREADINI_H
