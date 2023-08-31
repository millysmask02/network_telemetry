#include "messagereceiver.h"
#include <QDebug>
#include <iostream>

MessageReceiver::MessageReceiver(QObject *parent) : QObject(parent)
{}

void MessageReceiver::setStream(std::unique_ptr<IoStream> &&stream)
{
    _stream = std::move(stream);
    connect(_stream.get(), SIGNAL(newMessage(const QByteArray&)), this, SLOT(processMessage(const QByteArray&)));
}


int MessageReceiver::messageCount() const
{
    return _messageCount;
}

void MessageReceiver::start()
{
    _stream->open();
}

void MessageReceiver::stop()
{

}

void MessageReceiver::processMessage(const QByteArray &message)
{
    //std::cout << message.data() << std::endl;
    //qDebug() << message.size() << message.constData();
    _messageCount++;
    emit newMessageData(_messageCount, 40 + qrand() % 20);
    //emit newMessage(message);
}
