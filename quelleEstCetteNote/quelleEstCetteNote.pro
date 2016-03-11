#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T16:06:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia
TARGET = quelleEstCetteNote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    touche.cpp \
    mywidget.cpp \
    piano.cpp

HEADERS  += mainwindow.h \
    touche.h \
    mywidget.h \
    piano.h

FORMS    += mainwindow.ui

CONFIG += console
