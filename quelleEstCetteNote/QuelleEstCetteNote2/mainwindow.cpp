#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPainter>
#include <iostream>
#include <QDebug>
#include <cmath>
#include <QGraphicsScene>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::paintEvent(QPaintEvent * event)
{
    QMainWindow::paintEvent(event);
    QPainter p(this);
    vector<QString> notes;
    notes.push_back("cm");
    notes.push_back("dm");
    notes.push_back("em");
    notes.push_back("fm");
    notes.push_back("gm");
    notes.push_back("am");
    notes.push_back("bm");

    int w = width();
    int h = height();

    // Nb of note, depends of the  music entry
    //TODO
    int noteAmount = 15;

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

    //C key placement
    QImage key(":/new/prefix1/clef.png");
    key = key.scaled(2.5* interLineSpace, 6.5*interLineSpace);
    p.drawImage(0.15*w, 0.035*h / nbOfLine, key);

    //Notes
    // interLineSpace hauteur de la note
    float noteWidth = interLineSpace;
    //noteWidth a definir en fonction de la largeur de l'ecran

    qreal xNote = 0.25*w;
    qreal yNote = (5.5*interLineSpace);

    QRectF rect(xNote,yNote ,interLineSpace,interLineSpace);
    p.drawEllipse(rect);



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

