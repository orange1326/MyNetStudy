#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QUdpSocket>
#include <QTimer>
#include <QHostAddress>

class UDPServer : public QDialog
{
    Q_OBJECT
public:
    UDPServer(QWidget *parent = 0,Qt::WindowFlags f = 0);
private:
    QLabel *timerLabel;
    QLineEdit *textLineEdit;
    QPushButton *startBtn;
    QVBoxLayout *mainLayout;
public slots:
    void startBtnClicked();
    void timeout();
private:
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
};

#endif // UDPSERVER_H
