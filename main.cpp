#include <QtGui/QApplication>
#include "dancewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DanceWindow w;
    w.show();
    return a.exec();
}
