#include "movewidgetcontrol.h"
#include "globaldef.h"
#include <QDebug>


MoveWidgetControl::MoveWidgetControl(QWidget *parent) : QWidget(parent)
{
    selectWidget = new Selection(this);
}

void MoveWidgetControl::clearBox()
{
    selectWidget->clear();
}
