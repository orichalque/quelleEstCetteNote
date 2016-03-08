#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QLine>
#include <QRectF>
#include <QPainter>
#include <QBrush>
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

    void draw(QPainter p);
    void drawRed(QPainter p);
    void drawGreen(QPainter p);
private:
    QString note;
    QRectF rect;
    QLine tail;
};

#endif // NOTE_H
