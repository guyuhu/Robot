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

        QList<TcpSocket*> tcpSocketList;
    signals:
        void updateServer(QString,int);
    public slots:
        void updateClients(QString,int);
        void slotDisconnected(int);
    protected:
        void incomingConnection(int socketDescriptor);
};

#endif // TCPSERVER_H
