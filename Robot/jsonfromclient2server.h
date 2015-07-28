#ifndef JSONFROMCLIENT2SERVER_H
#define JSONFROMCLIENT2SERVER_H

#include <QObject>
#include "protocolfromclient2server.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>


/*一、本类包含数据发送的方法：
 *  本类数据输入：一个ProtocolFromClient2Server对象。
 *  本类数据输出：一个字符串。
 *  本类需要严格按照以下步骤进行操作，操作步骤如下：
 *      1、给定数据源：setProtocolFromClient2Server（）；
 *      2、进行数据转换：converData2JSON();
 *      3、得到最后字符串格式的数据：getJSONData();
 *
* 二、本类包含数据接收的方法：
 *  本类数据输入：一个bytearray,字符数组。
 *  本类数据输出：一个ProtocolFromClient2Server对象。
 *  本类需要严格按照以下步骤进行操作，操作步骤如下：
 *      1、给定数据源：setJSONData()；
 *      2、进行数据转换：converJSON2Data();
 *      3、得到最后字符串格式的数据：getProtocolFromClient2Server();
 */
class JsonFromClient2Server : public QObject
{
        Q_OBJECT
    public:
        explicit JsonFromClient2Server(QObject *parent = 0);
        ~JsonFromClient2Server();

        void setProtocolFromClient2Server(ProtocolFromClient2Server protolFromClient2Server);//首先需要外界给定一个protocolFromClient2Server类型的数据源。
        void converData2JSON();//将数据转为json格式。
        QString getJSONData();//得到最后的json数据；

        void setJSONData(QByteArray jsonData);//首先需要外界给定一个bytearray类型的数据源。
        void converJSON2Data();//将数据转为protocoFromClient2Server格式。
        ProtocolFromClient2Server getProtocolFromClient2Server();//得到最后的protocolFromClient2Server数据；

    signals:

    public slots:

    private:
        ProtocolFromClient2Server protocolFromClient2Server;

        QJsonObject jsonObject;
        QJsonDocument jsonDocument;
        QByteArray jsonData;
        QJsonParseError jsonError;
        QJsonValue jsonValue;
};

#endif // JSONFROMCLIENT2SERVER_H
