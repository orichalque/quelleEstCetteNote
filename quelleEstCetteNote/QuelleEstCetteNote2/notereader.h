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
    NoteReader();
    QVector<QString> readNotes(QString fileName);
};

#endif // NOTEREADER_H
