#include "piano.h"
#include "log.cpp"
#include <QVBoxLayout>
#include <QSlider>
#include <QVector>

char action[50]= "appuie sur touche";
Piano::Piano(QWidget *parent) :
    QWidget(parent)
{

    b_names_dip = false;
    b_racc_disp = false;
    notes = new QVector<Touche*>();
    setFixedSize(800, 310);

    QPushButton *raccButt= new QPushButton(QString("raccourcis"),this);
    QPushButton *noteNames = new QPushButton(QString("do ré mi ..."),this);

    Touche* doM = new Touche(this, QString("tab"),QString("DoM"));
    int sizeT= doM->width();
    int hauteur = 100;
    int nT =3;
    raccButt->move(0,hauteur+50);
    noteNames->move(700,hauteur +50);
    doM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* reM = new Touche(this, QString("A"),QString("RéM"));
    reM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* miM = new Touche(this, QString("Z"),QString("MiM"));
    miM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* faM = new Touche(this, QString("E"),QString("FaM"));
    faM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* solM = new Touche(this, QString("R"),QString("SolM"));
    solM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* laM = new Touche(this, QString("T"),QString("LaM"));
    laM->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* siM = new Touche(this, QString("Y"),QString("siM"));
    siM->move(sizeT*nT,hauteur);
    nT+=1;

    Touche* dom = new Touche(this, QString("U"),QString("Dom"));
    dom->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* rem = new Touche(this, QString("I"),QString("Rém"));
    rem->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* mim = new Touche(this, QString("O"),QString("Mim"));
    mim->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* fam = new Touche(this, QString("P"),QString("Fam"));
    fam->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* solm = new Touche(this, QString(/*"dead_circumflex"*/"16781906"),QString("Solm"));
    solm->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* lam = new Touche(this, QString("$"),QString("Lam"));
    lam->move(sizeT*nT,hauteur);
    nT+=1;
    Touche* sim = new Touche(this, QString("Return"),QString("sim"));
    sim->move(sizeT*nT,hauteur);


    nT=4;


    Touche* doMD = new Touche(this, QString("&"),QString("DoMD"));
    doMD->black();
    doMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* reMD = new Touche(this, QString("é"),QString("RéMD"));
    reMD->black();
    reMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=2;
    Touche* faMD = new Touche(this, QString("'"),QString("FaMD"));
    faMD->black();
    faMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* solMD = new Touche(this, QString("("),QString("SolMD"));
    solMD->black();
    solMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* laMD = new Touche(this, QString("-"),QString("LaMD"));
    laMD->black();
    laMD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=2;

    Touche* domD = new Touche(this, QString("_"),QString("DomD"));
    domD->black();
    domD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* remD = new Touche(this, QString("ç"),QString("RémD"));
    remD->black();
    remD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=2;
    Touche* famD = new Touche(this, QString(")"),QString("FamD"));
    famD->black();
    famD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* solmD = new Touche(this, QString("="),QString("SolmD"));
    solmD->black();
    solmD->move(sizeT*nT-sizeT/4,hauteur);
    nT+=1;
    Touche* lamD = new Touche(this, QString("Backspace"),QString("LamD"));
    lamD->black();
    lamD->move(sizeT*nT-sizeT/4,hauteur);





     QObject::connect(dom, SIGNAL(clicked()), this, SLOT(play_dom()));notes->append(dom);
     QObject::connect(rem, SIGNAL(clicked()), this, SLOT(play_rem()));notes->append(rem);
     QObject::connect(mim, SIGNAL(clicked()), this, SLOT(play_mim()));notes->append(mim);
     QObject::connect(fam, SIGNAL(clicked()), this, SLOT(play_fam()));notes->append(fam);
     QObject::connect(solm, SIGNAL(clicked()), this, SLOT(play_solm()));notes->append(solm);
     QObject::connect(lam, SIGNAL(clicked()), this, SLOT(play_lam()));notes->append(lam);
     QObject::connect(sim, SIGNAL(clicked()), this, SLOT(play_sim()));notes->append(sim);

     QObject::connect(doM, SIGNAL(clicked()), this, SLOT(play_doM()));notes->append(doM);
     QObject::connect(reM, SIGNAL(clicked()), this, SLOT(play_reM()));notes->append(reM);
     QObject::connect(miM, SIGNAL(clicked()), this, SLOT(play_miM()));notes->append(miM);
     QObject::connect(faM, SIGNAL(clicked()), this, SLOT(play_faM()));notes->append(faM);
     QObject::connect(solM, SIGNAL(clicked()), this, SLOT(play_solM()));notes->append(solM);
     QObject::connect(laM, SIGNAL(clicked()), this, SLOT(play_laM()));notes->append(laM);
     QObject::connect(siM, SIGNAL(clicked()), this, SLOT(play_siM()));notes->append(siM);

     QObject::connect(domD, SIGNAL(clicked()), this, SLOT(play_domD()));notes->append(domD);
     QObject::connect(remD, SIGNAL(clicked()), this, SLOT(play_remD()));notes->append(remD);

     QObject::connect(famD, SIGNAL(clicked()), this, SLOT(play_famD()));notes->append(famD);
     QObject::connect(solmD, SIGNAL(clicked()), this, SLOT(play_solmD()));notes->append(solmD);
     QObject::connect(lamD, SIGNAL(clicked()), this, SLOT(play_lamD()));notes->append(lamD);

     QObject::connect(doMD, SIGNAL(clicked()), this, SLOT(play_doMD()));notes->append(doMD);
     QObject::connect(reMD, SIGNAL(clicked()), this, SLOT(play_reMD()));notes->append(reMD);

     QObject::connect(faMD, SIGNAL(clicked()), this, SLOT(play_faMD()));notes->append(faMD);
     QObject::connect(solMD, SIGNAL(clicked()), this, SLOT(play_solMD()));notes->append(solMD);
     QObject::connect(laMD, SIGNAL(clicked()), this, SLOT(play_laMD()));notes->append(laMD);

     QObject::connect(raccButt, SIGNAL(clicked()), this, SLOT(display_racc()));
     QObject::connect(noteNames, SIGNAL(clicked()), this, SLOT(display_names()));

}

