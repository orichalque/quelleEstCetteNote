#ifndef PIANO_H
#define PIANO_H

#include <QWidget>
#include "touche.h"
#include <QSound>
#include <QMessageBox>

class Piano : public QWidget
{
    Q_OBJECT
public:
    explicit Piano(QWidget *parent = 0);

signals:

public slots:
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

};

#endif // PIANO_H
