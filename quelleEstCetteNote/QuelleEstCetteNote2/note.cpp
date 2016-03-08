#include "note.h"

note::note()
{
}

note::note(QString n, QRectF r, QLine l){
    note = n;
    rect = r;
    tail = l;
}

QString note::getNote(){
    return note;
}

QRectF note::getRect(){
    return rect;
}

QLine note::getTail(){
    return tail;
}

void note::draw(QPainter p){
    p.setBrush(QBrush(Qt::black));
    p.drawEllipse(rect);
}

void note::drawGreen(QPainter p){
    p.setBrush(QBrush(Qt::green));
    p.drawEllipse(rect);
}

void note::drawRed(QPainter p){
    p.setBrush(QBrush(Qt::red));
    p.drawEllipse(rect);
}
