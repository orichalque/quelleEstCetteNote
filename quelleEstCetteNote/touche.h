#ifndef TOUCHE_H
#define TOUCHE_H
#include <QPushButton>
#include <QString>
class Touche :/*public  QWidget,*/ public QPushButton
{
public:
    Touche(QWidget *parent, QString  raccourci=QStringLiteral("rac"), QString note=QStringLiteral("note"));

public slots:
    void on_clicked();
    void on_released();
};

#endif // TOUCHE_H
