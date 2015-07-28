#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
    robotIDValue=0;
    robotNumber=0;
}

TcpServer::~TcpServer()
{

}

void TcpServer::incomingConnection(int socketDescriptor)
{
    TcpSocket *tcpsocket=new TcpSocket(this);

    connect(tcpsocket,SIGNAL(updateClients(ProtocolFromClient2Server)),this,SLOT(receiveData(ProtocolFromClient2Server)));
    connect(tcpsocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));

    tcpsocket->setSocketDescriptor(socketDescriptor);

    //tcpHash.insert(tcpsocket,robotIDValue);
   // tcpSocketList.insert(robotIDValue,tcpsocket);
    tcpSocketList.append(tcpsocket);
}

/*
 *当有客户端连接的情况下，并且服务器成功接收到了数据，下面服务器则将信息进行广播。
 * 这段需要我们自己修改符合功能。
 * 新加功能，当有客户端连接过来，用一个hasn表来存储，key为客户端IP，value为给定的编号。实现逻辑分离。
 */
void TcpServer::receiveData(ProtocolFromClient2Server protocolFromClient2Server )
{   
 //   TcpSocket *tmpSocket=tcpHash.key(robotIDValue);
    QString robotIDKey=protocolFromClient2Server.getRobotID();
    QString instructState=protocolFromClient2Server.getInstructState();
   if(instructState=="connect")
   {
       if(!robotIDKey.isEmpty())
       {
           robotNumber+=1;
           if(robotIDHash.contains(robotIDKey))
           {
               protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
           }
           else
           {
               robotIDValue+=1;
               robotIDHash.insert(robotIDKey,robotIDValue);
               protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
           }
           emit receiveDataSource(protocolFromClient2Server);
       }
   }
   if(instructState=="send")
   {
       if(!robotIDKey.isEmpty())
       {
           if(robotIDHash.contains(robotIDKey))
           {
               protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
           }
           else
           {
               robotIDValue+=1;
               robotIDHash.insert(robotIDKey,robotIDValue);
               protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
           }
           emit receiveDataSource(protocolFromClient2Server);
       }
   }
   if(instructState=="disconnect")
   {
       if(!robotIDKey.isEmpty())
       {
           robotNumber-=1;
           if(robotIDHash.contains(robotIDKey))
           {
               protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
           }
           else
           {
               robotIDValue+=1;
               robotIDHash.insert(robotIDKey,robotIDValue);
               protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
           }
           emit receiveDataSource(protocolFromClient2Server);
       }
   }

//    if(!robotIDKey.isEmpty())
//    {
//        if(robotIDHash.contains(robotIDKey))
//        {
//            protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
//        }
//        else
//        {
//            robotIDValue+=1;
//            robotIDHash.insert(robotIDKey,robotIDValue);
//            protocolFromClient2Server.setRobotID(QString::number(robotIDHash.value(robotIDKey),10));
//        }
//        emit receiveDataSource(protocolFromClient2Server);
//    }
//    if(tcpHash.contains(tmpSocket))
//    {
//        tcpHash.remove(tmpSocket);
//        tcpHash.insert(tmpSocket,robotIDValue);
//    }
}

int TcpServer::getRobotNumber()
{
    return this->robotNumber;
}

QHash<QString, int> TcpServer::getRobotIDHash()
{
    return this->robotIDHash;
}

void TcpServer::sendData(QString msg,int length)
{
    for(int i=0;i<tcpSocketList.size();i++)
    {
      QTcpSocket *item = tcpSocketList.at(i);
      if(item->write(msg.toLatin1(),length)!=length)
      {
          continue;
      }
    }

//    for(int i=0;i<(robotIDValue+1);i++)
//    {
//        QTcpSocket *item=tcpHash.key(i);
//        if(item->write(msg.to))
//    }
}

/*
 *轮询查看已连接客户端是否有断开连接，有则断开。
 */
void TcpServer::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpSocketList.count();i++)
    {
        QTcpSocket *item=tcpSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpSocketList.removeAt(i);
            return;
        }
    }
    return;

//    for(int i=0;i<(robotIDValue+1);i++)
//    {
//        QTcpSocket *item=tcpHash.key(i);
//        if(item->socketDescriptor()==descriptor)
//        {
//           tcpHash.remove(tcpHash.key(i+1));
//            robotIDHash.remove(robotIDHash.key(i+1));
//            return;
//        }
//    }
//    return;
}
