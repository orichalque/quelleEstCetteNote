/**
 * \file piano.h
 * \brief contient la Classe Piano hérité de QWidget.
 * Comprend toutes les touches du piano + les options relatives au piano.
 * \author Dennis Bordet.
 */
#ifndef PIANO_H
#define PIANO_H

#include <QWidget>
#include "touche.h"
#include <QSound>
#include <QMessageBox>
#include <QVector>

/**
 * \brief Comprend toutes les touches du piano + les options relatives au piano.
 */
class Piano : public QWidget
{
    Q_OBJECT
public:
    /**
     * \brief constructeur qui initialise tous les boutons de la partie basse du programme.
     */
    explicit Piano(QWidget *parent = 0);
    /**
     * \brief tableau des notes jouées par l'utilisateur.
     */
    QVector<QString> *notes_jouees;
    /**
     * \brief fonction comparant le tableau des notes jouées avec un autre passé en paramètre.
     * Concrétement, le tableau passé en paramètre est celui contenant les notes de la partition.
     */
    QVector<bool>* comparaison(QVector<QString> *partition);
    int scoreMsg();
    bool showing;

signals:
  /**
   * \brief signal envoyé a chaque note jouée.
   * il est envoyé à la partition afin de mettre à jour le curseur.
   */
    void played();

private:
  /**
   * \brief tableau des touches, facilite certains traitement groupés.
   */
    QVector<Touche*> *notes;
    /**
     * \brief booleen indiquant si les raccourcis sont affichés sur les touches.
     */
    bool b_racc_disp;
    /**
     * \brief booleen indiquant si les noms de notes sont affichés sur les touches.
     */
    bool b_names_dip;
    int nbOfSuccess;

public slots:
  /**
   * \brief permet d'enlever la dernière note jouée de son tableau et reculer le curseur.
   */
    void retour_arriere();
    
    /**
     * \brief joue un do aigu
     */
    void play_dom();
    void play_rem();
    void play_mim();
    void play_fam();
    void play_solm();
    void play_lam();
    void play_sim();

    /**
     * \brief joue un do grave
     */
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
    
    /**
     * \brief affiche les raccourcis clavier sur le piano.
     */
    void display_racc();
    /**
     * \brief affiche les notes clavier sur le piano.
     */
    void display_names();
    /**
     * \brief affiche/masque les options du piano et le redimensionne en consequence.
     */
    void checking(bool checked);

};

#endif // PIANO_H
