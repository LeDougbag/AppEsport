#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1600, 900);

    QPixmap pix("../images/menu_background.png");

    background = new QLabel(this);
    background->setFixedSize(pix.width(), pix.height());
    background->setPixmap(pix);

    QPixmap logo("../images/logo.png");

    title = new QLabel(this);
    title->setFixedSize(logo.width(), logo.height());
    title->move(this->width() * 0.5 - logo.width() / 2, this->height() * 0.15);
    title->setPixmap(logo);

    QPixmap ebutton("../images/bouton vide.png");

    emptyButton = new QLabel(this);
    emptyButton->setFixedSize(ebutton.width(), ebutton.height());
    emptyButton->move(this->width() * 0.5 - ebutton.width() / 2, this->height() * 0.52);
    emptyButton->setPixmap(ebutton);

    creerTournois = new AdvancedButton(this);
    creerTournois->setFixedSize(emptyButton->width(), emptyButton->height());
    creerTournois->move(this->width() * 0.5 - ebutton.width() / 2, this->height() * 0.52);
    creerTournois->setDefaultPix("../images/bouton creer tournois.png");
    creerTournois->setHoverPix("../images/bouton creer tournois.png");

    connect(creerTournois, SIGNAL(clicked(bool)), this, SLOT(newTournament()));
}

void    MainWindow::newTournament()
{
    tournament = new TournamentCreation(this);
    tournament->show();
}
