#include "udpclient.h"

UdpClient::UdpClient()
{

}

bool UdpClient::open(QIODevice::OpenMode)
{
    return setAddress();
}

int64_t UdpClient::read(char *buff, int64_t size)
{
    return _udpSocket.readDatagram(buff, size, &_ip, &_port);
}

int64_t UdpClient::write(const char *message, int64_t size)
{
    return _udpSocket.writeDatagram(message, size, _ip, _port);
}
