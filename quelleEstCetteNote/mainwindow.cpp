#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywidget.h"
#include <QLabel>
#include <QPainter>
#include <iostream>
#include <QDebug>
#include <cmath>
#include "piano.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Piano *p = new Piano(this);

}

void MainWindow::paintEvent(QPaintEvent * event)
{
    QMainWindow::paintEvent(event);
    QPainter p(this);


    int w = width();
    int h = height();

    // Nb of note, depends of the  music entry
    //TODO
    int noteAmount = 13;

    float lineLength = w * (0.70); //57% of width

    // 0-12 note -> 1 line
    // 12 - 24 -> 2 line

    int nbOfLine = int (noteAmount / 12 +1);

    float interLineSpace = h*(0.07/nbOfLine);

    float upSpace = h*(0.1 / nbOfLine);

    float xBegin(0.15*w); //15% of width
    float xEnd(xBegin+lineLength);

    float y(0);
    qDebug() << QString::number(nbOfLine);
    for (int i = 0; i < nbOfLine; ++i){
        y += upSpace;
        for (int j = 0; j < 5; ++j){
            p.drawLine(xBegin, y, xEnd, y);
            y += interLineSpace;
        }
    }



    QPalette Pal(palette());

    // set black background
    Pal.setColor(QPalette::Background, QColor::fromRgb(203, 243, 238));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->show();




/*
    p.drawLine(1, 1, 1500, 0);
    p.drawLine(1, 5, 1500, 0);
    p.drawLine(1, 1, 100, 250);
    QString str = "";
    str = "Hauteur: " + QString::number(height()) + " largeur: " + QString::number(width());

    qDebug() << str;
 */

}

MainWindow::~MainWindow()
{
    delete ui;
}

