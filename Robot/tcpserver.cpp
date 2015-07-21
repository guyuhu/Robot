#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

TcpServer::~TcpServer()
{

}

void TcpServer::incomingConnection(int socketDescriptor)
{
    TcpSocket *tcpsocket=new TcpSocket(this);
    connect(tcpsocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));
    connect(tcpsocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));

    tcpsocket->setSocketDescriptor(socketDescriptor);

    tcpSocketList.append(tcpsocket);
}

/*
 *当有客户端连接的情况下，并且服务器成功接收到了数据，下面服务器则将信息进行广播。
 * 这段需要我们自己修改符合功能。
 */
void TcpServer::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);
    for(int i=0;i<tcpSocketList.count();i++)
    {
        QTcpSocket *item = tcpSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }
}

/*
 *轮询查看已连接客户端是否有断开连接，有则断开。
 */
void TcpServer::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpSocketList.count();i++)
    {
        QTcpSocket *item = tcpSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpSocketList.removeAt(i);
            return;
        }
    }
    return;
}
