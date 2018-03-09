#ifndef PLAYERSLOT_H
#define PLAYERSLOT_H

#include <QWidget>
#include <QString>
#include <QLabel>

class PlayerSlot : public QWidget
{
public:
    PlayerSlot(QWidget *parent = Q_NULLPTR);

private:

    int     id;
    QString name;
    QString team;
    QLabel  *background;

private slots:

};

#endif // PLAYERSLOT_H
