#ifndef MESSAGESENDLER_H
#define MESSAGESENDLER_H

#include <QObject>
#include <memory>
#include "iostream/iostream.h"
#include <QTimer>

class MessageSender : public QObject
{
    Q_OBJECT
public:
    MessageSender();
    void setStream(std::unique_ptr<IoStream>&& stream);

public slots:
    void start();
    void stop();

private slots:
    void sendMessage();

private:
    std::unique_ptr<IoStream> _stream;
    QTimer _timer;
};


#endif // MESSAGESENDLER_H
