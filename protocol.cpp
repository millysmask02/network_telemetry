#include "protocol.h"

QString protocolToString(const Protocol protocol) {
    if(protocol == Protocol::Udp) {
        return "udp";
    }
    else if(protocol == Protocol::Tcp) {
        return "tcp";
    }
    else if(protocol == Protocol::Psovp) {
        return "psovp";
    }
    return {};
}

Protocol protocolFromString(const QString& str) {
    QString txt = str.trimmed().toLower();
    if(txt == "udp") {
        return Protocol::Udp;
    }
    else if (txt == "tcp") {
        return Protocol::Tcp;
    }
    else if (txt == "psovp") {
        return Protocol::Psovp;
    }
    return {};
}
