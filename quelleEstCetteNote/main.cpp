#include "mainwindow.h"
#include <QApplication>
#include "touche.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString aa ="A";
    QString b = "Ré";
    QPushButton* bouton = new Touche(aa, b);
    bouton->show();
    //w.show();
    return a.exec();
}
