QT       += core gui widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ASSP
TEMPLATE = app


SOURCES += main.cpp \
	mainwindow.cpp \
	logclass.cpp \
	viewclass.cpp \
	logo.cpp \
	serialclass.cpp

HEADERS  += \
	mainwindow.h \
	logclass.h \
	globals.h \
	viewclass.h \
	logo.h \
	serialclass.h

RESOURCES += \
	splash.qrc
