#ifndef PORTEE_H
#define PORTEE_H
#include <QWidget>
#include <vector>
#include <QVector>
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
    void setFileName(QString fn);
    QVector<bool> result;

    void reset();
protected:
    QString fileName;
    bool modeCorrect;
    void scoreMsg();

signals:
    void callBox();

public slots:
    void refresh();
};

#endif // PORTEE_H
