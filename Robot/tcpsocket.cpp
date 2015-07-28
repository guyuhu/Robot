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
        QByteArray jsonData=readAll();
        jsonFromClient2Server.setJSONData(jsonData);
        jsonFromClient2Server.converJSON2Data();
       protocolFromClient2Server= jsonFromClient2Server.getProtocolFromClient2Server();
        emit updateClients(protocolFromClient2Server);
    }
}

void TcpSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
