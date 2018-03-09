#include "playerslot.h"

PlayerSlot::PlayerSlot(int _id, QString _name, QString _team)
{
    this->setFixedSize(1200, 70);
    this->setFont(QFont("OPTIBelwe-Medium", 20, QFont::Bold));

    id = _id;
    name = _name;
    team = _team;

    QPixmap pix("../images/barre joueur.png");

    background = new QLabel(this);
    background->setFixedSize(pix.width(), pix.height());
    background->setPixmap(pix);

    QPixmap pix2("../images/mana.png");

    mana = new QLabel(this);
    mana->move(10, 0);
    mana->setFixedSize(pix2.width(), pix2.height());
    mana->setPixmap(pix2);

    nameLabel = new QLabel(this);
    nameLabel->move(110, 0);
    nameLabel->setFixedSize(600, 70);
    nameLabel->setFont(QFont("OPTIBelwe-Medium", 20, QFont::Bold));
    nameLabel->setText(name);

    teamLabel = new QLabel(this);
    teamLabel->move(600, 0);
    teamLabel->setFixedSize(600, 70);
    teamLabel->setFont(QFont("OPTIBelwe-Medium", 20, QFont::Bold));
    teamLabel->setText(team);

    QPixmap pix3("../images/croix.png");

    erase = new AdvancedButton(this);
    erase->setFixedSize(pix3.width(), pix3.height());
    erase->move(1120, 0);
    erase->setDefaultPix("../images/croix.png");
    erase->setHoverPix("../images/croix.png");
}

PlayerSlot::PlayerSlot(PlayerSlot * const &player)
{
    id = player->id;
    name = player->name;
    team = player->team;

    QPixmap pix("../images/barre joueur.png");

    background = new QLabel(this);
    background->setFixedSize(pix.width(), pix.height());
    background->setPixmap(pix);

    QPixmap pix2("../images/mana.png");

    mana = new QLabel(this);
    mana->move(10, 0);
    mana->setFixedSize(pix2.width(), pix2.height());
    mana->setPixmap(pix2);

    nameLabel = new QLabel(this);
    nameLabel->move(110, 0);
    nameLabel->setFixedSize(600, 70);
    nameLabel->setFont(QFont("OPTIBelwe-Medium", 20, QFont::Bold));
    nameLabel->setText(name);

    teamLabel = new QLabel(this);
    teamLabel->move(600, 0);
    teamLabel->setFixedSize(600, 70);
    teamLabel->setFont(QFont("OPTIBelwe-Medium", 20, QFont::Bold));
    teamLabel->setText(team);


    QPixmap pix3("../images/croix.png");

    erase = new AdvancedButton(this);
    erase->setFixedSize(pix3.width(), pix3.height());
    erase->move(1120, 0);
    erase->setDefaultPix("../images/croix.png");
    erase->setHoverPix("../images/croix.png");
}
