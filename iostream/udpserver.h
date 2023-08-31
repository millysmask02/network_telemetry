#ifndef UDPSERVER_H
#define UDPSERVER_H

#include "udpbase.h"

class UdpServer : public UdpBase
{
    Q_OBJECT
public:
    UdpServer();
    virtual bool open(QIODevice::OpenMode mode = QIODevice::ReadWrite) override;
    virtual int64_t write(const char* message, int64_t size) override;

};

#endif // UDPSERVER_H
