#include "touche.h"
#include <QSound>
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
    //this->QPushButton::resize(30,130);
    resize(h/12,h/3);
    setFocusPolicy(Qt::StrongFocus);
    //QObject::connect(this, SIGNAL(pressed(Qt::Key_Escape)), note, SLOT(play()));


}

/*void Touche::clicked(Touche note){
    /*QSound::play("../../../son/do.wav");
    QMessageBox::information(new QWidget(),QString("debug"),QString("coucou"));
}
*/
void Touche::black(){
    resize(2*width()/3,2*height()/3);
    setStyleSheet("background-color: rgb(0, 0, 0);");
}

bool Touche::keyPressEvent(QEvent * e){
    /*if( 1==1/*e==QEvent::KeyPress /*==Qt::Key_A){
     QSound::play("../../../son/do.wav");
     QMessageBox::information(new QWidget(),QString("debug"),QString("event"));
    }*/
    return true;
}

bool Touche::hitButton(const QPoint & pos) const{
    /*QSound::play("../../../son/do.wav");
    QMessageBox::information(new QWidget(),QString("debug"),QString("coucou"));*/
}
void Touche::on__play(){
    QSound::play("../../../son/do.wav");
    QMessageBox::information(new QWidget(),QString("debug"),QString("on play"));
}

QString Touche::getNote(){
    return note;
}
void Touche::signal_play(){
    QMessageBox::information(new QWidget(),QString("debug"),QString("signal play"));
}
