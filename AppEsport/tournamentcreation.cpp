#include "tournamentcreation.h"

TournamentCreation::TournamentCreation(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(parent->width(), parent->height());

    QPixmap pix("../images/background.png");

    background = new QLabel(this);
    background->setFixedSize(pix.width(), pix.height());
    background->setPixmap(pix);

    player = new QLineEdit(this);
    player->setFixedSize(400, 70);
    player->move(200, 300);
    player->setFont(QFont("Arial", 25, QFont::Bold));
    player->setStyleSheet("background-color: transparent;");

    team = new QLineEdit(this);
    team->setFixedSize(400, 70);
    team->move(700, 300);
    team->setFont(QFont("Arial", 25, QFont::Bold));
    team->setStyleSheet("background-color: transparent;");

    btn = new QPushButton(this);
    btn->setFixedSize(200, 70);
    btn->move(1200, 300);
    btn->setText("Valider");

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(confirmPlayer()));
}

void    TournamentCreation::confirmPlayer()
{
    std::cout << "Player " << player->text().toStdString() << " in the team " << team->text().toStdString() << " added." << std::endl;
    player->clear();
    team->clear();
}
