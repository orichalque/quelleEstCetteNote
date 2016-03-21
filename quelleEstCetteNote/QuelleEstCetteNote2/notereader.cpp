#include "notereader.h"
#include <QVector>
using namespace std;

NoteReader::NoteReader()
{
}

QVector<QString> NoteReader::readNotes(QString fileName){
   QVector<QString> notes;
   QFile file(fileName);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

       return notes;
   }


   QTextStream in(&file);
   while (!in.atEnd())
   {
      QString line = in.readLine(); //read one line at a time
      if (line != "\n"){
        notes.push_back(line);
      }

   }
   file.close();
   return notes;
}
