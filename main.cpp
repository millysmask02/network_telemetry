#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QTextCodec>
#include <QSettings>
#include <QDebug>

#include "connectionsettings.h"
#include "globalsettings.h"
#include "commandlineparser.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if QT_MAJOR_VERSION < 5
    auto codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
#endif

    GlobalSettings::instance().load("networktelemetry.ini");
    ConnectionSettings& data = GlobalSettings::instance().connection;
    CommandLineParser parser;
    CommandLineParser::ParserError parserError = parser.parse(data, app.arguments());

    if (parserError == CommandLineParser::ParserError::Parsed) {
        qDebug() << "Данные успешно получены";
    }
    else if (parserError == CommandLineParser::ParserError::Error) {
        qDebug() << "Ошибка получения данных";
    }
    
    if (data.clientName.isEmpty() || data.serverName.isEmpty()) {
        qDebug() << "Отсутствует или неверно введен адрес клиента/сервера";
    }
    else if (data.protocol != Protocol::Psovp && 
             data.protocol != Protocol::Tcp &&
             data.protocol != Protocol::Udp) {
        qDebug() << "Отсутствует или неверно введен протокол";
    }

    MainWindow mainWindow(data.protocol, data.serverName, data.clientName);
    mainWindow.show();
    return app.exec();
}
