#include "playerslot.h"

PlayerSlot::PlayerSlot(QWidget *parent = Q_NULLPTR, int _id, QString _name, QString _team) : QWidget(parent)
{
    this->setFixedSize(1200, 70);

    /*QPixmap pix("../images/background.png");

    background = new QLabel(this);
    background->setFixedSize(pix.width(), pix.height());
    background->setPixmap(pix);*/
}
