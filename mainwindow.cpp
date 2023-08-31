#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream/udpserver.h"
#include "iostream/udpclient.h"
#include <QElapsedTimer>


MainWindow::MainWindow(Protocol protocol, const QString &serverName, const QString &clientName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    start(protocol, serverName, clientName);

    MessageSettings& message = GlobalSettings::instance().messageSettings;
    ui->messageSizeEdit->setText(QString::number(message.size));
    ui->messageIntervalEdit->setText(QString::number(message.interval));
    ui->messageCountEdit->setText(QString::number(message.count));

    ui->plotWidget->addGraph();
    ui->plotWidget->xAxis->setLabel("Номер сообщения");
    ui->plotWidget->yAxis->setLabel("Время");
    ui->plotWidget->xAxis->setRange(0, 300);
    ui->plotWidget->yAxis->setRange(0, 100);
    connect(&_messageReceiver, SIGNAL(newMessageData(int, int)), this, SLOT(processMessageData(int, int)));

    connect(&_replotTimer, SIGNAL(timeout()), this, SLOT(replot()));
    _replotTimer.setInterval(100);
    _replotTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start(Protocol protocol, const QString &serverName, const QString &clientName)
{
    std::unique_ptr<IoStream> server, client;
    if (protocol == Protocol::Udp){
        server.reset(new UdpServer);
        client.reset(new UdpClient);
    }
    else if (protocol == Protocol::Tcp) {
        //QMessageBox::warning(this, "...", "Не поддерживается");
        return;
    }
    else if (protocol == Protocol::Psovp) {
        return;
    }
    server->setName(serverName);
    client->setName(clientName);
    _messageReceiver.setStream(std::move(server));
    _messageSender.setStream(std::move(client));
    _messageReceiver.start();
    _messageSender.start();
    ui->logBrowser->append("Прием и отправка запущены");
}

void MainWindow::stop()
{
    _messageReceiver.stop();
    _messageSender.stop();
    ui->logBrowser->append("Прием и отправка остановлены");
}

void MainWindow::processMessageData(int messageNumber, int timeDiff)
{
    ui->plotWidget->graph(0)->addData(messageNumber, timeDiff);
    if (messageNumber > 300) {
        ui->plotWidget->xAxis->setRange(messageNumber - 300, messageNumber);
    }
}

void MainWindow::on_action_triggered()
{
    SettingsForm form;
    if (form.exec() == QDialog::Accepted) {
        stop();
        MessageSettings& message = GlobalSettings::instance().messageSettings;
        ui->messageSizeEdit->setText(QString::number(message.size));
        ui->messageIntervalEdit->setText(QString::number(message.interval));
        ui->messageCountEdit->setText(QString::number(message.count));
    }
}

void MainWindow::replot()
{
    ui->plotWidget->replot();
}

void MainWindow::on_stopButton_clicked()
{
    stop();
}

void MainWindow::on_startButton_clicked()
{
    stop();
    ConnectionSettings& data = GlobalSettings::instance().connection;
    start(data.protocol, data.serverName, data.clientName);
}
