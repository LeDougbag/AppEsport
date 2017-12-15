#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include "advancedbutton.h"
#include "tournamentcreation.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QLabel              *background;
    QLabel              *title;
    QLabel              *emptyButton;

    AdvancedButton      *creerTournois;
    TournamentCreation  *tournament;

public slots:
    void    newTournament();
};

#endif // MAINWINDOW_H
