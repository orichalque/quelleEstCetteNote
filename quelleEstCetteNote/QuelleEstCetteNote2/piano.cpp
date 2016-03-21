#include "piano.h"
#include "log.cpp"
#include <QAbstractButton>
#include <QVBoxLayout>
#include <QSlider>
#include <QVector>
#include <iostream>
#include <QCheckBox>
#include <QPalette>
char action[50]= "appuie sur touche";
Piano::Piano(QWidget *parent) :
    QWidget(parent)
{
    init_log();
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, QColor::fromRgb(240, 240, 240));
    setAutoFillBackground(true);
    setPalette(Pal);

    showing = false; //displaying the scorebox

    b_names_dip = false;
    b_racc_disp = false;
    notes = new QVector<Touche*>();
    notes_jouees = new QVector<QString>();
    setFixedSize(800, 310);

    QPushButton *raccButt= new QPushButton(QString(""),this);
    raccButt->setToolTip(QString("Affiche les raccourcis clavier pour le piano"));
    QPushButton *noteNames = new QPushButton(QString(""),this);
    noteNames->setToolTip(QString("Affiche le nom des notes sur le piano"));

    QCheckBox *checkB = new QCheckBox(QString("options affichage"),this);
    checkB->setToolTip(QString("Affiche/cache les options d'affiche du piano"));
    QPushButton *retour = new QPushButton(QString(""),this);
    checkB->setChecked(true);
    retour->move(740,0);
    retour->setStyleSheet("border-image: url(:/new/prefix1/undo.png)");
    retour->setToolTip(QString("Annule la dernière note jouée"));
    retour->resize(50,50);
    QPushButton *solution = new QPushButton(QString("Solution"),this);
    solution->setToolTip(QString("Aide: Indique la note suivante sur le piano"));
    solution->move(0,10);
    checkB->move(0,282);
    Touche* doM = new Touche(this, QString("tab"),QString("Do"));
    int sizeT= 38;//doM->width();
    //QMessageBox::information(new QWidget(),QString("taille "),QString::number(sizeT));

    int hauteur = 100;
    int nT =3;
    raccButt->move(0,hauteur+50);
    raccButt->setFixedSize(140,50);
    raccButt->setStyleSheet("border-image: url(:/img/clavier.svg.png);"
                            );



    noteNames->move(660,hauteur +50);
    noteNames->setFixedSize(140,50);
    noteNames->setStyleSheet("border-image: url(:/img/doremi);"
                            "border-width: 2px;");

    doM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* reM = new Touche(this, QString("A"),QString("Ré"));
    reM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* miM = new Touche(this, QString("Z"),QString("Mi"));
    miM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* faM = new Touche(this, QString("E"),QString("Fa"));
    faM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* solM = new Touche(this, QString("R"),QString("Sol"));
    solM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* laM = new Touche(this, QString("T"),QString("La"));
    laM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* siM = new Touche(this, QString("Y"),QString("si"));
    siM->move(sizeT*nT,hauteur);
    nT+=1;

    Touche* dom = new Touche(this, QString("U"),QString("Do"));
    dom->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* rem = new Touche(this, QString("I"),QString("Ré"));
    rem->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* mim = new Touche(this, QString("O"),QString("Mi"));
    mim->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* fam = new Touche(this, QString("P"),QString("Fa"));
    fam->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* solm = new Touche(this, QString(/*"dead_circumflex"*/"16781906"),QString("Sol"));
    solm->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* lam = new Touche(this, QString("$"),QString("La"));
    lam->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* sim = new Touche(this, QString("Return"),QString("si"));
    sim->move(sizeT*nT,hauteur);


    nT=4;


    Touche* doMD = new Touche(this, QString("&"),QString("Do#"));
    doMD->black();
    doMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* reMD = new Touche(this, QString("é"),QString("Ré#"));
    reMD->black();
    reMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=2;
    Touche* faMD = new Touche(this, QString("'"),QString("Fa#"));
    faMD->black();
    faMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* solMD = new Touche(this, QString("("),QString("Sol#"));
    solMD->black();
    solMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* laMD = new Touche(this, QString("-"),QString("La#"));
    laMD->black();
    laMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=2;

    Touche* domD = new Touche(this, QString("_"),QString("Do#"));
    domD->black();
    domD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* remD = new Touche(this, QString("ç"),QString("Ré#"));
    remD->black();
    remD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=2;
    Touche* famD = new Touche(this, QString(")"),QString("Fa#"));
    famD->black();
    famD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* solmD = new Touche(this, QString("="),QString("Sol#"));
    solmD->black();
    solmD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* lamD = new Touche(this, QString("Backspace"),QString("La#"));
    lamD->black();
    lamD->move(sizeT*nT-sizeT/4,hauteur);







     QObject::connect(doM, SIGNAL(clicked()), this, SLOT(play_doM()));notes->append(doM);
     QObject::connect(reM, SIGNAL(clicked()), this, SLOT(play_reM()));notes->append(reM);
     QObject::connect(miM, SIGNAL(clicked()), this, SLOT(play_miM()));notes->append(miM);
     QObject::connect(faM, SIGNAL(clicked()), this, SLOT(play_faM()));notes->append(faM);
     QObject::connect(solM, SIGNAL(clicked()), this, SLOT(play_solM()));notes->append(solM);
     QObject::connect(laM, SIGNAL(clicked()), this, SLOT(play_laM()));notes->append(laM);
     QObject::connect(siM, SIGNAL(clicked()), this, SLOT(play_siM()));notes->append(siM);

     QObject::connect(dom, SIGNAL(clicked()), this, SLOT(play_dom()));notes->append(dom);
     QObject::connect(rem, SIGNAL(clicked()), this, SLOT(play_rem()));notes->append(rem);
     QObject::connect(mim, SIGNAL(clicked()), this, SLOT(play_mim()));notes->append(mim);
     QObject::connect(fam, SIGNAL(clicked()), this, SLOT(play_fam()));notes->append(fam);
     QObject::connect(solm, SIGNAL(clicked()), this, SLOT(play_solm()));notes->append(solm);
     QObject::connect(lam, SIGNAL(clicked()), this, SLOT(play_lam()));notes->append(lam);
     QObject::connect(sim, SIGNAL(clicked()), this, SLOT(play_sim()));notes->append(sim);

     QObject::connect(doMD, SIGNAL(clicked()), this, SLOT(play_doMD()));notes->append(doMD);
     QObject::connect(reMD, SIGNAL(clicked()), this, SLOT(play_reMD()));notes->append(reMD);

     QObject::connect(faMD, SIGNAL(clicked()), this, SLOT(play_faMD()));notes->append(faMD);
     QObject::connect(solMD, SIGNAL(clicked()), this, SLOT(play_solMD()));notes->append(solMD);
     QObject::connect(laMD, SIGNAL(clicked()), this, SLOT(play_laMD()));notes->append(laMD);

     QObject::connect(domD, SIGNAL(clicked()), this, SLOT(play_domD()));notes->append(domD);
     QObject::connect(remD, SIGNAL(clicked()), this, SLOT(play_remD()));notes->append(remD);

     QObject::connect(famD, SIGNAL(clicked()), this, SLOT(play_famD()));notes->append(famD);
     QObject::connect(solmD, SIGNAL(clicked()), this, SLOT(play_solmD()));notes->append(solmD);
     QObject::connect(lamD, SIGNAL(clicked()), this, SLOT(play_lamD()));notes->append(lamD);


     QObject::connect(raccButt, SIGNAL(clicked()), this, SLOT(display_racc()));
     QObject::connect(noteNames, SIGNAL(clicked()), this, SLOT(display_names()));
     QObject::connect(checkB, SIGNAL(toggled(bool)), this, SLOT(checking(bool)));
     QObject::connect(retour, SIGNAL(clicked()), this, SLOT(retour_arriere()));



}

