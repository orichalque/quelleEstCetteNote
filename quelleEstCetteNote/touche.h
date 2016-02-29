#ifndef TOUCHE_H
#define TOUCHE_H
#include <QPushButton>
#include <QString>
class Touche : public QPushButton
{
public:
    Touche(QString  raccourci, QString note);

public slots:
    void on_clicked();
    void on_released();
};

#endif // TOUCHE_H
