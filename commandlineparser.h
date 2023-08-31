#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <QStringList>
#include "connectionsettings.h"

class CommandLineParser
{
public:
    CommandLineParser();
    ~CommandLineParser();

    enum class ParserError
    {
        Parsed,
        Error
    };
    ParserError parse(ConnectionSettings& data, const QStringList& args);

};

#endif // COMMANDLINEPARSER_H
