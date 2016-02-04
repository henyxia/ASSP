QT       += core gui widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ASSP
TEMPLATE = app


SOURCES += main.cpp \
	mainwindow.cpp \
	log.cpp \
	output.cpp \
	view.cpp \
	remote.cpp \
	serial.cpp \
	control.cpp

HEADERS  += \
	mainwindow.h \
	log.h \
	output.h \
	view.h \
	logo.h \
	remote.h \
	serial.h \
	control.h

RESOURCES += \
	splash.qrc
