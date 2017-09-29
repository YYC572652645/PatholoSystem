#ifndef MOVEWIDGETCONTROL_H
#define MOVEWIDGETCONTROL_H

/***************************************************************
   功能:提升的打印区域Widget,可用来移动控件

   创建人:殷宇辰

   创建时间:2017-9-18
**************************************************************/

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include "printtemplate/qselectwidget/qselectwidget.h"
#include <QMouseEvent>

class MoveWidgetControl : public QWidget
{
    Q_OBJECT
public:
    explicit MoveWidgetControl(QWidget *parent = 0);

public:
    Selection *selectWidget;   //提升窗口部件
    void clearBox();           //清除Box边界
};

#endif // MOVEWIDGETCONTROL_H
