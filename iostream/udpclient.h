#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include "udpbase.h"

class UdpClient : public UdpBase
{
    Q_OBJECT
public:
    UdpClient();
    virtual bool open(QIODevice::OpenMode mode = QIODevice::ReadWrite) override;
    virtual int64_t read(char* buff, int64_t size) override;
    virtual int64_t write(const char *message, int64_t size) override;
};

#endif // UDPCLIENT_H
