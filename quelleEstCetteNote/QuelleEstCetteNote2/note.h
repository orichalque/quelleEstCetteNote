#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QLine>
#include <QRectF>
#include <QPainter>
#include <QBrush>
#include <chrono>
#include <thread>

class note
{
public:
    note();
    note(QString n, QRectF r, QLine l);

    void setRect(QRectF);
    void setTail(QLine l);
    void setNote(QString s);

    QString getNote();
    QRectF getRect();
    QLine getTail();

    void draw(QPainter *p);
    void drawRed(QPainter *p);
    void drawGreen(QPainter *p);

    void correct(QPainter *p);
    static void correctAll(std::vector<note> notes, QPainter *p);
private:
    QString noteName;
    QRectF rect;
    QLine tail;
    bool success;
};

#endif // NOTE_H
