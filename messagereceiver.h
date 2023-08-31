#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

#include <QObject>
#include "iostream/iostream.h"
#include <memory>

class MessageReceiver : public QObject
{
    Q_OBJECT
public:
    explicit MessageReceiver(QObject *parent = nullptr);
    void setStream(std::unique_ptr<IoStream>&& stream);
    int messageCount() const;

signals:
    //void newMessage(const QByteArray& message);
    int newMessageData(int messageNumber, int timeDiff);

public slots:
    void start();
    void stop();

private slots:
    void processMessage(const QByteArray& message);

private:
    std::unique_ptr<IoStream> _stream;
    int _messageCount = 0;
};

#endif // MESSAGEPROCESSOR_H
