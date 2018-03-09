#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOverrideCursor(QCursor(QPixmap("../images/Curseur.png")));

    MainWindow w;
    w.setWindowIcon(QIcon(QPixmap("../images/icone.png")));
    w.setWindowTitle("Le super titre de la super application de tournois hearthstone codé par Alessio, ça tourne mal avec un hand spinner explications");
    w.setFixedSize(1600, 900);
    w.show();

    return a.exec();
}
