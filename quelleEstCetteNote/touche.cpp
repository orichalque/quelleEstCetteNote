#include "touche.h"

using namespace std;
Touche::Touche(QString  raccourci, QString note): QPushButton(){
    setText("");
    setStyleSheet("background-color: rgb(255, 255, 255);");
    QString tooltip(""+note +": raccourci -> "+ raccourci);
    setToolTip(tooltip);
    setShortcut(raccourci);
    resize(30,130);


}

void Touche::on_clicked(){
    setStyleSheet("background-color: rgb(0, 0, 0);");
}
void Touche::on_released(){
    setStyleSheet("background-color: rgb(0, 0, 0);");
}
