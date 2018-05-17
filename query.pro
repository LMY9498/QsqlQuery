#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T11:13:50
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = query
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    connection.h

FORMS    += widget.ui
