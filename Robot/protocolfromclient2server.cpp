#include "protocolfromclient2server.h"

ProtocolFromClient2Server::ProtocolFromClient2Server()
{

}

ProtocolFromClient2Server::~ProtocolFromClient2Server()
{

}

/*
 *机器人编号ID
 */
QString ProtocolFromClient2Server::getRobotID()
{
    return this->robotID;
}
void   ProtocolFromClient2Server::setRobotID(QString robotID)
{
    this->robotID=robotID;
}


/*
 *1号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic1()
{
    return this->ultrasonic1;
}
void   ProtocolFromClient2Server::setUltrasonic1(QString ultrasonic1)
{
    this->ultrasonic1=ultrasonic1;
}

/*
 *2号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic2()
{
    return this->ultrasonic2;
}
void   ProtocolFromClient2Server::setUltrasonic2(QString ultrasonic2)
{
    this->ultrasonic2=ultrasonic2;
}

/*
 *3号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic3()
{
    return this->ultrasonic3;
}
void   ProtocolFromClient2Server::setUltrasonic3(QString ultrasonic3)
{
     this->ultrasonic3=ultrasonic3;
}

/*
 *4号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic4()
{
    return this->ultrasonic4;
}
void   ProtocolFromClient2Server::setUltrasonic4(QString ultrasonic4)
{
     this->ultrasonic4=ultrasonic4;
}

/*
 *5号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic5()
{
    return this->ultrasonic5;
}
void   ProtocolFromClient2Server::setUltrasonic5(QString ultrasonic5)
{
     this->ultrasonic5=ultrasonic5;
}

/*
 *6号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic6()
{
    return this->ultrasonic6;
}
void   ProtocolFromClient2Server::setUltrasonic6(QString ultrasonic6)
{
     this->ultrasonic6=ultrasonic6;
}

/*
 *7号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic7()
{
    return this->ultrasonic7;
}
void   ProtocolFromClient2Server::setUltrasonic7(QString ultrasonic7)
{
     this->ultrasonic7=ultrasonic7;
}

/*
 *8号超声波
 */
QString ProtocolFromClient2Server::getUltrasonic8()
{
    return this->ultrasonic8;
}
void   ProtocolFromClient2Server::setUltrasonic8(QString ultrasonic8)
{
     this->ultrasonic8=ultrasonic8;
}

/*
 *陀螺仪数据
 */
QString ProtocolFromClient2Server::getGyroData()
{
    return this->gyroData;
}
void   ProtocolFromClient2Server::setGyroData(QString gyroData)
{
    this->gyroData=gyroData;
}

/*
 *左轮编码盘方向
 */
QString ProtocolFromClient2Server::getEncodeOrientL()
{
    return this->encodeOrientL;
}
void   ProtocolFromClient2Server::setEncodeOrientL(QString encodeOrientL)
{
    this->encodeOrientL=encodeOrientL;
}

/*
 *右轮编码盘方向
 */
QString ProtocolFromClient2Server::getEncodeOrientR()
{
    return this->encodeOrientR;
}

void   ProtocolFromClient2Server::setEncodeOrientR(QString encodeOrientR)
{
    this->encodeOrientR=encodeOrientR;
}

/*
 *左轮速度
 */
QString ProtocolFromClient2Server::getEncodeSpeedL()
{
    return this->encodeSpeedL;
}
void   ProtocolFromClient2Server::setEncodeSpeedL(QString encodeSpeedL)
{
    this->encodeSpeedL=encodeSpeedL;
}

/*
 *右轮速度
 */
QString ProtocolFromClient2Server::getEncodeSpeedR()
{
    return this->encodeSpeedR;
}
void   ProtocolFromClient2Server::setEncodeSpeedR(QString encodeSpeedR)
{
    this->encodeSpeedR=encodeSpeedR;
}

/*
 *左轮编码盘距离
 */
QString ProtocolFromClient2Server::getEncodeDistanceL()
{
    return this->encodeDistanceL;
}
void   ProtocolFromClient2Server::setEncodeDistanceL(QString encodeDistanceL)
{
    this->encodeDistanceL=encodeDistanceL;
}

/*
 *右轮编码盘距离
 */
QString ProtocolFromClient2Server::getEncodeDistanceR()
{
    return this->encodeDistanceR;
}
void   ProtocolFromClient2Server::setEncodeDistanceR(QString encodeDistanceR)
{
    this->encodeDistanceR=encodeDistanceR;
}

/*
 *机器人行走状态
 */
QString ProtocolFromClient2Server::getFinishFlag()
{
    return this->finishFlag;
}
void   ProtocolFromClient2Server::setFinishFlag(QString finishFlag)
{
    this->finishFlag=finishFlag;
}

/*
 *按键编码
 */
QString ProtocolFromClient2Server::getKeyResponseFlag()
{
    return this->keyResponseFlag;
}
void   ProtocolFromClient2Server::setKeyResponseFlag(QString keyResponseFlag)
{
    this->keyResponseFlag=keyResponseFlag;
}

/*
 *当前的目标点
 */
QString ProtocolFromClient2Server::getLastTargetNode()
{
    return this->lastTargetNode;
}
void   ProtocolFromClient2Server::setLastTargetNode(QString lastTargetNode)
{
    this->lastTargetNode=lastTargetNode;
}

/*
 *机器人坐标X
 */
QString ProtocolFromClient2Server::getCurrentCoordinateX()
{
    return this->currentCoordinateX;
}
void   ProtocolFromClient2Server::setCurrentCoordinateX(QString currentCoordinateX)
{
    this->currentCoordinateX=currentCoordinateX;
}

/*
 *机器人坐标Y
 */
QString ProtocolFromClient2Server::getCurrentCoordinateY()
{
    return this->currentCoordinateY;
}
void   ProtocolFromClient2Server::setCurrentCoordinateY(QString currentCoordinateY)
{
    this->currentCoordinateY=currentCoordinateY;
}

/*
 *指令的状态，只是为了在客户端和服务器端进行通信时好判断指令的状态。
 * 这里定义为 connect：客户端连接服务器； send：客户端发送数据； disconnect：客户端断开连接。
 */
QString ProtocolFromClient2Server::getInstructState()
{
    return this->instructState;
}
void   ProtocolFromClient2Server::setInstructState(QString instructState)
{
    this->instructState=instructState;
}
