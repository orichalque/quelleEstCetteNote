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
    Piano* piano;
    void paintEvent(QPaintEvent * event);
protected:



public slots:
    void refresh();
};

#endif // PORTEE_H
