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
    workstation.cpp \
    date.cpp \
    calendar.cpp \
    addreservation.cpp \
    detailsreservation.cpp \
    checkavailability.cpp \
    reservation.cpp \
    reservationslist.cpp

HEADERS  += positionswindow.h \
    workstations.h \
    date.h \
    calendar.h \
    addreservation.h \
    detailsreservation.h \
    checkavailability.h \
    reservation.h \
    reservationslist.h

FORMS    += positionswindow.ui \
    calendar.ui \
    addreservation.ui \
    detailsreservation.ui \
    checkavailability.ui
