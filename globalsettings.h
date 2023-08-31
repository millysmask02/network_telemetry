#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

#include "connectionsettings.h"
#include "messagesettings.h"
#include <QSettings>

class GlobalSettings
{
public:
    ConnectionSettings connection;
    MessageSettings messageSettings;

    static GlobalSettings& instance();
    void load(QString fileName);
    void save();
    
private:
    GlobalSettings();
    QString fileName;
    GlobalSettings(const GlobalSettings& root) = delete;
    GlobalSettings operator=(const GlobalSettings&) = delete;
    ~GlobalSettings();
};

#endif // GLOBALSETTINGS_H
