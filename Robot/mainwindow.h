#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QProcess>
#include <QtDebug>
#include <QTimer>
#include <QFileDialog>

#include "tcpserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void receiveData(QString,int);

private slots:
    void on_btnMoreMessage_clicked();
    void pingTimeOut();
    void on_pushButton_clicked();

    void on_btnRemoteDown_clicked();

    void on_bthOrder_clicked();

    void sendData(QString msg, int length);

signals:
    void sendDataSource(QString msg,int length);

private:
    Ui::MainWindow *ui;
    TcpServer *tcpserver;
    int port;

    QString pingNet;//这里两个实现ping值实时保持功能。
    QString ping;

    QString companyWebAddress;
protected:
    void getHostInformation();
    void getPing();

};

#endif // MAINWINDOW_H
