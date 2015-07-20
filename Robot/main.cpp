#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //这里作为欢迎界面，在载入初始化界面之前，显示一段欢迎动画界面。
    QPixmap pixmap("Welcome.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();

    MainWindow w;
    w.show();

    splash.finish(&w);
    return a.exec();
}
