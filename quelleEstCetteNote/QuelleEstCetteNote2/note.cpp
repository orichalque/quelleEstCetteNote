#include "note.h"

note::note()
{
}

note::note(QString n, QRectF r, QLine l){
    noteName = n;
    rect = r;
    tail = l;
    success = false;
}

QString note::getNote(){
    return noteName;
}

QRectF note::getRect(){
    return rect;
}

QLine note::getTail(){
    return tail;
}

void note::draw(QPainter* p){
    p -> setBrush(QBrush(Qt::black));
    p -> drawEllipse(rect);
    p -> drawLine(tail);
}

void note::drawGreen(QPainter* p){
    p -> setBrush(QBrush(Qt::green));
    p -> drawEllipse(rect);
    p -> drawLine(tail);
}

void note::drawRed(QPainter* p){
    p -> setBrush(QBrush(Qt::red));
    p -> drawEllipse(rect);
    p -> drawLine(tail);
}

void note::correct(QPainter *p){
    if (this -> success){
        drawGreen(p);
    } else {
        drawRed(p);
    }
}

void note::correctAll(std::vector<note> notes, QPainter *p){
    for (auto n : notes){
        //p->setPen(Qt::Pen);
        n.correct(p);
        //std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}
