#include "commandlineparser.h"

CommandLineParser::CommandLineParser()
{

}

CommandLineParser::ParserError CommandLineParser::parse(ConnectionSettings& data, const QStringList& args)
{

    if (args.count() % 2 == 0) {
        return ParserError::Error;
    }
    
    for (int i = 0; i < (args.size() - 1) / 2; ++i) {
        QString name = args.at(1 + 2 * i);
        QString value = args.at(1 + 2 * i + 1);
        if (name == "--server"){
            data.serverName = value;
        }
        else if (name == "--client") {
            data.clientName = value;
        }
        else if (name == "--protocol") {
            data.protocol = protocolFromString(value);
        }
        else {
            return ParserError::Error;
        }
    }

    return ParserError::Parsed;
}

CommandLineParser::~CommandLineParser()
{

}