void Piano::retour_arriere(){

    if(notes_jouees->size()>0){
        QSound::play(":/new/prefix1/son/back.wav");
        notes_jouees->removeLast();
        emit(played());
    }

}

int Piano::scoreMsg(){
    QMessageBox msgBox;
    msgBox.setDefaultButton(QMessageBox::Cancel);
    showing = true;
    QString mesg = "Partie terminée\n Score: "+QString::number(nbOfSuccess)+" %";
    msgBox.setText(mesg);
    msgBox.addButton(tr("Réinitialiser la portée"), QMessageBox::NoRole);
    QAbstractButton* pButtonContinue = msgBox.addButton(tr("Recommencer"), QMessageBox::YesRole);

    int ret = msgBox.exec();
    if (msgBox.clickedButton() == pButtonContinue){
        return 1;
    } else {
        notes_jouees->clear();
        return 0;
    }
}

QVector<bool>* Piano::comparaison(QVector<QString> *partition){
    QVector<bool> *tabCorrection = new QVector<bool>();
    if(notes_jouees->size()<=partition->size()){
        for(int i=0;i<notes_jouees->size();i++){
           if(notes_jouees->at(i).compare(partition->at(i))==0){
               tabCorrection->append(true);
               nbOfSuccess++;
           }else{
               tabCorrection->append(false);
           }
        }

    }else{
        for(int i=0;i<partition->size();i++){
            if(notes_jouees->at(i).compare(partition->at(i))==0){
                tabCorrection->append(true);
            }else{
                tabCorrection->append(false);
            }
         }
    }

    if (!this->showing){
        nbOfSuccess = (100*(nbOfSuccess/tabCorrection->size()));
    }

    return tabCorrection;
}

