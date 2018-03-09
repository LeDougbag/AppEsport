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
    player->setFont(QFont("OPTIBelwe-Medium", 25, QFont::Bold));
    player->setStyleSheet("background-color: transparent;");

    team = new QLineEdit(this);
    team->setFixedSize(400, 70);
    team->move(700, 180);
    team->setFont(QFont("OPTIBelwe-Medium", 25, QFont::Bold));
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

    /*scrollArea = new QScrollArea(this);
    scrollArea->setFixedSize(1200, 400);
    scrollArea->move(200, 350);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    scrollBackground = new QLabel(scrollArea);
    scrollBackground->setFixedSize(100, 100);
    QPixmap fap("../images/fap.jpg");
    fap = fap.scaled(QSize(scrollBackground->width(), scrollBackground->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    scrollBackground->setPixmap(fap);

    testGrid = new QLabel(scrollArea);
    testGrid->setFixedSize(100, 100);
    testGrid->setPixmap(fap);

    grid = new QGridLayout(scrollArea);
    grid->setVerticalSpacing(1000);
    grid->setHorizontalSpacing(1000);
    //grid->SetFixedSize(scrollArea->width(), scrollArea->height());
    grid->addWidget(scrollBackground, 1, 1);
    grid->addWidget(testGrid, 4, 1);*/

    //scrollArea->setWidget(scrollBackground);

    scrollWidget = new QWidget;
    scrollWidget->setFixedSize(1200, 300);

    /*scrollBackground = new QLabel(scrollWidget);
    QImage image("../images/BackgroundTest.png");
    image = image.scaled(QSize(1200, 1000), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    scrollBackground->setPixmap(QPixmap::fromImage(image));*/

    scrollArea = new QScrollArea(this);
    scrollArea->setFixedSize(1220, 400);
    scrollArea->move(200, 350);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(addPlayer, SIGNAL(clicked(bool)), this, SLOT(confirmPlayer()));
}

void    TournamentCreation::updateScrollArea()
{
    scrollWidget = new QWidget;
    scrollWidget->setFixedSize(1200, playerList.count() * 70);
    //scrollBackground->setParent(scrollWidget);

    int pos = 0;

    for (int i = 0; i < playerList.count(); i++)
    {
        QLabel *temp = new QLabel;// = new QLabel(scrollWidget);
        temp = playerList.at(i);
        temp->setParent(scrollWidget);
        temp->move(0, pos);
        pos += 70;
    }

    scrollArea->setWidget(scrollWidget);
}

void    TournamentCreation::confirmPlayer()
{
    QLabel *temp = new QLabel;
    temp->setStyleSheet("background-color: red; border: 1px solid black;");
    temp->setFixedSize(1200, 70);
    temp->setFont(QFont("OPTIBelwe-Medium", 20, QFont::Bold));
    temp->setText("   " + player->text() + " " + team->text());
    playerList.push_back(temp);
    updateScrollArea();

    //qDebug() << "Player " << player->text().toStdString() << " in the team " << team->text().toStdString() << " added.";
    player->clear();
    team->clear();
}
