#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    companyWebAddress ="explorer http://www.oschina.net/p/qtsharp";

    pingNet ="Ping www.baidu.com";   //实现ping值的实时测量
    getPing();
    QTimer *pingTimer=new QTimer(this);//此段作用是用一个定时器，每隔5s,查看一次当前ping值。
    connect(pingTimer,SIGNAL(timeout()),this,SLOT(pingTimeOut()));
    pingTimer->start(5000);

    bool ok=false;                      //定义声明一个服务器实体。
    getHostInformation();
    port=this->ui->editPort->text().toInt(&ok,10);
    tcpserver=new TcpServer(this,port);

    connect(tcpserver,SIGNAL(receiveDataSource(QString,int)),this,SLOT(receiveData(QString,int)));//接收数据槽函数。
    connect(this,SIGNAL(sendDataSource(QString,int)),this,SLOT(sendData(QString,int)));//发送数据槽函数。
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 *此处通过几个类来获取本地主机的几个基本属性，并显示出来。
 */
void MainWindow::getHostInformation()
{
    QString localHostName=QHostInfo::localHostName();
    this->ui->txtLocalName->setText(localHostName);

    QHostInfo hostInfo=QHostInfo::fromName(localHostName);//初始化界面，显示本地信息。
    QList<QHostAddress> listAddress=hostInfo.addresses();
    if(!listAddress.isEmpty())
    {
        this->ui->txtLocalIP->setText(listAddress.first().toString());
    }
}

/*
 *查询本地信息详细情况
 */
void MainWindow::on_btnMoreMessage_clicked()
{
    QString detail="";
    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces();
    for(int i=0;i<list.count();i++)
    {
        QNetworkInterface interface=list.at(i);
        detail=detail+tr("设备：")+interface.name()+"\n";
        detail=detail+tr("硬件地址: ")+interface.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList=interface.addressEntries();
        for(int j=0;j<entryList.count();j++)
        {
            QNetworkAddressEntry entry=entryList.at(j);
            detail=detail+"\t"+tr("IP地址： ")+entry.ip().toString()+"\n";
            detail=detail+"\t"+tr("子网掩码： ")+entry.netmask().toString()+"\n";
            detail=detail+"\t"+tr("广播地址： ")+entry.broadcast().toString()+"\n";
        }
    }
    QMessageBox::information(this,tr("Detail"),detail);
}


/*
* 得到ping值，用来表示网络状况。
*/
void MainWindow::getPing()
{
    QProcess cmd;
    cmd.start(pingNet);
    cmd.waitForStarted(200);
    cmd.waitForFinished(200);
    cmd.waitForReadyRead(200);
    ping =QString::fromLocal8Bit( cmd.readAll());
    QString pingTime=ping.mid( ping.indexOf("时间="),7);//没办法，只能通过找到字符位置，然后取来得到时间。
    pingTime=pingTime.mid(pingTime.indexOf("="));
  //  qDebug()<<"ping:"<<ping;
   // qDebug()<<"pingTime:"<<pingTime;
    pingTime="ping"+pingTime;
    this->ui->txtLocalNet->setText(pingTime);
}

/*
* 用定时器做的一个5s固定查询ping值。
*/
void MainWindow::pingTimeOut()
{
    getPing();
}

/*
* 按下更新软件按钮，转到更新网页，可以让用户自己下载新产品。
*/
void MainWindow::on_pushButton_clicked()
{
    switch (QMessageBox::question(this,tr("更新软件对话框"),
                                  tr("您确定要进行软件更新？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
        case QMessageBox::Ok:
            QProcess::startDetached(companyWebAddress);
        break;
        case QMessageBox::Cancel:
        break;
        default:
        break;
    }
    return;
}

/*
* 按下远程下载，选择bin文件，然后远程下载给机器。
*/
void MainWindow::on_btnRemoteDown_clicked()
{
    switch (QMessageBox::question(this,tr("远程下载对话框"),
                                  tr("您确定要进行远程下载？如果是，请继续，选择下载文件！"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
        case QMessageBox::Ok :
            // QString file=QFileDialog::getOpenFileName(this,"选择bin文件","/","二进制文件(*.bin)");
            QFileDialog::getOpenFileName(this,"选择bin文件","/","二进制文件(*.bin)");
        break;
        case QMessageBox::Cancel :
        break;
        default:
        break;
    }
    return;
}

/*
 *在服务器端，用来接收客户端传送来的数据，现阶段主要是用作调试，显示出来。
 * 我们的工作重点就放在数据接收、解析。发送解析。
 */
void MainWindow::receiveData(QString msg, int length)
{
  //  this->ui->txtShowData->setText(msg.left(length));
    this->ui->txtShowData->append(msg.left(length));
}

/*
 * 发送数据，作为测试，保证服务器、客户端能够连通。
 * */
void MainWindow::on_bthOrder_clicked()
{
    QString msg;
    msg=this->ui->editOrder->text();
    int length=msg.length();

    emit sendDataSource(msg,length);
}

void MainWindow::sendData(QString msg, int length)
{
    tcpserver->sendData(msg,length);
}