void Piano::checking(bool checked){
    log("L'utilisateur"," affiche les options");
    int sizeT= 38;

    int nT =3;
    int hauteur= 100;
    if(checked){
        QSound::play(":/new/prefix1/son/sim.wav");
        QSound::play(":/new/prefix1/son/solm.wav");
        //reduire le piano
            for(Touche *t : *notes){
                if(t->blacked){
                    t->resize(sizeT*2/3,sizeT*8/3);
                    t->move(sizeT*(nT-13)-sizeT/4,hauteur);
                    nT++;
                    if(nT==19||nT==23||nT==26){
                        nT++;
                    }
                }else{
                    t->resize(sizeT,sizeT*4);
                    t->move(sizeT*nT,hauteur);
                    nT++;
                }

            }

    }else{
        log("L'utilisateur","cache les options / agrandit le piano");
        sizeT= 56;

        nT =0;
        hauteur= 60;
        QSound::play(":/new/prefix1/son/doM.wav");
        QSound::play(":/new/prefix1/son/faM.wav");

        //agrandir piano
        for(Touche *t : *notes){
            if(t->blacked){
                t->resize(sizeT*2/3,sizeT*8/3);
                t->move(sizeT*(nT-13)-sizeT/4,hauteur);
                nT++;
                if(nT==19-3||nT==23-3||nT==26-3){
                    nT++;
                }
            }else{
                t->resize(sizeT,sizeT*4);
                t->move(sizeT*nT,hauteur);
                nT++;
            }

        }
    }
}

