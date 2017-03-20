#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QHostInfo>
#include <QNetworkInterface>
#include "udpserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void getHostInfomation();
private:
    Ui::MainWindow *ui;

    QLabel *hostLabel;
    QLineEdit *lineEditLocalHostName;
    QLabel *ipLabel;
    QLineEdit *lineEditAddress;
    QPushButton *detailBtn;
    QGridLayout *mainLayout;

public slots:
    void slotDetail();
    void UDPServerSlot();
};

#endif // MAINWINDOW_H
