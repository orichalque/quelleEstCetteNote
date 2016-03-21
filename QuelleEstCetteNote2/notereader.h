/** @file notereader.h
 *  @brief Classe utilisée pour lire un fichier de notes et créer un vector 
 *
 *  @author Thibault Béziers la Fosse
 *  @author Dennis Bordet
 *  @bug No known bugs.
 */

#ifndef NOTEREADER_H
#define NOTEREADER_H
#include<vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>

class NoteReader
{
public:
    /**
     * @brief Constructor empty
     */
    NoteReader();
    
    /** 
     * @brief Ouvre un fichier et le lit, et stocke ses données dans un QVector 
     * @param fileName le nom du fichier
     * @return QVector<QString> Contenant les notes
     */
    QVector<QString> readNotes(QString fileName);
};

#endif // NOTEREADER_H
