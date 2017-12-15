#include "advancedbutton.h"

AdvancedButton::AdvancedButton(QWidget *parent = 0) : QPushButton(parent)
{
    this->setStyleSheet("background-color:transparent;");
    hasHoverSound = false;
    hasClicSound = false;
    clicPixSet = false;
    onTheZone = false;
    hasHover = false;
    hoverMod = false;
    onHover = false;
    mouseLocalPos = QPoint(0,0);
    mouseAbsPos = QPoint(0,0);
    enter = 0;
    leave = 0;
    ratio = 1.0;
    savedSize = QSize(this->width(), this->height());
    savedPos = QSize(this->x(), this->y());

    basicDefaultPix.load("../images/blue.png");
    basicDefaultPix = basicDefaultPix.scaled(QSize(this->width(), this->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    basicClicPix.load("../images/blue.png");
    basicClicPix = basicClicPix.scaled(QSize(this->width(), this->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    background = new QLabel(this);
    background->setFixedSize(this->width(), this->height());
    background->setPixmap(basicDefaultPix);
    background->show();

    textLabel = new QLabel(this);
    textLabel->setFixedSize(this->width(), this->height());
    textLabel->setStyleSheet("qproperty-alignment: AlignCenter;");

    updateTimer = new QTimer(this);
    updateTimer->start(16);

    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
}

void    AdvancedButton::setFixedSize(int w, int h)
{
    QPushButton::setFixedSize(w, h);

    defaultPix = basicDefaultPix.scaled(QSize(w, h), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    clicPix = basicClicPix.scaled(QSize(w, h), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    if (hasHover)
        hoverPix = basicHoverPix.scaled(QSize(w, h), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    background->setFixedSize(w, h);
    textLabel->setFixedSize(w, h);

    background->setPixmap(defaultPix);
    savedSize = QSize(w, h);
}

void    AdvancedButton::move(int x, int y)
{
    QPushButton::move(x, y);
    savedPos = QSize(x, y);
}

void    AdvancedButton::mousePressEvent(QMouseEvent *e)
{
    onTheZone = false;

    if (e->pos().x() < 0 || e->pos().y() < 0 || e->pos().x() > defaultPix.width() || e->pos().y() > defaultPix.height())
    {
        return;
    }

    QColor    transparent(0,0,0,0);
    QColor    rgb = defaultPix.toImage().pixel(e->pos());

    if (!(rgb.redF() == transparent.redF()) && !(rgb.greenF() == transparent.greenF()) && !(rgb.blueF() == transparent.blueF()))
    {
        QPushButton::mousePressEvent(e);
        background->setPixmap(clicPix);
        onTheZone = true;
    }
}

void    AdvancedButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (mouseLocalPos.x() > 0 && mouseLocalPos.x() < this->width() && mouseLocalPos.y() > 0 && mouseLocalPos.y() < this->height() && onTheZone == true)
    {
        QPushButton::mouseReleaseEvent(e);
        if (hasClicSound)
            clicSound->play();
        this->releaseMouse();
    }
    else
    {
        this->releaseMouse();
    }
    background->setPixmap(defaultPix);
}

void    AdvancedButton::enterEvent(QEvent *e)
{
    Q_UNUSED(e);
    this->grabMouse();
    this->setMouseTracking(true);
}

void    AdvancedButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e);
    this->releaseMouse();
    this->setMouseTracking(false);
}

void    AdvancedButton::mouseMoveEvent(QMouseEvent *e)
{
    mouseAbsPos = e->globalPos();
    mouseLocalPos = e->pos();
}

void    AdvancedButton::setDefaultPix(const QString &path)
{
    basicDefaultPix.load(path);
    defaultPix = basicDefaultPix.scaled(QSize(this->width(), this->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    if (!clicPixSet)
    {
        basicClicPix.load(path);
        clicPix = basicClicPix.scaled(QSize(this->width(), this->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    background->setPixmap(defaultPix);
}

void    AdvancedButton::setClicPix(const QString &path)
{
    clicPixSet = true;
    basicClicPix.load(path);
    clicPix = basicClicPix.scaled(QSize(this->width(), this->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void    AdvancedButton::setHoverPix(const QString &path)
{
    basicHoverPix.load(path);
    hoverPix = basicHoverPix.scaled(QSize(this->width(), this->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    hasHover = true;
}

void    AdvancedButton::setClicSound(const QString &path)
{
    clicSound = new QSound(path, this);
    hasClicSound = true;
}

void    AdvancedButton::setHoverSound(const QString &path)
{
    hoverSound = new QSound(path, this);
    hasHoverSound = true;
}

void    AdvancedButton::setText(const QString &text)
{
    textLabel->setText(text);
}

void    AdvancedButton::hoverResize(int w, int h)
{
    QPushButton::setFixedSize(w, h);

    defaultPix = basicDefaultPix.scaled(QSize(w, h), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    clicPix = basicClicPix.scaled(QSize(w, h), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    if (hasHover)
        hoverPix = basicHoverPix.scaled(QSize(w, h), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    background->setFixedSize(w, h);
    textLabel->setFixedSize(w, h);

    background->setPixmap(defaultPix);
}

void    AdvancedButton::hoverMove(int x, int y)
{
    QPushButton::move(x, y);
}

void    AdvancedButton::update()
{
    if (hasHover)
    {
        //if the cursor is on the widget
        if ((mouseLocalPos.x() > 0 && mouseLocalPos.x() < this->width()) && (mouseLocalPos.y() > 0 && mouseLocalPos.y() < this->height()))
        {
            //update the button
            if (mouseLocalPos.x() < 0 || mouseLocalPos.y() < 0 || mouseLocalPos.x() > defaultPix.width() || mouseLocalPos.y() > defaultPix.height())
            {
                return;
            }

            updateAnimationStatus();
        }
        else
        {
            //the cursor is not on the widget ----> reduce the size of the image
            hoverMod = false;
            background->setPixmap(defaultPix);
        }
        updateButtonResize();
    }
}

void    AdvancedButton::updateAnimationStatus()
{
    QColor    transparent(0,0,0,0);
    QColor    rgb = defaultPix.toImage().pixel(mouseLocalPos);

    //determines if the cursor is on the clickable image
    if (rgb.redF() == transparent.redF() && rgb.greenF() == transparent.greenF() && rgb.blueF() == transparent.blueF())
    {
        //if no , reduce the size of the image (this action starts when this instuction is executed 2 times in a row)
        enter++;
        leave = 0;
        if (enter == 2)
        {
            hoverMod = false;
            background->setPixmap(defaultPix);
        }
    }
    else
    {
        //if yes , increase the size of the image (this action starts when this instuction is executed 2 times in a row)
        leave++;
        enter = 0;
        if (leave == 2)
        {
            hoverMod = true;
            if (hasHoverSound)
                hoverSound->play();
            background->setPixmap(hoverPix);
        }
    }
}

void    AdvancedButton::updateButtonResize()
{
    if (hoverMod)
    {
        if (ratio < MAX_SIZE_RATIO)
        {
            int width = ((savedSize.width() * ratio) - savedSize.width()) / 2;
            int height = ((savedSize.height() * ratio) - savedSize.height()) / 2;

            this->hoverResize(savedSize.width() * ratio, savedSize.height() * ratio);
            this->hoverMove(savedPos.width() - width, savedPos.height() - height);
            ratio += 0.03;
        }
    }
    else
    {
        if (ratio > NORMAL_RATIO)
        {
            int width = ((savedSize.width() * ratio) - savedSize.width()) / 2;
            int height = ((savedSize.height() * ratio) - savedSize.height()) / 2;

            this->hoverResize(savedSize.width() * ratio, savedSize.height() * ratio);
            this->hoverMove(savedPos.width() - width, savedPos.height() - height);
            ratio -= 0.03;
        }
    }
}
