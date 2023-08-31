#ifndef UDPBASE_H
#define UDPBASE_H
#include "iostream.h"
#include <QUdpSocket>

class UdpBase : public IoStream
{
    Q_OBJECT
public:
    explicit UdpBase(QObject *parent = 0);
    virtual const QString& name() const override;
    virtual void setName(const QString& string) override;
    virtual void close() override;
    virtual int64_t read(char* buff, int64_t size) override;
    virtual int64_t write(const char* message, int64_t size) override;

public slots:
    void readPendingDatagrams();

protected:
    bool setAddress();

    QUdpSocket _udpSocket;
    QString _name;
    QHostAddress _ip;
    quint16 _port;

};

#endif // UDPBASE_H
