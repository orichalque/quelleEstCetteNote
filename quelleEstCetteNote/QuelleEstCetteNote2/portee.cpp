#include "portee.h"
#include "note.h"
#include <vector>
#include <QLabel>
#include <QPainter>
#include <iostream>
#include <QDebug>
#include <cmath>

using namespace std;
Portee::Portee()
{
}

Portee::Portee(QWidget *parent) :
    QWidget(parent)
{

}

void Portee::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
    QPainter p(this);
    vector<QString> notes;
    vector<note> notesToPlay;
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
    int noteAmount = notes.size();

    float lineLength = w * (0.70); //70% of width

    // 0-14 note -> 1 line
    // 14 - 28 -> 2 line

    int nbOfLine = int (noteAmount / 15 +1);

    float interLineSpace = h*(0.07/nbOfLine);

    float upSpace = h*(0.1 / nbOfLine);

    float xBegin(0.15*w); //15% of width
    float xEnd(xBegin+lineLength);

    float y(2*upSpace);
    for (int i = 0; i < nbOfLine; ++i){
        for (int j = 0; j < 5; ++j){
            p.drawLine(xBegin, y, xEnd, y);
            y += interLineSpace;
        }
        y += 2*upSpace;
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
    note *n;
    //(xNote,yNote , w*0.025 ,interLineSpace)
    vector<QRectF *> rectToDraw;
    int nbOfNotesDrawn;
    for (auto noteName : notes){

        yNote = (upSpace + 0.207*h + ((2*upSpace + 5*interLineSpace )*(nbOfNotesDrawn/14))); //Modulo le nombre de portées ! //TODO
        if (nbOfNotesDrawn % 14 == 0 && nbOfNotesDrawn > 0){
            xNote = 0.22*w;
        }

        if (noteName == "cm" || noteName =="dom"){
            //yNote immobile
        }
        if (noteName == "dm" || noteName =="rem"){
            yNote = yNote - 0.5*interLineSpace;
        }
        if (noteName == "em" || noteName =="mim"){
            yNote = yNote - 1*interLineSpace;
        }
        if (noteName == "fm" || noteName =="fam"){
            yNote = yNote - 1.5*interLineSpace;
        }
        if (noteName == "gm" || noteName =="solm"){
            yNote = yNote - 2*interLineSpace;
        }
        if (noteName == "am" || noteName =="lam"){
            yNote = yNote - 2.5*interLineSpace;
        }
        if (noteName == "bm" || noteName =="sim"){
            yNote = yNote - 3*interLineSpace;
        }

        if (noteName == "cM" || noteName =="doM"){
            yNote = yNote - 3.5*interLineSpace;
        }
        if (noteName == "dM" || noteName =="reM"){
            yNote = yNote - 4*interLineSpace;
        }
        if (noteName == "eM" || noteName =="miM"){
            yNote = yNote - 4.5*interLineSpace;
        }
        if (noteName == "fM" || noteName =="faM"){
            yNote = yNote - 5*interLineSpace;
        }
        if (noteName == "gM" || noteName =="solM"){
            yNote = yNote - 5.5*interLineSpace;
        }
        if (noteName == "aM" || noteName =="laM"){
            yNote = yNote - 6*interLineSpace;
        }
        if (noteName == "bM" || noteName =="siM"){
            yNote = yNote - 6.5*interLineSpace;
        }
        rect = new QRectF(xNote,yNote , w*0.025 ,interLineSpace);
        line = new QLine(xNote + 0.026*w, yNote+0.5*interLineSpace, xNote + 0.026*w, yNote-3*interLineSpace);
        n = new note(noteName, *rect, *line);
        notesToPlay.push_back(*n);
        n -> draw(&p);

        xNote = xNote + 0.045*w;

        nbOfNotesDrawn ++;
    }

    //note::correctAll(notesToPlay, &p);

/*
    p.drawLine(1, 1, 1500, 0);
    p.drawLine(1, 5, 1500, 0);
    p.drawLine(1, 1, 100, 250);
    QString str = "";
    str = "Hauteur: " + QString::number(height()) + " largeur: " + QString::number(width());

    qDebug() << str;
 */
}