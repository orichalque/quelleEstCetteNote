#include "mainwindow.h"
#include <QSpacerItem>
#include <iostream>
#include <QApplication>
#include "piano.h"
#include "portee.h"
#include <QLayout>
#include <QVBoxLayout>
#include <QSlider>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    w.setFixedSize(800, 720);
    Piano *pi = new Piano(&w);
    Portee *po = new Portee(&w);
  /*  QHBoxLayout qhblupper;
    qhblupper.addSpacing(1);
    qhblupper.addWidget(po);
    qhblupper.addSpacing(1);;*/



    QVBoxLayout qvbox;
    qvbox.addWidget(po);
    qvbox.addWidget(pi);



    w.setLayout(&qvbox);
    //MainWindow w;
    w.show();

    return a.exec();
}
