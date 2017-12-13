#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*this->setFixedSize(1600, 900);

    btn = new QPushButton(this);
    btn->setFixedSize(300, 100);
    btn->setStyleSheet("background-color: red;"
                       "qproperty-alignment: AlignCenter;");
    btn->move(200, 200);
    btn->setText("hello");

    lab = new QLabel(this);
    lab->move(500, 500);
    lab->setFixedSize(200, 200);

    QPixmap pix("../images/Missile Soviet.png");
    pix = pix.scaled(QSize(lab->width(), lab->height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    lab->setPixmap(pix);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
