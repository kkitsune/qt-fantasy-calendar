TEMPLATE = app

QT += qml quick sql

SOURCES += main.cpp \
    calendar.cpp \
    month.cpp \
    day.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    calendar.h \
    month.h \
    day.h
