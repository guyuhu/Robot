#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QObject>
#include "tcpsocket.h"
#include "protocolfromclient2server.h"
#include <QHash>
#include <QString>

class TcpServer : public QTcpServer
{
        Q_OBJECT
    public:
        TcpServer(QObject *parent=0,int port=0);
        ~TcpServer();
        void sendData(QString msg, int length);

        QHash<QString,int> getRobotIDHash();
        int  getRobotNumber();

    signals:
        void receiveDataSource(ProtocolFromClient2Server);
    public slots:
        void receiveData(ProtocolFromClient2Server protocolRromClient2Server);
        void slotDisconnected(int);
    protected:
        void incomingConnection(int socketDescriptor);
    private:
        QList<TcpSocket*> tcpSocketList;
        QHash<QString,int> robotIDHash;
       // QHash<TcpSocket*,int> tcpHash;
        int robotIDValue;
        int robotNumber;
};

#endif // TCPSERVER_H
