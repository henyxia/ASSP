QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ASSP
TEMPLATE = app


SOURCES += main.cpp \
	mainwindow.cpp \
	logclass.cpp \
	viewclass.cpp \
    logo.cpp

HEADERS  += \
	mainwindow.h \
	logclass.h \
	globals.h \
	viewclass.h \
    logo.h

RESOURCES += \
	splash.qrc
