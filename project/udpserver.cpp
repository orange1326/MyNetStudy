#include "udpserver.h"

UDPServer::UDPServer(QWidget *parent,Qt::WindowFlags f)
    :QDialog(parent,f)
{
    setWindowTitle(tr("UDP Server"));

    timerLabel = new QLabel(tr("计数器："),this);
    textLineEdit = new QLineEdit(this);
    startBtn = new QPushButton(tr("开始"),this);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(timerLabel);
    mainLayout->addWidget(textLineEdit);
    mainLayout->addWidget(startBtn);

    connect(startBtn,SIGNAL(clicked()),this,SLOT(startBtnClicked()));

    port = 5555;
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
}

void UDPServer::startBtnClicked()
{
    if(!isStarted)
    {
        startBtn->setText(tr("停止"));
        timer->start(1000);
        isStarted = true;
    }
    else
    {
        startBtn->setText("开始");
        isStarted = false;
        timer->stop();
    }
}

void UDPServer::timeout()
{
    QString msg = textLineEdit->text();
    int length = 0;
    if(msg == "")
    {
        return;
    }
    qDebug()<<QHostAddress::Broadcast;
    if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port)) != msg.length())
    {
        return;
    }
}
