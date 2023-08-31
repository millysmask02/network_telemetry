#include "udpserver.h"
#include <limits>

UdpServer::UdpServer()
{}

bool UdpServer::open(QIODevice::OpenMode )
{
    return setAddress() && _udpSocket.bind(_ip, _port);
}

int64_t UdpServer::write(const char *message, int64_t size)
{
    return _udpSocket.writeDatagram(message, size, _ip, _port);
}
