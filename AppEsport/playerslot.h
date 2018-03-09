#ifndef PLAYERSLOT_H
#define PLAYERSLOT_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include "advancedbutton.h"

class PlayerSlot : public QWidget
{
public:
    PlayerSlot(QWidget *parent = Q_NULLPTR, int _id, QString _name, QString _team);

private:
    int             id;
    QString         name;
    QString         team;
    QLabel          *background;
    QLabel          *textString;
    QLabel          *mana;
    AdvancedButton  *erase;

private slots:


};

#endif // PLAYERSLOT_H
