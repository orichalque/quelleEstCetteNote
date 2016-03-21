#ifndef PIANO_H
#define PIANO_H

#include <QWidget>
#include "touche.h"
#include <QSound>
#include <QMessageBox>
#include <QVector>


class Piano : public QWidget
{
    Q_OBJECT
public:
    explicit Piano(QWidget *parent = 0);
    QVector<QString> *notes_jouees;
    QVector<bool>* comparaison(QVector<QString> *partition);
    int scoreMsg();
    bool showing;

signals:
    void played();

private:
    QVector<Touche*> *notes;
    bool b_racc_disp;
    bool b_names_dip;
    int nbOfSuccess;

public slots:
    void retour_arriere();
    void play_dom();
    void play_rem();
    void play_mim();
    void play_fam();
    void play_solm();
    void play_lam();
    void play_sim();

    void play_doM();
    void play_reM();
    void play_miM();
    void play_faM();
    void play_solM();
    void play_laM();
    void play_siM();

    void play_domD();
    void play_remD();

    void play_famD();
    void play_solmD();
    void play_lamD();

    void play_doMD();
    void play_reMD();

    void play_faMD();
    void play_solMD();
    void play_laMD();
    void display_racc();
    void display_names();
    void checking(bool checked);

};

#endif // PIANO_H
