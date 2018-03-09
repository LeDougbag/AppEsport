#ifndef TOURNAMENTCREATION_H
#define TOURNAMENTCREATION_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <iostream>
#include <QScrollArea>
#include <QGridLayout>
#include "advancedbutton.h"
#include "playerslot.h"

class TournamentCreation : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentCreation(QWidget *parent = nullptr);

private:
    void                updateScrollArea();

    QLabel              *background;
    QLineEdit           *player;
    QLineEdit           *team;

    QLabel              *emptyButton;
    AdvancedButton      *addPlayer;

    QWidget             *scrollWidget;
    QScrollArea         *scrollArea;
    QLabel              *scrollBackground;
    QVector<PlayerSlot *>   playerList;

public slots:
    void                confirmPlayer();
};

#endif // TOURNAMENTCREATION_H
