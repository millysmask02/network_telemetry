#include "udpbase.h"


UdpBase::UdpBase(QObject *parent)
    : IoStream (parent)
{
    connect(&_udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

const QString& UdpBase::name() const{
    return _name;
}
void UdpBase::setName(const QString& name){
    _name = name;
}

void UdpBase::close(){
    _udpSocket.close();
}
int64_t UdpBase::read(char* buff, int64_t size){
    return _udpSocket.read(buff, size);
}
int64_t UdpBase::write(const char* message, int64_t size){
    return _udpSocket.write(message, size);
}

void UdpBase::readPendingDatagrams()
{
    while (_udpSocket.hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(_udpSocket.pendingDatagramSize());

            _udpSocket.readDatagram(datagram.data(), datagram.size());

            emit newMessage(datagram);
        }
}

bool UdpBase::setAddress(){
    int index = _name.lastIndexOf(':');
    QString namePort;
    namePort = _name.right(_name.size() - index - 1);
    bool okPort;
    uint port = namePort.toUInt(&okPort, 10);
    QString nameIp = _name.left(index);
    if (okPort && port <= std::numeric_limits<ushort>::max()){
        _ip.setAddress(nameIp);
        _port = quint16(port);
        return true;
    }
    return false;
}

