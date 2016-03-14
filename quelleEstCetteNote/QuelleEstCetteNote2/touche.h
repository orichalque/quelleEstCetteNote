#ifndef TOUCHE_H
#define TOUCHE_H
#include <QPushButton>
#include <QString>


class Touche :/*public  QWidget,*/ public QPushButton
{
public:
    Touche(QWidget *parent, QString  raccourci=QString("rac"), QString note=QString("note"));
    QString getNote();
    //bool hitButton(const QPoint & pos) const;
    void black();

private:
    QString racc;
    QString note;

public slots:
};

#endif // TOUCHE_H
