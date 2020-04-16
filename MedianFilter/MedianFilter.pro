#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T11:48:58
#
#-------------------------------------------------


QT       += core gui
QT       += core
QT       += concurrent gui
QT       += concurrent
QT       += widgets
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedianFilterMyPicQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagechanger.cpp

HEADERS  += mainwindow.h \
    imagechanger.h

FORMS    += mainwindow.ui
