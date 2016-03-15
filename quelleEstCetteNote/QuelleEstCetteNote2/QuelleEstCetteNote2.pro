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
        mainwindow.cpp \
    note.cpp \
    piano.cpp \
    touche.cpp \
    portee.cpp \
    log.cpp

HEADERS  += mainwindow.h \
    note.h \
    piano.h \
    touche.h \
    portee.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

QMAKE_CXXFLAGS += -std=c++11

DISTFILES += \
    logtouches.log
