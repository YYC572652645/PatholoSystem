#ifndef MOVEWIDGETCONTROL_H
#define MOVEWIDGETCONTROL_H

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
    Selection *selectWidget;
    void clearBox();

};

#endif // MOVEWIDGETCONTROL_H
