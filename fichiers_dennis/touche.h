#ifndef TOUCHE_H
#define TOUCHE_H
#include <QPushButton>
#include <QString>
class Touche :/*public  QWidget,*/ public QPushButton
{
public:
    Touche(QWidget *parent, QString  raccourci=QStringLiteral("rac"), QString note=QStringLiteral("note"));
    QString getNote();
    bool keyPressEvent(QEvent * e);
    bool hitButton(const QPoint & pos) const;
    void black();
signals:
    //void clicked(Touche note);
    void signal_play();
private:
    QString racc;
    QString note;

public slots:
    void on__play();
};

#endif // TOUCHE_H
