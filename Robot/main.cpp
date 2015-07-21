#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QElapsedTimer>
#include <QDateTime>
#include <QtTest/QTest>
#include <QtTest/qtestcase.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //这里作为欢迎界面，在载入初始化界面之前，显示一段欢迎动画界面。
  //  QPixmap pixmap("Welcome.png");
   // QSplashScreen splash(pixmap);
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":resource/picture/Welcome.png"));
    splash->show();

    QTest::qSleep(3000);
    splash->showMessage("程序启动中，可能会花费几秒钟，请耐心等待！",Qt::AlignCenter,Qt::green);
    a.processEvents();

    QTest::qSleep(3000);

    /*
#if 0
    int delayTime=4;
    QElapsedTimer timer;
    timer.start();
    while(timer.elapsed()<(delayTime * 1000))
    {
        a.processEvents();
    }
#endif

#if 0
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        a.processEvents();
    } while (n.secsTo(now)<=4);//4为需要延时的秒数
#endif
*/
    MainWindow w;
    w.show();

    splash->finish(&w);
    return a.exec();
}
