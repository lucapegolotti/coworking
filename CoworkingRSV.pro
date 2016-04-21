#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T22:40:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoworkingRSV
TEMPLATE = app


SOURCES += main.cpp\
        positionswindow.cpp \
    user.cpp \
    userslist.cpp \
    workstation.cpp \
    date.cpp \
    calendar.cpp \
    addreservation.cpp \
    detailsreservation.cpp

HEADERS  += positionswindow.h \
    user.h \
    userslist.h \
    workstations.h \
    date.h \
    calendar.h \
    addreservation.h \
    detailsreservation.h

FORMS    += positionswindow.ui \
    calendar.ui \
    addreservation.ui \
    detailsreservation.ui
