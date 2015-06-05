#include "mainwindow.h"
#include <QTime>
#include <QDataStream>
#include <QString>

#include <QUrlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    ui.statusBar->addWidget(&statusMessage);

    QUrl url("/auth?login=d3i0&password=123456");
    QUrl url2;


    QUrlQuery urlq(url);
    qDebug() << url.path();
    qDebug() << urlq.queryItemValue("login");


    connect(this, SIGNAL(connectToServer(QString,int)),
            this, SLOT(slotConnectToServer(QString,int))
            );
    connect(this, SIGNAL(sendToServer(QString)),
            this, SLOT(slotSendToServer(QString))
            );
}

void MainWindow::on_pushButton_clicked()
{
    int port = 3434;
    QString host = ui.lineEdit->text();
    emit connectToServer(host, port);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString msg = ui.plainTextEdit->document()->toPlainText();
    emit sendToServer(msg);
}

void MainWindow::slotConnectToServer(const QString &host, const int port)
{
    _client = new TcpClient(host, port);
    connect( _client, SIGNAL(dataRecieved(QString)),
             this, SLOT(setRecivedData(QString))
             );
}

void MainWindow::slotSendToServer(const QString &msg)
{
    _client->sendToServer(msg);
}

void MainWindow::setRecivedData(const QString &msg)
{
    statusMessage.setText(msg);
}
