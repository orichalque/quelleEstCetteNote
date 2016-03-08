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
    notes.push_back("cM");
    notes.push_back("dM");
    notes.push_back("eM");
    notes.push_back("fM");
    notes.push_back("gM");
    notes.push_back("aM");
    notes.push_back("bM");
    int w = width();
    int h = height();

    // Nb of note, depends of the  music entry
    //TODO
    int noteAmount = 15;

    float lineLength = w * (0.70); //70% of width

    // 0-12 note -> 1 line
    // 12 - 24 -> 2 line

    int nbOfLine = int (noteAmount / 12 +1);

    float interLineSpace = h*(0.07/nbOfLine);

    float upSpace = h*(0.1 / nbOfLine);

    float xBegin(0.15*w); //15% of width
    float xEnd(xBegin+lineLength);

    float y(upSpace);
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
    key = key.scaled(0.05*w, 6.5*interLineSpace);
    p.drawImage(0.15*w, 0.035*h / nbOfLine + upSpace, key);

    //Notes
    // interLineSpace hauteur de la note
    float noteWidth = interLineSpace;
    //noteWidth a definir en fonction de la largeur de l'ecran

    qreal xNote = 0.22*w;
    qreal yNote = (upSpace + 0.207*h);

    QRectF *rect;
    QLine *line;
    //(xNote,yNote , w*0.025 ,interLineSpace)
    vector<QRectF *> rectToDraw;
    for (auto note : notes){
        if (note == "cm" || note =="dom"){
            rect = new QRectF(xNote,yNote , w*0.025 ,interLineSpace);
            line = new QLine(xNote + 0.026*w, yNote+0.5*interLineSpace, xNote + 0.026*w, yNote-3*interLineSpace);
        }
        if (note == "dm" || note =="rem"){
            rect = new QRectF(xNote,yNote - 0.5*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "em" || note =="mim"){
            rect = new QRectF(xNote,yNote -1 *interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "fm" || note =="fam"){
            rect = new QRectF(xNote,yNote -1.5*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "gm" || note =="solm"){
            rect = new QRectF(xNote,yNote -2*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "am" || note =="lam"){
            rect = new QRectF(xNote,yNote -2.5*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "bm" || note =="sim"){
            rect = new QRectF(xNote,yNote -3*interLineSpace, w*0.025 ,interLineSpace);
        }

        if (note == "cM" || note =="doM"){
            rect = new QRectF(xNote,yNote -3.5*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "dM" || note =="reM"){
            rect = new QRectF(xNote,yNote -4*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "eM" || note =="miM"){
            rect = new QRectF(xNote,yNote -4.5*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "fM" || note =="faM"){
            rect = new QRectF(xNote,yNote -5*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "gM" || note =="solM"){
            rect = new QRectF(xNote,yNote -5.5*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "aM" || note =="laM"){
            rect = new QRectF(xNote,yNote -6*interLineSpace, w*0.025 ,interLineSpace);
        }
        if (note == "bM" || note =="siM"){
            rect = new QRectF(xNote,yNote -6.5*interLineSpace, w*0.025 ,interLineSpace);
        }

        rectToDraw.push_back(rect);
        p.setBrush(QBrush(Qt::black));
        p.drawEllipse(*rect);
        p.drawLine(*line);
        xNote = xNote + 0.045*w;
    }

    p.setBrush(QBrush(Qt::red));

    for (auto ellipse : rectToDraw){
        p.drawEllipse(*ellipse);
    }



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

