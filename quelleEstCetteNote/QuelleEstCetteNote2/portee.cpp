#include "portee.h"
#include "note.h"
#include <vector>
#include <QLabel>
#include <QPainter>
#include <iostream>
#include <QDebug>
#include <QVector>
#include <cmath>

using namespace std;
Portee::Portee()
{
}

Portee::Portee(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(780, 490);
    fileName = "";
    modeCorrect = false;
}


void Portee::setFileName(QString fn) {
    fileName = fn;
}

void Portee::refresh(){
    //this -> repaint();
}

void Portee::setPiano(Piano* p){
    piano = p;
    QObject::connect(piano, SIGNAL(played()), this, SLOT(update()));
}

void Portee::reset(){
    setFileName("");
}

void Portee::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
    QPainter p(this);
    QVector<QString> notes;
    vector<note> notesToPlay;
    NoteReader notereader;
    notes = notereader.readNotes(fileName);

    /* Dessin des lignes */
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

    /* Dessin des notes */
    if (! notes.empty()) {
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

        /* Loading des notes */

        QImage blackN(":/new/prefix1/black.png"); //Note normale
        QImage blackD(":/new/prefix1/black_downLine.png"); //Note avec barre en bas sim, reM
        QImage blackU(":/new/prefix1/black_upLine.png"); //Note avec barre en haut : solm,
        QImage blackM(":/new/prefix1/black_middleLine.png"); //Note avec barre au milieu : lam, doM
        QImage blackDiese(":/new/prefix1/black_diese.png"); //Note diese
        QImage green(":/new/prefix1/green.png");
        QImage red(":/new/prefix1/red.png");
        QImage greenD(":/new/prefix1/green_diese.png");
        QImage redD(":/new/prefix1/red_diese.png");


        blackN = blackN.scaled(0.05*w, 6.5*interLineSpace);
        blackD = blackD.scaled(0.05*w, 6.5*interLineSpace);
        blackU = blackU.scaled(0.05*w, 6.5*interLineSpace);
        blackM = blackM.scaled(0.05*w, 6.5*interLineSpace);
        blackDiese = blackDiese.scaled(0.05*w, 6.5*interLineSpace);
        green = green.scaled(0.05*w, 6.5*interLineSpace);
        red = red.scaled(0.05*w, 6.5*interLineSpace);
        greenD = greenD.scaled(0.05*w, 6.5*interLineSpace);
        redD = redD.scaled(0.05*w, 6.5*interLineSpace);


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

        /*CORRECTION*/
        if (notes.size() == piano -> notes_jouees -> size()){
            //On a joué toutes les notes, auto correction
            result = *(piano -> comparaison(&notes));
            modeCorrect = true;
            update();
        } else {
            modeCorrect = false;
        }


        /* PLACEMENT NOTES A JOUER */
        //Affichage des notes en noir si pas fini, notes en vert sinon
        for (auto noteName : notes){

            up = down = mid = diese = false;
            yNote = 0.118*h + (((0.275*h)*(floor(nbOfNotesDrawn/14))));
            if (nbOfNotesDrawn % 14 == 0 && nbOfNotesDrawn > 0){
                xNote = 0.22*w;
            }

            if (this -> piano != NULL && this->piano->notes_jouees->size()== nbOfNotesDrawn){
                //Scroller
                p.drawLine(xNote, yNote - 2*interLineSpace, xNote , yNote + 5*interLineSpace);
            }

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
                diese = true;
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

            /* MODE NORMAL */
            if (!modeCorrect){
                if (down == true){
                    p.drawImage(xNote, yNote, blackD);
                } else if (up == true) {
                    p.drawImage(xNote, yNote, blackU);
                } else if (mid == true) {
                    p.drawImage(xNote, yNote, blackM);
                } else {
                    p.drawImage(xNote, yNote, blackN);
                }
            }

            if (diese && !modeCorrect) {
                //on dessigne le dièse en plus
                p.drawImage(xNote, yNote, blackDiese);
            }

            /*************/


            if (modeCorrect){
                if (diese){
                    p.drawImage(xNote, yNote, greenD);
                } else {
                    p.drawImage(xNote, yNote, green);
                }
            }


            //Decallage de la note
            xNote = xNote + 0.045*w;
            nbOfNotesDrawn ++;
        }

        //Réinitialisation de l'abscisse
        xNote = 0.22*w;
        //Affichage des notes rouges quand il y a erreur
        if (modeCorrect == true ){
            for (int i = 0; i < piano->notes_jouees->size(); ++i){
                diese = false;
                yNote = 0.118*h + (((0.275*h)*(floor(i/14))));
                if (i % 14 == 0 && i > 0){
                    xNote = 0.22*w;
                }
                QString noteName = piano->notes_jouees->at(i);
                /* NOTE CLASSIQUE */
                if (noteName == "cm" || noteName =="doM"){
                    //yNote immobile
                } else
                if (noteName == "dm" || noteName =="reM"){
                    yNote = yNote - 0.5*interLineSpace;
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
                } else
                if (noteName == "aM" || noteName =="lam"){
                    yNote = yNote - 6*interLineSpace;
                } else
                if (noteName == "bM" || noteName =="sim"){
                    yNote = yNote - 6.5*interLineSpace;
                } else

                /* NOTE DIESE */
                if (noteName == "cm" || noteName =="doMD"){
                    //yNote immobile
                    diese = true;
                    mid = true;
                } else
                if (noteName == "dm" || noteName =="reMD"){
                    yNote = yNote - 0.5*interLineSpace;
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
                    diese = true;
                } else
                if (noteName == "bM" || noteName =="simD"){
                    yNote = yNote - 6.5*interLineSpace;
                    diese = true;
                }

                if (result.at(i)){
                    //nepas afficher
                } else {
                    if (diese){
                        p.drawImage(xNote, yNote, redD);
                    } else {
                        p.drawImage(xNote, yNote, red);
                    }
                }
                //Decallage de la note
                xNote = xNote + 0.045*w;
            }
            if (!piano->showing){
                if (!piano->scoreMsg()){
                    reset();
                }
            }
        }


    }
}



