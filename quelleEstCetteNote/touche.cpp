#include "touche.h"
#include<QMessageBox>
using namespace std;
Touche::Touche(QWidget *parent, QString  raccourci, QString note):QPushButton(QString(""),parent){

    int w = parent->width();
    int h = parent->height();
    this->racc = raccourci;
    this->note = note;
    this->QPushButton::setStyleSheet("background-color: rgb(255, 255, 255);");
    QString tooltip(""+note +": raccourci -> "+ raccourci);
    this->QPushButton::setToolTip(tooltip);
    setShortcut(raccourci);
    resize(h/12,h/3);
    setFocusPolicy(Qt::StrongFocus);


}


void Touche::black(){
    resize(2*width()/3,2*height()/3);
    setStyleSheet("background-color: rgb(0, 0, 0);");
}


/*
bool Touche::hitButton(const QPoint & pos) const{
    QSound::play("../../../son/do.wav");
    QMessageBox::information(new QWidget(),QString("debug"),QString("coucou"));
}*/

QString Touche::getNote(){
    return note;
}
