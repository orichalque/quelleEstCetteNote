/**
 * \file touche.h
 * \brief contient la Classe Touche qui correspond à une touche du piano.
 * \author Dennis Bordet.
 */
#ifndef TOUCHE_H
#define TOUCHE_H
#include <QPushButton>
#include <QString>

/**
 * \class Touche.
 * \brief Hérite de QPushButton, représente une touche de piano.
 */
class Touche :/*public  QWidget,*/ public QPushButton
{
public:
    /**
     * \brief constructeur hérité de QPushbutton qui initialise le racourci clavier et le nom sa note associée.
     * Construit une touche de piano (taille, raccourci, nom)
     */
    Touche(QWidget *parent, QString  raccourci=QString("rac"), QString note=QString("note"));
    /*
     * \brief getter donnant le nom de la note associé à la touche.
     */
    QString getNote();
    /**
     * \brief getter donnant le raccourci de la touche.
     */
    QString getRacc();
    //bool hitButton(const QPoint & pos) const;
    
    /**
     * \brief transforme une note blanche (d'origine) en note noire.
     * Redimensionne et colorie différement.
     * change l'attribut blacked.
     */
    void black();
    /**
     * \brief booleen indiquant si une note est noire ou non.
     */
    bool blacked;

private:
  
    QString racc;
    QString note;


public slots:
};

#endif // TOUCHE_H
