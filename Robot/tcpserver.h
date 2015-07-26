#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QObject>
#include "tcpsocket.h"

class TcpServer : public QTcpServer
{
        Q_OBJECT
    public:
        TcpServer(QObject *parent=0,int port=0);
        ~TcpServer();


        void sendData(QString msg, int length);

    signals:
        void receiveDataSource(QString,int);
    public slots:
        void receiveData(QString,int);
        void slotDisconnected(int);
    protected:
        void incomingConnection(int socketDescriptor);
    private:
        QList<TcpSocket*> tcpSocketList;

};

#endif // TCPSERVER_H
