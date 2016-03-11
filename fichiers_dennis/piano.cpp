#include "piano.h"
Piano::Piano(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(1200,800);
    Touche* doM = new Touche(this, QString("tab"),QString("DoM"));
    int sizeT= doM->width();
    int nT =2;
    doM->move(sizeT*nT,10);
    nT+=1;
    Touche* reM = new Touche(this, QString("A"),QString("RéM"));
    reM->move(sizeT*nT,10);
    nT+=1;
    Touche* miM = new Touche(this, QString("Z"),QString("MiM"));
    miM->move(sizeT*nT,10);
    nT+=1;
    Touche* faM = new Touche(this, QString("E"),QString("FaM"));
    faM->move(sizeT*nT,10);
    nT+=1;
    Touche* solM = new Touche(this, QString("R"),QString("SolM"));
    solM->move(sizeT*nT,10);
    nT+=1;
    Touche* laM = new Touche(this, QString("T"),QString("LaM"));
    laM->move(sizeT*nT,10);
    nT+=1;
    Touche* siM = new Touche(this, QString("Y"),QString("siM"));
    siM->move(sizeT*nT,10);
    nT+=1;

    Touche* dom = new Touche(this, QString("U"),QString("Dom"));
    dom->move(sizeT*nT,10);
    nT+=1;
    Touche* rem = new Touche(this, QString("I"),QString("Rém"));
    rem->move(sizeT*nT,10);
    nT+=1;
    Touche* mim = new Touche(this, QString("O"),QString("Mim"));
    mim->move(sizeT*nT,10);
    nT+=1;
    Touche* fam = new Touche(this, QString("P"),QString("Fam"));
    fam->move(sizeT*nT,10);
    nT+=1;
    Touche* solm = new Touche(this, QString("¨"),QString("Solm"));
    solm->move(sizeT*nT,10);
    nT+=1;
    Touche* lam = new Touche(this, QString("$"),QString("Lam"));
    lam->move(sizeT*nT,10);
    nT+=1;
    Touche* sim = new Touche(this, QString("Entree"),QString("sim"));
    sim->move(sizeT*nT,10);


    nT=3;


    Touche* doMD = new Touche(this, QString("&"),QString("DoMD"));
    doMD->black();
    doMD->move(sizeT*nT-sizeT/4,10);
    nT+=1;
    Touche* reMD = new Touche(this, QString("é"),QString("RéMD"));
    reMD->black();
    reMD->move(sizeT*nT-sizeT/4,10);
    nT+=2;
    Touche* faMD = new Touche(this, QString("'"),QString("FaMD"));
    faMD->black();
    faMD->move(sizeT*nT-sizeT/4,10);
    nT+=1;
    Touche* solMD = new Touche(this, QString("("),QString("SolMD"));
    solMD->black();
    solMD->move(sizeT*nT-sizeT/4,10);
    nT+=1;
    Touche* laMD = new Touche(this, QString("-"),QString("LaMD"));
    laMD->black();
    laMD->move(sizeT*nT-sizeT/4,10);
    nT+=2;

    Touche* domD = new Touche(this, QString("_"),QString("DomD"));
    domD->black();
    domD->move(sizeT*nT-sizeT/4,10);
    nT+=1;
    Touche* remD = new Touche(this, QString("ç"),QString("RémD"));
    remD->black();
    remD->move(sizeT*nT-sizeT/4,10);
    nT+=2;
    Touche* famD = new Touche(this, QString(")"),QString("FamD"));
    famD->black();
    famD->move(sizeT*nT-sizeT/4,10);
    nT+=1;
    Touche* solmD = new Touche(this, QString("="),QString("SolmD"));
    solmD->black();
    solmD->move(sizeT*nT-sizeT/4,10);
    nT+=1;
    Touche* lamD = new Touche(this, QString("back"),QString("LamD"));
    lamD->black();
    lamD->move(sizeT*nT-sizeT/4,10);





     QObject::connect(dom, SIGNAL(clicked()), this, SLOT(play_dom()));
     QObject::connect(rem, SIGNAL(clicked()), this, SLOT(play_rem()));
     QObject::connect(mim, SIGNAL(clicked()), this, SLOT(play_mim()));
     QObject::connect(fam, SIGNAL(clicked()), this, SLOT(play_fam()));
     QObject::connect(solm, SIGNAL(clicked()), this, SLOT(play_solm()));
     QObject::connect(lam, SIGNAL(clicked()), this, SLOT(play_lam()));
     QObject::connect(sim, SIGNAL(clicked()), this, SLOT(play_sim()));

     QObject::connect(doM, SIGNAL(clicked()), this, SLOT(play_doM()));
     QObject::connect(reM, SIGNAL(clicked()), this, SLOT(play_reM()));
     QObject::connect(miM, SIGNAL(clicked()), this, SLOT(play_miM()));
     QObject::connect(faM, SIGNAL(clicked()), this, SLOT(play_faM()));
     QObject::connect(solM, SIGNAL(clicked()), this, SLOT(play_solM()));
     QObject::connect(laM, SIGNAL(clicked()), this, SLOT(play_laM()));
     QObject::connect(siM, SIGNAL(clicked()), this, SLOT(play_siM()));

     QObject::connect(domD, SIGNAL(clicked()), this, SLOT(play_domD()));
     QObject::connect(remD, SIGNAL(clicked()), this, SLOT(play_remD()));

     QObject::connect(famD, SIGNAL(clicked()), this, SLOT(play_famD()));
     QObject::connect(solmD, SIGNAL(clicked()), this, SLOT(play_solmD()));
     QObject::connect(lamD, SIGNAL(clicked()), this, SLOT(play_lamD()));

     QObject::connect(doMD, SIGNAL(clicked()), this, SLOT(play_doMD()));
     QObject::connect(reMD, SIGNAL(clicked()), this, SLOT(play_reMD()));

     QObject::connect(faMD, SIGNAL(clicked()), this, SLOT(play_faMD()));
     QObject::connect(solMD, SIGNAL(clicked()), this, SLOT(play_solMD()));
     QObject::connect(laMD, SIGNAL(clicked()), this, SLOT(play_laMD()));

}
 void Piano::play_dom(){
     QSound::play("../son/dom.wav");
 }
 void Piano::play_rem(){
     QSound::play("../son/rem.wav");
 }
 void Piano::play_mim(){
     QSound::play("../son/mim.wav");
 }
 void Piano::play_fam(){
     QSound::play("../son/fam.wav");
 }
 void Piano::play_solm(){
     QSound::play("../son/solm.wav");
 }
 void Piano::play_lam(){
     QSound::play("../son/lam.wav");
 }
 void Piano::play_sim(){
     QSound::play("../son/sim.wav");
 }


 void Piano::play_doM(){
     QSound::play("../son/doM.wav");
 }
 void Piano::play_reM(){
     QSound::play("../son/reM.wav");
 }
 void Piano::play_miM(){
     QSound::play("../son/miM.wav");
 }
 void Piano::play_faM(){
     QSound::play("../son/faM.wav");
 }
 void Piano::play_solM(){
     QSound::play("../son/solM.wav");
 }
 void Piano::play_laM(){
     QSound::play("../son/laM.wav");
 }
 void Piano::play_siM(){
     QSound::play("../son/siM.wav");
 }

 void Piano::play_domD(){
     QSound::play("../son/domD.wav");
 }
 void Piano::play_remD(){
     QSound::play("../son/remD.wav");
 }
 void Piano::play_famD(){
     QSound::play("../son/famD.wav");
 }
 void Piano::play_solmD(){
     QSound::play("../son/solmD.wav");
 }
 void Piano::play_lamD(){
     QSound::play("../son/lamD.wav");
 }

 void Piano::play_doMD(){
     QSound::play("../son/doMD.wav");
 }
 void Piano::play_reMD(){
     QSound::play("../son/reMD.wav");
 }
 void Piano::play_faMD(){
     QSound::play("../son/faMD.wav");
 }
 void Piano::play_solMD(){
     QSound::play("../son/solMD.wav");
 }
 void Piano::play_laMD(){
     QSound::play("../son/laMD.wav");
 }




