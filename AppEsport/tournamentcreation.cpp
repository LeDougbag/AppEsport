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
    player->move(200, 180);
    player->setFont(QFont("Arial", 25, QFont::Bold));
    player->setStyleSheet("background-color: transparent;");

    team = new QLineEdit(this);
    team->setFixedSize(400, 70);
    team->move(700, 180);
    team->setFont(QFont("Arial", 25, QFont::Bold));
    team->setStyleSheet("background-color: transparent;");

    QPixmap ebutton("../images/bouton vide.png");
    ebutton = ebutton.scaled(QSize(ebutton.width() / 2, ebutton.height() / 2), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    emptyButton = new QLabel(this);
    emptyButton->setFixedSize(ebutton.width(), ebutton.height());
    emptyButton->move(1200, 180);
    emptyButton->setPixmap(ebutton);

    addPlayer = new AdvancedButton(this);
    addPlayer->setFixedSize(ebutton.width(), ebutton.height());
    addPlayer->move(1200, 180);
    addPlayer->setDefaultPix("../images/bouton ajouter joueur.png");
    addPlayer->setHoverPix("../images/bouton ajouter joueur.png");

    scrollArea = new QScrollArea(this);
    scrollArea->setFixedSize(1200, 400);
    scrollArea->move(200, 350);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    scrollBackground = new QLabel(scrollArea);
    scrollBackground->setFixedSize(1180, 1200);
    QPixmap fap("../images/fap.jpg");
    fap = fap.scaled(QSize(scrollBackground->width(), scrollBackground->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    scrollBackground->setPixmap(fap);

    scrollArea->setWidget(scrollBackground);

    connect(addPlayer, SIGNAL(clicked(bool)), this, SLOT(confirmPlayer()));
}

void    TournamentCreation::confirmPlayer()
{
    std::cout << "Player " << player->text().toStdString() << " in the team " << team->text().toStdString() << " added." << std::endl;
    player->clear();
    team->clear();
}
