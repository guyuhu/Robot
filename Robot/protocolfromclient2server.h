#ifndef PROTOCOLFROMCLIENT2SERVER_H
#define PROTOCOLFROMCLIENT2SERVER_H

#include <QObject>
#include <QString>

class ProtocolFromClient2Server
{
       // Q_OBJECT
    public:
        explicit ProtocolFromClient2Server();
        ~ProtocolFromClient2Server();
    QString getRobotID();
    void   setRobotID(QString robotID);

    QString getUltrasonic1();
    void   setUltrasonic1(QString ultrasonic1);
    QString getUltrasonic2();
    void   setUltrasonic2(QString ultrasonic2);
    QString getUltrasonic3();
    void   setUltrasonic3(QString ultrasonic3);
    QString getUltrasonic4();
    void   setUltrasonic4(QString ultrasonic4);
    QString getUltrasonic5();
    void   setUltrasonic5(QString ultrasonic5);
    QString getUltrasonic6();
    void   setUltrasonic6(QString ultrasonic6);
    QString getUltrasonic7();
    void   setUltrasonic7(QString ultrasonic7);
    QString getUltrasonic8();
    void   setUltrasonic8(QString ultrasonic8);

    QString getGyroData();
    void   setGyroData(QString gyroData);

    QString getEncodeOrientL();
    void   setEncodeOrientL(QString encodeOrientL);
    QString getEncodeOrientR();
    void   setEncodeOrientR(QString encodeOrientR);

    QString getEncodeSpeedL();
    void   setEncodeSpeedL(QString encodeSpeedL);
    QString getEncodeSpeedR();
    void   setEncodeSpeedR(QString encodeSpeedR);

    QString getEncodeDistanceL();
    void   setEncodeDistanceL(QString encodeDistanceL);
    QString getEncodeDistanceR();
    void   setEncodeDistanceR(QString encodeDistanceR);

    QString getFinishFlag();
    void   setFinishFlag(QString finishFlag);

    QString getKeyResponseFlag();
    void   setKeyResponseFlag(QString keyResponseFlag);

    QString getLastTargetNode();
    void   setLastTargetNode(QString lastTargetNode);

    QString getCurrentCoordinateX();
    void   setCurrentCoordinateX(QString currentCoordinateX);
    QString getCurrentCoordinateY();
    void   setCurrentCoordinateY(QString currentCoordinateY);

    QString getInstructState();
    void   setInstructState(QString instructState);

    signals:

    public slots:

    private:
        QString robotID;//机器人编号ID
        QString ultrasonic1;//1号超声波
        QString ultrasonic2;//2号超声波
        QString ultrasonic3;//3号超声波
        QString ultrasonic4;//4号超声波
        QString ultrasonic5;//5号超声波
        QString ultrasonic6;//6号超声波
        QString ultrasonic7;//7号超声波
        QString ultrasonic8;//8号超声波

        QString gyroData;//陀螺仪数据
        QString encodeOrientL;//左轮编码盘方向
        QString encodeOrientR;//右轮编码盘方向
        QString encodeSpeedL;//左轮速度
        QString encodeSpeedR;//右轮速度
        QString encodeDistanceL;//左轮编码盘距离
        QString encodeDistanceR;//右轮编码盘距离

        QString finishFlag;//机器人行走状态。这一位初步打算用枚举，来做。

        QString keyResponseFlag;//按键编码

        QString lastTargetNode;//当前的目标点（这个只是为了调试用）。
        QString currentCoordinateX;//机器人坐标X
        QString currentCoordinateY;//机器人坐标Y

        QString instructState;//指令的状态，只是为了在客户端和服务器端进行通信时好判断指令的状态。
                              //这里定义为 connect：客户端连接服务器； send：客户端发送数据； disconnect：客户端断开连接。

};

#endif // PROTOCOLFROMCLIENT2SERVER_H
