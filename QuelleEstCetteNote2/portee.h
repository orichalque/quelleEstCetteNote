/**
 * \file portee.h
 * \brief Contient la classe portée dérivée de QWidget défini la portée.
 * \author Thibault Béziers la Fosse (Surtout)
 * \author Dennis Bordet (Un peu)
 * @bug L'affichage des notes sur une portée est décallé. Fonctionne bien au dessus de 14 notes
 */
#ifndef PORTEE_H
#define PORTEE_H
#include <QWidget>
#include <vector>
#include <QVector>
#include "notereader.h"
#include "piano.h"

/**
 * @class Portee
 * @brief défini la portée, l'affichage des notes et leur correction, ainsi que le curseur d'avancement
 */
class Portee : public QWidget
{
public:
    /**
     * @brief Constructor
     */
    Portee();
    /**
     * @brief Constructor hérité du QWidget
     * @param parent
     */
    explicit Portee(QWidget *parent = 0);
    
    /**
     * @brief Défini le piano qui correspond à la portée
     * @param p le pointeur vers le piano défini dans le main
     */
    void setPiano(Piano* p);
    
    /**
     * @brief Le pointeur vers le piano. Public pour simplifier l'accès depuis le main
     */
    Piano* piano;
    
    /**
     * @brief Fonction principale, affiche la portée, les notes, le curseur, avec QPainter et QImages
     * @param event
     */
    void paintEvent(QPaintEvent * event);
    
    /**
     * @brief Choisi le nom du fichier qui contient la partition
     * Permet de le lire en affichant, dans le paintEvent
     * @param fn le nom du fichier
     */
    void setFileName(QString fn);
    
    /**
     * @brief Contient les résultats issue de la fonction comparaison de Piano. Vrai si la note est bein jouée, faux sinon
     */
    QVector<bool> result;
    
    /**
     * @brief Remet à 0 le curseur si le joueur change de partition ou recommence
     */
    void reset();
protected:
    /**
     * @brief Nom du fichier à lire pour la partition
     */
    QString fileName;
    
    /**
     * @brief Vrai quand on veut afficher les notes vertes, faux sinon
     */
    bool modeCorrect;
    
    /**
     * @brief Affiche le score. On prefère la methode de Piano
     * @deprecated
     */
    void scoreMsg();

signals:
    /**
     * @brief Signal qui dit à piano d'afficher la boite avec le score
     * @deprecated
     */
    void callBox();

public slots:
    /**
     * @brief Pour rafraichir le QPainter
     */
    void refresh();
};

#endif // PORTEE_H
