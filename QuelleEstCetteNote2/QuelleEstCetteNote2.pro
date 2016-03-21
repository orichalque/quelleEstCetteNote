#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T20:24:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT+=multimedia
TARGET = QuelleEstCetteNote2
TEMPLATE = app


SOURCES += main.cpp\
    piano.cpp \
    touche.cpp \
    portee.cpp \
    log.cpp \
    notereader.cpp

HEADERS  += \
    piano.h \
    touche.h \
    portee.h \
    notereader.h

FORMS    +=

RESOURCES += \
    res.qrc \
    buttonclavier.qrc

QMAKE_CXXFLAGS += -std=c++11

DISTFILES += \
    logtouches.log
