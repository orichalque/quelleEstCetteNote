#ifndef PORTEE_H
#define PORTEE_H
#include <QWidget>
#include "notereader.h"

class Portee : public QWidget
{
public:
    Portee();
    explicit Portee(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent * event);

};

#endif // PORTEE_H
