QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetworkTelemetry
TEMPLATE = app

DESTDIR = $$PWD/../bin/$${TARGET}
TEMPPATH = $${DESTDIR}/$${TARGET}_temp
CONFIG(debug, debug|release) {
    OBJECTS_DIR = $${TEMPPATH}/$${TARGET}_objects_debug
}
CONFIG(release, debug|release) {
    OBJECTS_DIR = $${TEMPPATH}/$${TARGET}_objects_release
}

MOC_DIR = $${TEMPPATH}/moc
UI_DIR  = $${TEMPPATH}/ui
RCC_DIR = $${TEMPPATH}/rcc

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

CONFIG += c++11

unix:QMAKE_CXXFLAGS += -std=c++11
unix:QMAKE_LFLAGS += -rdynamic
unix:QMAKE_CXXFLAGS_WARN_ON += -Werror=return-type -Werror=array-bounds

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        protocol.cpp \
        iostream/iostream.cpp \
        iostream/udpbase.cpp \
        iostream/udpclient.cpp \
        iostream/udpserver.cpp \
        messagesender.cpp \
        messagereceiver.cpp \
    globalsettings.cpp \
    connectionsettings.cpp \
    commandlineparser.cpp \
    qcustomplot.cpp \
    settingsform.cpp \
    messagesettings.cpp

HEADERS += \
        mainwindow.h \
        protocol.h \
        iostream/iostream.h \
        iostream/udpbase.h \
        iostream/udpclient.h \
        iostream/udpserver.h \
        messagesender.h \
        messagereceiver.h \
    globalsettings.h \
    connectionsettings.h \
    commandlineparser.h \
    qcustomplot.h \
    settingsform.h \
    messagesettings.h

FORMS += \
        mainwindow.ui \
    settingsform.ui
