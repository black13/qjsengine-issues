TEMPLATE = app

DESTDIR = ./bin
MOC_DIR = ./.moc
OBJECTS_DIR = ./.obj
RCC_DIR = ./.rcc
TARGET = qjsengine-issues

QMAKE_CXXFLAGS += -fvisibility=hidden

QT += qml

CONFIG += console debug
CONFIG -= release
mac {
    CONFIG -= app_bundle
}

RESOURCES = \
    project.qrc

HEADERS += \
    console.h

SOURCES += \
    main.cpp \
    console.cpp

OTHER_FILES += \
    app.js

# vim:ts=4:sw=4:sts=4:et:
