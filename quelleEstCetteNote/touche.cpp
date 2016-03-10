#include "touche.h"

using namespace std;
Touche::Touche(QWidget *parent, QString  raccourci, QString note):QPushButton(QString(""),parent){

    //setText("");
    this->QPushButton::setStyleSheet("background-color: rgb(255, 255, 255);");
    QString tooltip(""+note +": raccourci -> "+ raccourci);
    this->QPushButton::setToolTip(tooltip);
    setShortcut(raccourci);
    this->QPushButton::resize(30,130);


}

void Touche::on_clicked(){
    this->QPushButton::setStyleSheet("background-color: rgb(255, 0, 0);");
}
void Touche::on_released(){
    this->QPushButton::setStyleSheet("background-color: rgb(0, 255, 0);");
}
