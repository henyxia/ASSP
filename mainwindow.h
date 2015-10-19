// Protector
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes
#include <QMainWindow>
#include <QDockWidget>
#include <QMenuBar>
#include <QTextEdit>

// Class
class MainWindow
{
    // Con/Des structor
    public:
    MainWindow();
    ~MainWindow();

    // Public
    bool create();
    void show();

    // Private
    private:
    bool initLog();
    QMainWindow*    mainWin;
    QDockWidget*    dockLog;
    QDockWidget*    dockStatus;
    QDockWidget*    dockContols;
    QTextEdit*      outputLog;
    QMenuBar*       menu;
};

#endif // MAINWINDOW_H
