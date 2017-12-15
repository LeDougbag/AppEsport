#ifndef TOURNAMENTCREATION_H
#define TOURNAMENTCREATION_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <iostream>
#include <QScrollArea>
#include "advancedbutton.h"

class TournamentCreation : public QWidget
{
    Q_OBJECT
public:
    explicit TournamentCreation(QWidget *parent = nullptr);

private:
    QLabel          *background;
    QLineEdit       *player;
    QLineEdit       *team;

    QLabel          *emptyButton;
    AdvancedButton  *addPlayer;

    QScrollArea     *scrollArea;
    QLabel          *scrollBackground;

public slots:
    void    confirmPlayer();
};

#endif // TOURNAMENTCREATION_H
