#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H

#include "protocol.h"

class ConnectionSettings
{
public:
    Protocol protocol;
    QString serverName;
    QString clientName;

    ConnectionSettings();
    ~ConnectionSettings();
};

#endif // CONNECTIONSETTINGS_H
