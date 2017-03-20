#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    getHostInfomation();
    connect(ui->btnDetail,SIGNAL(clicked()),this,SLOT(slotDetail()));

    connect(ui->BtnUDPServer,SIGNAL(clicked()),this,SLOT(UDPServerSlot()));
    connect(ui->udpClientBtn,SIGNAL(clicked()),this,SLOT(UDPClientSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getHostInfomation()
{
    QString localHostName = QHostInfo::localHostName();
    ui->lineEditLocalHostName->setText(localHostName);

    QHostInfo hostInfo = QHostInfo::fromName(localHostName);
    QList<QHostAddress> listAddress = hostInfo.addresses();

    if(!listAddress.isEmpty())
    {
        ui->lineEditAddress->setText(listAddress.first().toString());
    }
}

void MainWindow::slotDetail()
{
    QString  detail = "";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for(int i=0;i<list.count();i++)
    {
        QNetworkInterface interface = list.at(i);
        detail = detail+tr("设备：")+interface.name()+"\n";
        detail = detail+tr("硬件地址:")+interface.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for(int j=0;j<entryList.count();j++)
        {
            QNetworkAddressEntry entry = entryList.at(j);
            detail = detail+"\t"+tr("IP地址：")+entry.ip().toString()+"\n";
            detail = detail+"\t"+tr("子网掩码：")+entry.netmask().toString()+"\n";
            detail = detail+"\t"+tr("广播地址：")+entry.broadcast().toString()+"\n";
        }
    }
    QMessageBox::information(this,tr("Detail"),detail);
}

void MainWindow::UDPServerSlot()
{
    this->hide();
    UDPServer *udpServer = new UDPServer();
    udpServer->show();
    int res = udpServer->exec();
    if(res == QDialog::Accepted)
    {
        udpServer->show();
    }
    if(res == QDialog::Rejected)
    {
        udpServer->close();
    }
    this->show();
}
