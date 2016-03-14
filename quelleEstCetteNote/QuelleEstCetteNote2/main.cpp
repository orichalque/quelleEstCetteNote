#include "mainwindow.h"
#include <QSpacerItem>
#include <iostream>
#include <QApplication>
#include "piano.h"
#include "portee.h"
#include <QLayout>
#include <QVBoxLayout>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    w.setFixedSize(1366, 720);
    Piano *pi = new Piano(&w);
    Portee *po = new Portee(&w);
    QHBoxLayout qhblupper;

    pi -> setFixedSize(1000, 300);
    po -> setFixedSize(1000, 300);
    QVBoxLayout qvbox;
    qvbox.addWidget(po);
    qvbox.addWidget(pi);



    w.setLayout(&qvbox);
    w.show();

    return a.exec();
}
