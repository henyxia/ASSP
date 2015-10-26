QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ASSP
TEMPLATE = app


SOURCES += main.cpp \
	mainwindow.cpp \
	logclass.cpp

HEADERS  += \
	mainwindow.h \
	logclass.h \
    globals.h

RESOURCES += \
	splash.qrc
