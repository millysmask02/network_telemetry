#include "messagesender.h"
#include <QDebug>

MessageSender::MessageSender()
{
    _timer.setInterval(10);
    connect(&_timer, SIGNAL(timeout()), this, SLOT(sendMessage()));
}

void MessageSender::setStream(std::unique_ptr<IoStream> &&stream)
{
    _stream = std::move(stream);
}

void MessageSender::start()
{
    _stream->open();
    _timer.start();
}

void MessageSender::stop()
{
    _timer.stop();
}

void MessageSender::sendMessage()
{
    auto msg = "hello";
    //qDebug() <<
    _stream->write(msg, sizeof(msg));
}
