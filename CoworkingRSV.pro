#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T22:40:31
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoworkingRSV
TEMPLATE = app


SOURCES += main.cpp\
        positionswindow.cpp \
    workstation.cpp \
    calendar.cpp \
    addreservation.cpp \
    detailsreservation.cpp \
    checkavailability.cpp \
    reservation.cpp \
    rsvmeetingroom.cpp \
    meetingroomdaily.cpp \
    meetingroomprogram.cpp \
    addmeetingroomrsv.cpp

HEADERS  += positionswindow.h \
    workstations.h \
    calendar.h \
    addreservation.h \
    detailsreservation.h \
    checkavailability.h \
    reservation.h \
    rsvmeetingroom.h \
    meetingroomdaily.h \
    meetingroomprogram.h \
    genericlist.h \
    genericlist-inl.h \
    addmeetingroomrsv.h

FORMS    += positionswindow.ui \
    calendar.ui \
    addreservation.ui \
    detailsreservation.ui \
    checkavailability.ui \
    meetingroomdaily.ui \
    addmeetingroomrsv.ui
