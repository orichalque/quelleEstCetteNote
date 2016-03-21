//#include "mainwindow.h"
//#include <QSpacerItem>
#include <iostream>
#include <QApplication>
#include "piano.h"
#include "portee.h"
#include <QLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QPalette>
#include <QToolBar>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QKeySequence>
#include <QProcess>
#include <QDesktopServices>
#include <QDir>
#include <QUrl>

using namespace std;

QString fileNameToPlay;
Portee *po;
Piano *pi;


void setElise(){
    fileNameToPlay = ":/new/prefix1/part_lettre_elise.txt";

    if (po != NULL){
        po -> setFileName(fileNameToPlay);
        po -> update();
    }
    if (po -> piano != NULL){
        po -> piano -> notes_jouees->clear();
        po -> piano -> notes_jouees = new QVector<QString>();
    }
}

void setBoyard(){
    fileNameToPlay = ":/new/prefix1/part_fort_boyard";
    if (po != NULL){
        po->setFileName(fileNameToPlay);
        po -> update();
    }
    if (po -> piano != NULL){
        po -> piano -> notes_jouees->clear();
        po -> piano -> notes_jouees = new QVector<QString>();
    }
}

void setNooby(){
    fileNameToPlay = ":/new/prefix1/crescendo";
    if (po != NULL){
        po->setFileName(fileNameToPlay);
        po -> update();
    }
    if (po -> piano != NULL){
        po -> piano -> notes_jouees->clear();
        po -> piano -> notes_jouees = new QVector<QString>();
    }
}

void openExplorer(){
    QString path = QDir::toNativeSeparators(QApplication::applicationDirPath());
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));

    // Get Part File name

    fileNameToPlay = ":/new/prefix1/part_lettre_elise.txt";
}

void addMenus(QWidget *w){
    // QToolBar *tb ;
      QMenu *file = new QMenu("Fichier", 0);
      QMenuBar *menubar;
      menubar = new QMenuBar(w);


      QAction *open = new QAction("Ouvrir", 0);
      QAction *mode = new QAction("Mode libre", 0);
      QAction *quit = new QAction("Quitter", 0);
      QAction *stats = new QAction("Historique des scores", 0);

      quit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
      open -> setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));

      w->connect(quit, SIGNAL(triggered()), w, SLOT(close()));
      w->connect(open, &QAction::triggered, openExplorer);

      file->addAction(open);
      file->addAction(mode);
      file->addAction(stats);
      file->addAction(quit);

      QMenu*part = new QMenu("Partition", 0);
      QAction *elise = new QAction("Lettre à Elise", 0);
      QAction *fort = new QAction("Fort Boyard", 0);
      QAction *noob = new QAction("Initiation", 0);

      w -> connect(elise, &QAction::triggered, setElise);
      w -> connect(fort, &QAction::triggered, setBoyard);
      w -> connect(noob, &QAction::triggered, setNooby);

      part->addAction(elise);
      part->addAction(noob);
      part->addAction(fort);

      menubar->addMenu(file);
      menubar->addMenu(part);

      menubar->show();
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QWidget w;

    w.setFixedSize(800, 720);

    // set color background
    QPalette Pal(w.palette());
    Pal.setColor(QPalette::Background, QColor::fromRgb(250, 250, 250));
    w.setAutoFillBackground(true);
    w.setPalette(Pal);


    po = new Portee(&w);
    Piano *pi = new Piano(&w);
    po->setPiano(pi);

    addMenus(&w);
    QVBoxLayout qvbox;
    qvbox.addWidget(po);
    qvbox.addWidget(pi);
    w.setLayout(&qvbox);

    w.show();

    return a.exec();
}
