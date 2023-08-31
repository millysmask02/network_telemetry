#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QString>
#include <QMetaType>
//#include <QPair>
//#include <QHostAddress>

enum class Protocol {
    Udp,
    Tcp,
    Psovp
};

Q_DECLARE_METATYPE(Protocol)

QString protocolToString(const Protocol protocol);
Protocol protocolFromString(const QString& str);

//typedef QPair<QHostAddress, uint16_t> HostName;

//QString hostNameToString(const HostName& protocol);
//Protocol hostNameFromString(const QString& str);


#endif // PROTOCOL_H
