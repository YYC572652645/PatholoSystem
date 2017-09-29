#include "movewidgetcontrol.h"
#include "globaldef.h"
#include <QDebug>

/****************          构造函数              ***************/
MoveWidgetControl::MoveWidgetControl(QWidget *parent) : QWidget(parent), selectWidget(NULL)
{
    selectWidget = new Selection(this);
}

/****************          清除Box边界            ***************/
void MoveWidgetControl::clearBox()
{
    selectWidget->clear();
}
