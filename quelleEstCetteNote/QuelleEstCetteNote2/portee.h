#ifndef PORTEE_H
#define PORTEE_H
#include <QWidget>
#include "notereader.h"
#include "piano.h"

class Portee : public QWidget
{
public:
    Portee();
    explicit Portee(QWidget *parent = 0);
    void setPiano(Piano* p);

protected:
    void paintEvent(QPaintEvent * event);
    Piano* piano;
};

#endif // PORTEE_H
