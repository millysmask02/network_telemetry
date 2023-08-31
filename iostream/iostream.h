#ifndef IOSTREAM_H
#define IOSTREAM_H

#include <QObject>
#include <QString>
#include <QIODevice>
#include <QByteArray>
#include <stdint.h>

class IoStream : public QObject
{
    Q_OBJECT
public:
    explicit IoStream(QObject *parent = 0);
    virtual const QString& name() const = 0;
    virtual ~IoStream();

public slots:
    virtual void setName(const QString& string) = 0;
    virtual bool open(QIODevice::OpenMode mode = QIODevice::ReadWrite) = 0;
    virtual void close() = 0;
    virtual int64_t read(char* buff, int64_t size) = 0;
    virtual int64_t write(const char* message, int64_t size) = 0;

signals:
    void newMessage(const QByteArray& message);
};

#endif // IOSTREAM_H
