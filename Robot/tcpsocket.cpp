#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));

}

TcpSocket::~TcpSocket()
{

}

void TcpSocket::dataReceived()
{
    while(bytesAvailable()>0)
    {
        int length = bytesAvailable();
        char buf[1024];
        read(buf,length);

        QString msg=buf;
        emit updateClients(msg,length);
    }
}

void TcpSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
