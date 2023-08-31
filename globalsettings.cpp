#include "globalsettings.h"

GlobalSettings::GlobalSettings()
{
}

GlobalSettings::~GlobalSettings()
{

}

GlobalSettings &GlobalSettings::instance()
{
    static GlobalSettings theSingleInstance;
    return theSingleInstance;
}

void GlobalSettings::load(QString fileName)
{
    this->fileName = fileName;
    QSettings settingsArgv(fileName, QSettings::IniFormat);
    connection.serverName = settingsArgv.value("Network/server").toString();
    connection.clientName = settingsArgv.value("Network/client").toString();
    connection.protocol = protocolFromString(settingsArgv.value("Network/protocol").toString());


    messageSettings.size = settingsArgv.value("Message/size").toInt();
    messageSettings.interval = settingsArgv.value("Message/interval").toInt();
    messageSettings.count = settingsArgv.value("Message/count").toInt();
}

void GlobalSettings::save()
{
    QSettings settingsArgv(fileName, QSettings::IniFormat);
    settingsArgv.setValue("Network/server", connection.serverName);
    settingsArgv.setValue("Network/client", connection.clientName);
    settingsArgv.setValue("Network/protocol", protocolToString(connection.protocol));

    settingsArgv.setValue("Message/size", messageSettings.size);
    settingsArgv.setValue("Message/interval", messageSettings.interval);
    settingsArgv.setValue("Message/count", messageSettings.count);

    settingsArgv.sync();
}
