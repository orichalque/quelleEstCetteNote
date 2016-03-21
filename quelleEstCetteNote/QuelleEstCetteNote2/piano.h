/**
 * \file piano.h
 * \brief contient la Classe Piano hérité de QWidget.
 * Comprend toutes les touches du piano + les options relatives au piano.
 * \author Dennis Bordet (surtout)
 * \author Thibault Béziers la Fosse (un peu)
 * @bug L'affichage du score est buggy
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
    
    /**
     * @brief Affiche le message de fin de portée, avec le score de l'utilisateur
     * @return 1 si le joueur recommence, 0 s'il quitte
     */
    int scoreMsg();
    
    /**
     * @brief Mutex indiquant si la fenetre des scores est actuellement montrée ou non
     * @return vrai si la fenetre est présente, faux sinon
     */
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
    
    /**
     * @brief Contient le nombre de notes bien jouées par l'utilisateur
     */
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
    
    /**
     * \brief joue re do aigu
     */
    void play_rem();
    
    /**
     * \brief joue un mi aigu
     */
    void play_mim();
    
    /**
     * \brief joue un fa aigu
     */
    void play_fam();
    
    /**
     * \brief joue un sol aigu
     */
    void play_solm();
    
    /**
     * \brief joue un la aigu
     */
    void play_lam();
    
    /**
     * \brief joue un si aigu
     */
    void play_sim();
    

    /**
     * \brief joue un do grave
     */
    void play_doM();
    
    /**
     * \brief joue un re grave
     */
    void play_reM();
    
    /**
     * \brief joue un mi grave
     */
    void play_miM();
    
    /**
     * \brief joue un fac grave
     */
    void play_faM();
    
    /**
     * \brief joue un sol grave
     */
    void play_solM();
    
    /**
     * \brief joue un la grave
     */
    void play_laM();
    
    /**
     * \brief joue un si grave
     */
    void play_siM();
    
    
    /**
     * \brief joue un do aigu diese
     */    
    void play_domD();
    
    /**
     * \brief joue un re aigu diese
     */
    void play_remD();
    
    /**
     * \brief joue un fa aigu diese
     */
    void play_famD();
    
    /**
     * \brief joue un sol aigu diese
     */
    void play_solmD();
    
    /**
     * \brief joue un la aigu diese
     */
    void play_lamD();
    
    /**
     * \brief joue un do grave diese
     */
    void play_doMD();
    
    /**
     * \brief joue un re grave diese
     */
    void play_reMD();
    
    /**
     * \brief joue un fa grave diese
     */
    void play_faMD();
    
    /**
     * \brief joue un sol grave diese
     */
    void play_solMD();
    
    /**
     * \brief joue un la grave diese
     */
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
