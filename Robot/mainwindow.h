#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QProcess>
#include <QtDebug>
#include <QTimer>
#include <QFileDialog>
#include <QString>


#include "tcpserver.h"
#include "protocolfromclient2server.h"

#include <QHash>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = 0,QObject *parent);
        explicit MainWindow(QWidget *parent=0);
    ~MainWindow();



private slots:
    void on_btnMoreMessage_clicked();
    void pingTimeOut();
    void on_pushButton_clicked();

    void on_btnRemoteDown_clicked();

    void on_bthOrder_clicked();

    void sendData(QString msg, int length);
    void receiveData(ProtocolFromClient2Server protocolFromClient2Server);//这个接收客户端函数最好是放到槽函数，否则不能显示接收函数。

signals:
    void sendDataSource(QString msg,int length);

private:
    Ui::MainWindow *ui;
    QString companyWebAddress;

    QString pingNet;//这里两个实现ping值实时保持功能。
    QString ping;
    TcpServer *tcpserver;
    QHash<QString,int> robotHash;
    int robotNumberOnLine;

    int port;

    ProtocolFromClient2Server protocolFromClient2Server;//这两个对象作为客户端——》服务器端通信接收。

protected:
    void getHostInformation();
    void getPing();
    void showClientMessage();

};

#endif // MAINWINDOW_H
