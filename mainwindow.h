// Protector
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes
#include <QMainWindow>
#include <QDockWidget>
#include <QMenuBar>
#include <QTextEdit>
#include <QObject>
#include "log.h"
#include "view.h"
#include "remote.h"
#include "control.h"

// Class
class MainWindow : public QObject
{
    Q_OBJECT

    // Con/Des structor
    public:
    MainWindow();
    ~MainWindow();

    // Public
    bool    create();
    void    show();

    // Private
    private:
	//control*	c;
	logAAA		l;
	//remote*		r;
	//view*		v;

    private slots:
    void startManualMode();
};

#endif
