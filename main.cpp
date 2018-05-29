#include "mainwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
<<<<<<< HEAD
    w.goto_ufunction_window(true);
=======
    w.show();
>>>>>>> aa09449a1e54c3a87b7e39f888a931630f0a2e52
    return a.exec();
}
