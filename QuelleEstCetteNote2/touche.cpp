#include "touche.h"
#include<QMessageBox>
using namespace std;
Touche::Touche(QWidget *parent, QString  raccourci, QString note):QPushButton(QString(""),parent){
    blacked = false;
    //setText(raccourci);
    int h = parent->height();
    this->racc = raccourci;
    this->note = note;
    QString tooltip(""+note +": raccourci -> "+ raccourci);
    this->QPushButton::setToolTip(tooltip);
    setShortcut(raccourci);
    resize(h/8,h/2);
    setFocusPolicy(Qt::StrongFocus);

        setStyleSheet("background-color: qlineargradient(spread:reflect, x1:0, y1:0.995, x2:0, y2:0, stop:0 rgba(221, 221, 221, 255), stop:1 rgba(255, 255, 255, 255));"
        "font: 8px;"
    );

}


void Touche::black(){
    blacked = true;
    resize(2*width()/3,2*height()/3);
    setStyleSheet("background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(182, 182, 182, 255), stop:0.564576 rgba(0, 0, 0, 255));"
                   "font: bold;"
                  "border-style: outset;"
                  "border-color: white;"
                  "font: 8px;"
                  "border-bottom-right-radius: 3px;"
                  "border-bottom-left-radius: 3px;"
                  );
}


/*
bool Touche::hitButton(const QPoint & pos) const{
    QSound::play("../../../son/do.wav");
    QMessageBox::information(new QWidget(),QString("debug"),QString("coucou"));
}*/

QString Touche::getNote(){
    return note;
}
QString Touche::getRacc(){
    return racc;
}