void Piano::display_racc(){
    for(Touche *t : *notes){
        if(b_racc_disp){
           /* if(b_names_dip){

            }else{

            }*/
            log("L'utilisateur","cache les raccourcis");
            auto rac = t->getRacc(); //sauvegarde du raccourci qui change sinon
            t->setText("");
            t->setShortcut(rac);
        }else{
           /* if(b_names_dip){

            }else{*/
            log("L'utilisateur","affiche les raccourcis");
                auto rac = t->getRacc(); //sauvegarde du raccourci qui change sinon
                t->setText(t->getRacc());
                t->setShortcut(rac);
                if(t->blacked){
                    t->setStyleSheet("background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(182, 182, 182, 255), stop:0.564576 rgba(0, 0, 0, 255));"
                                    "font: bold;"
                                  "color: white;"
                                  "border-style: outset;"
                                  "border-color: white;"
                                  "font-size: 6px;"
                                  "border-bottom-right-radius: 3px;"
                                  "border-bottom-left-radius: 3px;"
                                  );

                }
           // }
        }
    }

    b_racc_disp = !(b_racc_disp);
    b_names_dip =false;
}
void Piano::display_names(){
    for(Touche *t : *notes){
        if(b_names_dip){
            /*if(b_names_dip){

            }else{

            }*/
            log("L'utilisateur","cache le nom des notes");
            auto rac = t->getRacc(); //sauvegarde du raccourci qui change sinon
            t->setText("");
            t->setShortcut(rac);
        }else{
            /*if(b_names_dip){

            }else{*/
            log("L'utilisateur","affiche le nom des notes");
               auto rac = t->getRacc(); //sauvegarde du raccourci qui change sinon
               t->setText(t->getNote());
               t->setShortcut(rac);
               if(t->blacked){
                   t->setStyleSheet("background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(182, 182, 182, 255), stop:0.564576 rgba(0, 0, 0, 255));"
                                   "font: bold;"
                                 "color: white;"
                                 "border-style: outset;"
                                 "border-color: white;"
                                 "font-size: 6px;"
                                 "border-bottom-right-radius: 3px;"
                                 "border-bottom-left-radius: 3px;"
                                 );

               }
            //}
        }
    }
    b_names_dip = !(b_names_dip);
    b_racc_disp = false;
}
 void Piano::play_dom(){
     QSound::play(":/new/prefix1/son/dom.wav");
     notes_jouees->append(QString("dom"));
     char action2[50]=  "do mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_rem(){
     QSound::play(":/new/prefix1/son/rem.wav");
     notes_jouees->append(QString("rem"));
     char action2[50]=  "re mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_mim(){
     QSound::play(":/new/prefix1/son/mim.wav");
     notes_jouees->append(QString("mim"));
     char action2[50]=  "mi mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_fam(){
     QSound::play(":/new/prefix1/son/fam.wav");
     notes_jouees->append(QString("fam"));
     char action2[50]=  "fa mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_solm(){
     QSound::play(":/new/prefix1/son/solm.wav");
     notes_jouees->append(QString("solm"));
     char action2[50]=  "sol mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_lam(){
     QSound::play(":/new/prefix1/son/lam.wav");
     notes_jouees->append(QString("lam"));
     char action2[50]=  "la mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_sim(){
     QSound::play(":/new/prefix1/son/sim.wav");
     notes_jouees->append(QString("sim"));
     char action2[50]=  "si mineur";
     log(action,action2);
     emit played();
 }



 void Piano::play_doM(){
     QSound::play(":/new/prefix1/son/doM.wav");
     notes_jouees->append(QString("doM"));
     char action2[50]=  "do Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_reM(){
     QSound::play(":/new/prefix1/son/reM.wav");
     notes_jouees->append(QString("reM"));
     char action2[50]=  "re Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_miM(){
     QSound::play(":/new/prefix1/son/miM.wav");
     notes_jouees->append(QString("miM"));
     char action2[50]=  "mi Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_faM(){
     QSound::play(":/new/prefix1/son/faM.wav");
     notes_jouees->append(QString("faM"));
     char action2[50]=  "fa Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_solM(){
     QSound::play(":/new/prefix1/son/solM.wav");
     notes_jouees->append(QString("solM"));
     char action2[50]=  "sol Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_laM(){
     QSound::play(":/new/prefix1/son/laM.wav");
     notes_jouees->append(QString("laM"));
     char action2[50]=  "la Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_siM(){
     QSound::play(":/new/prefix1/son/siM.wav");
     notes_jouees->append(QString("siM"));
     char action2[50]=  "si Majeur";
     log(action,action2);
     emit played();
 }

 void Piano::play_domD(){
     QSound::play(":/new/prefix1/son/domD.wav");
     notes_jouees->append(QString("domD"));
     char action2[50]=  "do# mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_remD(){
     QSound::play(":/new/prefix1/son/remD.wav");
     notes_jouees->append(QString("remD"));
     char action2[50]=  "re# mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_famD(){
     QSound::play(":/new/prefix1/son/famD.wav");
     notes_jouees->append(QString("famD"));
     char action2[50]=  "fa# mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_solmD(){
     QSound::play(":/new/prefix1/son/solmD.wav");
     notes_jouees->append(QString("solmD"));
     char action2[50]=  "sol# mineur";
     log(action,action2);
     emit played();
 }
 void Piano::play_lamD(){
     QSound::play(":/new/prefix1/son/lamD.wav");
     notes_jouees->append(QString("lamD"));
     char action2[50]=  "la# mineur";
     log(action,action2);
     emit played();
 }

 void Piano::play_doMD(){
     QSound::play(":/new/prefix1/son/doMD.wav");
     notes_jouees->append(QString("doMD"));
     char action2[50]=  "do# Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_reMD(){
     QSound::play(":/new/prefix1/son/reMD.wav");
     notes_jouees->append(QString("reMD"));
     char action2[50]=  "re# Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_faMD(){
     QSound::play(":/new/prefix1/son/faMD.wav");
     notes_jouees->append(QString("faMD"));
     char action2[50]=  "fa# Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_solMD(){
     QSound::play(":/new/prefix1/son/solMD.wav");
     notes_jouees->append(QString("solMD"));
     char action2[50]=  "sol# Majeur";
     log(action,action2);
     emit played();
 }
 void Piano::play_laMD(){
     QSound::play(":/new/prefix1/son/laMD.wav");
     notes_jouees->append(QString("laMD"));
     char action2[50]=  "la# Majeur";
     log(action,action2);
     emit played();
 }