void Piano::display_racc(){
    for(Touche *t : *notes){
        if(b_racc_disp){
           /* if(b_names_dip){

            }else{

            }*/
            auto rac = t->getRacc(); //sauvegarde du raccourci qui change sinon
            t->setText("");
            t->setShortcut(rac);
        }else{
           /* if(b_names_dip){

            }else{*/
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
            auto rac = t->getRacc(); //sauvegarde du raccourci qui change sinon
            t->setText("");
            t->setShortcut(rac);
        }else{
            /*if(b_names_dip){

            }else{*/
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
     char action2[50]=  "do mineur";
     log(action,action2);
 }
 void Piano::play_rem(){
     QSound::play(":/new/prefix1/son/rem.wav");
     char action2[50]=  "re mineur";
     log(action,action2);
 }
 void Piano::play_mim(){
     QSound::play(":/new/prefix1/son/mim.wav");
     char action2[50]=  "mi mineur";
     log(action,action2);
 }
 void Piano::play_fam(){
     QSound::play(":/new/prefix1/son/fam.wav");
     char action2[50]=  "fa mineur";
     log(action,action2);
 }
 void Piano::play_solm(){
     QSound::play(":/new/prefix1/son/solm.wav");
     char action2[50]=  "sol mineur";
     log(action,action2);
 }
 void Piano::play_lam(){
     QSound::play(":/new/prefix1/son/lam.wav");
     char action2[50]=  "la mineur";
     log(action,action2);
 }
 void Piano::play_sim(){
     QSound::play(":/new/prefix1/son/sim.wav");
     char action2[50]=  "si mineur";
     log(action,action2);
 }


 void Piano::play_doM(){
     QSound::play(":/new/prefix1/son/doM.wav");
     char action2[50]=  "do Majeur";
     log(action,action2);
 }
 void Piano::play_reM(){
     QSound::play(":/new/prefix1/son/reM.wav");
     char action2[50]=  "re Majeur";
     log(action,action2);
 }
 void Piano::play_miM(){
     QSound::play(":/new/prefix1/son/miM.wav");
     char action2[50]=  "mi Majeur";
     log(action,action2);
 }
 void Piano::play_faM(){
     QSound::play(":/new/prefix1/son/faM.wav");
     char action2[50]=  "fa Majeur";
     log(action,action2);
 }
 void Piano::play_solM(){
     QSound::play(":/new/prefix1/son/solM.wav");
     char action2[50]=  "sol Majeur";
     log(action,action2);
 }
 void Piano::play_laM(){
     QSound::play(":/new/prefix1/son/laM.wav");
     char action2[50]=  "la Majeur";
     log(action,action2);
 }
 void Piano::play_siM(){
     QSound::play(":/new/prefix1/son/siM.wav");
     char action2[50]=  "si Majeur";
     log(action,action2);
 }

 void Piano::play_domD(){
     QSound::play(":/new/prefix1/son/domD.wav");
     char action2[50]=  "do# mineur";
     log(action,action2);
 }
 void Piano::play_remD(){
     QSound::play(":/new/prefix1/son/remD.wav");
     char action2[50]=  "re# mineur";
     log(action,action2);
 }
 void Piano::play_famD(){
     QSound::play(":/new/prefix1/son/famD.wav");
     char action2[50]=  "fa# mineur";
     log(action,action2);
 }
 void Piano::play_solmD(){
     QSound::play(":/new/prefix1/son/solmD.wav");
     char action2[50]=  "sol# mineur";
     log(action,action2);
 }
 void Piano::play_lamD(){
     QSound::play(":/new/prefix1/son/lamD.wav");
     char action2[50]=  "la# mineur";
     log(action,action2);
 }

 void Piano::play_doMD(){
     QSound::play(":/new/prefix1/son/doMD.wav");
     char action2[50]=  "do# Majeur";
     log(action,action2);
 }
 void Piano::play_reMD(){
     QSound::play(":/new/prefix1/son/reMD.wav");
     char action2[50]=  "re# Majeur";
     log(action,action2);
 }
 void Piano::play_faMD(){
     QSound::play(":/new/prefix1/son/faMD.wav");
     char action2[50]=  "fa# Majeur";
     log(action,action2);
 }
 void Piano::play_solMD(){
     QSound::play(":/new/prefix1/son/solMD.wav");
     char action2[50]=  "sol# Majeur";
     log(action,action2);
 }
 void Piano::play_laMD(){
     QSound::play(":/new/prefix1/son/laMD.wav");
     char action2[50]=  "la# Majeur";
     log(action,action2);
 }



