#ifndef PLAYERSLOT_H
#define PLAYERSLOT_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include "advancedbutton.h"

class PlayerSlot : public QWidget
{
public:
    PlayerSlot(int _id, QString _name, QString _team);
    PlayerSlot(PlayerSlot* const&player);

private:
    int             id;
    QString         name;
    QString         team;
    QLabel          *nameLabel;
    QLabel          *teamLabel;
    QLabel          *background;
    QLabel          *textString;
    QLabel          *mana;
    AdvancedButton  *erase;

private slots:


};

#endif // PLAYERSLOT_H
