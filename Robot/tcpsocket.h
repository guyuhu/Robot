#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>
#include <QObject>
#include "protocolfromclient2server.h"
#include "jsonfromclient2server.h"
class TcpSocket : public QTcpSocket
{
    Q_OBJECT

    public:
        TcpSocket(QObject *parent=0);
        ~TcpSocket();
    private:
        ProtocolFromClient2Server protocolFromClient2Server;
        JsonFromClient2Server jsonFromClient2Server;
    signals:
        void updateClients(ProtocolFromClient2Server);
        void disconnected(int);
    protected slots:
        void dataReceived();
        void slotDisconnected();
};

#endif // TCPSOCKET_H
