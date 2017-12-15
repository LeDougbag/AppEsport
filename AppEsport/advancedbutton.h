#ifndef ADVANCEDBUTTON_H
#define ADVANCEDBUTTON_H

#include <QPushButton>
#include <QLabel>
#include <QSound>
#include <QEvent>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QTimer>
#include <iostream>

#define MAX_SIZE_RATIO 1.08
#define NORMAL_RATIO 1.0

class AdvancedButton : public QPushButton
{
    Q_OBJECT

public:
    AdvancedButton(QWidget *parent);

    void        setPixmap(QPixmap *pix);
    void        setFixedSize(int w, int h);
    void        setText(const QString &text);
    void        move(int x, int y);

    void        setDefaultPix(const QString &path);
    void        setClicPix(const QString &path);
    void        setHoverPix(const QString &path);

    void        setClicSound(const QString &path);
    void        setHoverSound(const QString &path);

    void        updateButtonResize();

protected:
    void        mouseMoveEvent(QMouseEvent *e);
    void        mousePressEvent(QMouseEvent *e);
    void        mouseReleaseEvent(QMouseEvent *e);
    void        enterEvent(QEvent *e);
    void        leaveEvent(QEvent *e);

private:
    void        updateAnimationStatus();
    void        hoverResize(int w, int h);
    void        hoverMove(int x, int y);

    QTimer      *updateTimer;

    QPoint      mouseLocalPos;
    QPoint      mouseAbsPos;
    QLabel      *background;
    QLabel      *textLabel;

    QPixmap     basicDefaultPix;
    QPixmap     basicHoverPix;
    QPixmap     basicClicPix;

    QPixmap     defaultPix;
    QPixmap     hoverPix;
    QPixmap     clicPix;

    QSize       savedSize;
    QSize       savedPos;

    bool        clicPixSet;
    bool        onTheZone;
    bool        hasHover;
    bool        hasClicSound;
    bool        hasHoverSound;
    bool        hoverMod;
    bool        onHover;
    double      ratio;
    int         enter;
    int         leave;

    QSound      *hoverSound;
    QSound      *clicSound;

public slots:
    void        update();
};

#endif // ADVANCEDBUTTON_H
