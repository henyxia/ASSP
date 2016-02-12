// Protector
#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

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
	bool			initMenuBar	(QWidget*);

	QMainWindow*	mainWin;
	QMenuBar*		menu;
	//control*		c;
	log*			l;
	//remote*		r;
	view*			v;

    private slots:
    void startManualMode();
};

#endif
