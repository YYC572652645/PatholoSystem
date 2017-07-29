#ifndef NEWSLICES_H
#define NEWSLICES_H

#include <QDialog>

namespace Ui {
class newslices;
}

class newslices : public QDialog
{
    Q_OBJECT

public:
    explicit newslices(QWidget *parent = 0);
    ~newslices();

private:
    Ui::newslices *ui;
};

#endif // NEWSLICES_H
