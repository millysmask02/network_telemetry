#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "messagereceiver.h"
#include "messagesender.h"
#include "messagereceiver.h"
#include "protocol.h"
#include "globalsettings.h"
#include "settingsform.h"
//#include <QMessageBox>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Protocol protocol, const QString& serverName, const QString& clientName, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void start(Protocol protocol, const QString& serverName, const QString& clientName);
    void stop();
    void processMessageData(int messageNumber, int timeDiff);

    void on_action_triggered();
    void replot();

    void on_stopButton_clicked();

    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    MessageReceiver _messageReceiver;
    MessageSender   _messageSender;
    Protocol protocol;
    QString serverName;
    QString clientName;
    QTimer _replotTimer;
};

#endif // MAINWINDOW_H
