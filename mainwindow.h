#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QHostAddress>
#include "tcpclient.h"
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    TcpClient *_client;
    QLabel statusMessage;
public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private slots:
    void slotConnectToServer(const QString &host, const int port);
    void slotSendToServer(const QString &msg);

    void setRecivedData(const QString &msg);

private:
    Ui::MainWindow ui;

signals:
    void connectToServer(const QString &host, const int port);
    void sendToServer(const QString &msg);
};

#endif // MAINWINDOW_H
