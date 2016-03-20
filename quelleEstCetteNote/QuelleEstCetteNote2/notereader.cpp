#include "notereader.h"

using namespace std;

NoteReader::NoteReader()
{
}

vector<QString> NoteReader::readNotes(QString fileName){
    vector<QString> notes;
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
   cout << "Nombre de notes: " << notes.size() << endl;
   file.close();
   return notes;
}
