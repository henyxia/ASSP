// Protector
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes
#include <QMainWindow>
#include <QDockWidget>
#include <QMenuBar>
#include <QTextEdit>
#include <QObject>
#include "logclass.h"
#include "viewclass.h"
#include "serialclass.h"
#include "commandclass.h"

// Class
class MainWindow : public QObject
{
    Q_OBJECT

    // Con/Des structor
    public:
    MainWindow();
    ~MainWindow();
    //~MainWindow() {};

    // Public
    bool    create();
    void    show();

    // Private
    private:
    bool            initLog();
    bool            initMenuBar(QWidget*);
    QMainWindow*    mainWin;
    QDockWidget*    dockLog;
    QDockWidget*    dockStatus;
    QDockWidget*    dockContols;
    QTextEdit*      outputLog;
    QMenuBar*       menu;
    viewclass*      viewObject;
    serialclass*    serials;
    commandclass*   command;

    private slots:
    void startManualMode();
};

#endif
