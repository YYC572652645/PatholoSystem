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
    static QReadIni*getInstance();                      //单例模式
    void readIni();                                     //读取所有配置文件
    void writeIni(QString userName, QString passWord);  //写入用户信息
    void writeIni(QString startNumber);                 //写入开始病理号
    void writeQCIni(QString recentNumber);              //写入最新病理号
    void writeTemplateIni();                            //写入模板信息

    const DataConfig &getDataConfig();                  //获取数据库配置信息
    LoginConfig getLoginConfig() const;                 //获取登录配置信息
    QString getStartNumber() const;                     //获取开始病理号信息
    QString getRecentNumber() const;                    //获取最新病理号
    QList<QString> getTemplateList() const;             //获取使用的模板名称
    void setTemplateList(const QList<QString> &value);  //设置当前模板名称

private:
    QReadIni();                  //私有构造
    DataConfig dataConfig;       //数据库配置信息
    LoginConfig loginConfig;     //用户配置信息
    QString startNumber;         //开始病理号
    QString recentNumber;        //最新病理号
    QList<QString>templateList;  //使用的模板名称
    static QReadIni*instance;    //单例模式

};

#endif // QREADINI_H
