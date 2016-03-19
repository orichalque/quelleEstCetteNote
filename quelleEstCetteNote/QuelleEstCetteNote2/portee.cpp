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
    setFixedSize(780, 490);
}

void Portee::setPiano(Piano* p){
    piano = p;
}

void Portee::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
    QPainter p(this);
    vector<QString> notes;
    vector<note> notesToPlay;
    NoteReader notereader;
    notes = notereader.readNotes(":/new/prefix1/part_lettre_elise.txt");
    int w = width();
    int h = height();

    // Nb of note, depends of the  music entry
    //TODO
    int noteAmount = notes.size();

    float lineLength = w * (0.70); //70% of width

    // 0-14 note -> 1 line
    // 14 - 28 -> 2 line
   // int nbOfNotesPerLine = 14;
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
    /*Pal.setColor(QPalette::Background, QColor::fromRgb(255, 255, 255));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->show();*/

    //C key placement
    QImage key(":/new/prefix1/clef.png");
    key = key.scaled(0.05*w, 6.5*interLineSpace);
    p.drawImage(0.15*w, 0.035*h / nbOfLine + upSpace, key);


    QImage blackN(":/new/prefix1/black.png"); //Note normale
    QImage blackD(":/new/prefix1/black_downLine.png"); //Note avec barre en bas sim, reM
    QImage blackU(":/new/prefix1/black_upLine.png"); //Note avec barre en haut : solm,
    QImage blackM(":/new/prefix1/black_middleLine.png"); //Note avec barre au milieu : lam, doM
    QImage blackDiese(":/new/prefix1/black_diese.png"); //Note diese
    blackN = blackN.scaled(0.05*w, 6.5*interLineSpace);
    blackD = blackD.scaled(0.05*w, 6.5*interLineSpace);
    blackU = blackU.scaled(0.05*w, 6.5*interLineSpace);
    blackM = blackM.scaled(0.05*w, 6.5*interLineSpace);
    blackDiese = blackDiese.scaled(0.05*w, 6.5*interLineSpace);

    //Notes
    // interLineSpace hauteur de la note
    float noteWidth = interLineSpace;
    //noteWidth a definir en fonction de la largeur de l'ecran

    qreal xNote = 0.22*w;
    qreal yNote;

    note *n;
    //(xNote,yNote , w*0.025 ,interLineSpace)
    vector<QRectF *> rectToDraw;
    int nbOfNotesDrawn;
    bool up, down, mid, diese;
    for (auto noteName : notes){
        up = down = mid = diese = false;
        yNote = 0.118*h + (((0.275*h)*(floor(nbOfNotesDrawn/14)))); //Modulo le nombre de portées ! //TODO
        cout << yNote << endl;
        if (nbOfNotesDrawn % 14 == 0 && nbOfNotesDrawn > 0){
            xNote = 0.22*w;
        }
        //if (this->piano->note_)
        p.drawLine(xNote, yNote, xNote , yNote + 5*interLineSpace);
        /* NOTE CLASSIQUE */
        if (noteName == "cm" || noteName =="doM"){
            //yNote immobile
            mid = true;
        } else
        if (noteName == "dm" || noteName =="reM"){
            yNote = yNote - 0.5*interLineSpace;
            down = true;
        } else
        if (noteName == "em" || noteName =="miM"){
            yNote = yNote - 1*interLineSpace;
        } else
        if (noteName == "fm" || noteName =="faM"){
            yNote = yNote - 1.5*interLineSpace;
        } else
        if (noteName == "gm" || noteName =="solM"){
            yNote = yNote - 2*interLineSpace;
        } else
        if (noteName == "am" || noteName =="laM"){
            yNote = yNote - 2.5*interLineSpace;
        } else
        if (noteName == "bm" || noteName =="siM"){
            yNote = yNote - 3*interLineSpace;
        } else
        if (noteName == "cM" || noteName =="dom"){
            yNote = yNote - 3.5*interLineSpace;
        } else
        if (noteName == "dM" || noteName =="rem"){
            yNote = yNote - 4*interLineSpace;
        } else
        if (noteName == "eM" || noteName =="mim"){
            yNote = yNote - 4.5*interLineSpace;
        } else
        if (noteName == "fM" || noteName =="fam"){
            yNote = yNote - 5*interLineSpace;
        } else
        if (noteName == "gM" || noteName =="solm"){
            yNote = yNote - 5.5*interLineSpace;
            up = true;
        } else
        if (noteName == "aM" || noteName =="lam"){
            yNote = yNote - 6*interLineSpace;
            mid = true;
        } else
        if (noteName == "bM" || noteName =="sim"){
            yNote = yNote - 6.5*interLineSpace;
            down = true;
        } else

        /* NOTE DIESE */
        if (noteName == "cm" || noteName =="doMD"){
            //yNote immobile
            mid = true;
        } else
        if (noteName == "dm" || noteName =="reMD"){
            yNote = yNote - 0.5*interLineSpace;
            down = true;
            diese = true;
        } else
        if (noteName == "em" || noteName =="miMD"){
            yNote = yNote - 1*interLineSpace;
            diese = true;
        } else
        if (noteName == "fm" || noteName =="faMD"){
            yNote = yNote - 1.5*interLineSpace;
            diese = true;
        } else
        if (noteName == "gm" || noteName =="solMD"){
            yNote = yNote - 2*interLineSpace;
            diese = true;
        } else
        if (noteName == "am" || noteName =="laMD"){
            yNote = yNote - 2.5*interLineSpace;
            diese = true;
        } else
        if (noteName == "bm" || noteName =="siMD"){
            yNote = yNote - 3*interLineSpace;
            diese = true;
        } else
        if (noteName == "cM" || noteName =="domD"){
            yNote = yNote - 3.5*interLineSpace;
            diese = true;
        } else
        if (noteName == "dM" || noteName =="remD"){
            yNote = yNote - 4*interLineSpace;
            diese = true;
        } else
        if (noteName == "eM" || noteName =="mimD"){
            yNote = yNote - 4.5*interLineSpace;
            diese = true;
        } else
        if (noteName == "fM" || noteName =="famD"){
            yNote = yNote - 5*interLineSpace;
            diese = true;
        } else
        if (noteName == "gM" || noteName =="solmD"){
            yNote = yNote - 5.5*interLineSpace;
            up = true;
            diese = true;
        } else
        if (noteName == "aM" || noteName =="lamD"){
            yNote = yNote - 6*interLineSpace;
            mid = true;
            diese = true;
        } else
        if (noteName == "bM" || noteName =="simD"){
            yNote = yNote - 6.5*interLineSpace;
            down = true;
            diese = true;
        }

        if (down == true){
            p.drawImage(xNote, yNote, blackD);
        } else if (up == true) {
            p.drawImage(xNote, yNote, blackU);
        } else if (mid == true) {
            p.drawImage(xNote, yNote, blackM);
        } else {
            p.drawImage(xNote, yNote, blackN);
        }

        if (diese) {
            p.drawImage(xNote, yNote, blackDiese);
        }



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
