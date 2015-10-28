// Includes
#include "mainwindow.h"
#include "globals.h"
#include <QMessageBox>
#include <QObject>

MainWindow::MainWindow()
{
    mainWin = NULL;
    dockLog = NULL;
    dockStatus = NULL;
    dockContols = NULL;
    menu = NULL;
    outputLog = NULL;
    serials = NULL;
}

MainWindow::~MainWindow()
{
}

bool MainWindow::create()
{
    bool ret;

    mainWin = new QMainWindow();

    ret = initLog();
    if(!ret)
    {
        QMessageBox msgB(QMessageBox::Critical, "Critical error",
                         "Unable to init log");
        msgB.exec();
        return false;
    }

    viewObject = new viewclass();

    mainWin->setCentralWidget(viewObject);
    mainWin->addDockWidget(Qt::BottomDockWidgetArea, dockLog);

    serials = new serialclass();
    //FIXME
    // Check return
    serials->listAvailableInterfaces();
    //FIXME
    // Check return

    if(!initMenuBar(viewObject))
        return false;

    return true;
}

void MainWindow::show()
{
    mainWin->showMaximized();
}

bool MainWindow::initLog()
{

    dockLog = new QDockWidget("Log");
    outputLog = new QTextEdit();
    if(outputLog == NULL)
    {
        QMessageBox msgB(QMessageBox::NoIcon, "Critical error",
                         "Unable to create output log");
        msgB.exec();
        return false;
    }
    outputLog->setEnabled(false);
    outputLog->setMinimumHeight(100);
    outputLog->setMaximumHeight(100);
    output->addOutput(outputLog);
    dockLog->setWidget(outputLog);

    if(dockLog == NULL)
    {
        QMessageBox msgB(QMessageBox::NoIcon, "Critical error",
                         "Unable to create log");
        msgB.exec();
        return false;
    }

    output->printMessage(logClass::INFO, "ASSP Starting\n");

    return true;
}

bool MainWindow::initMenuBar(QWidget* parent)
{
    QMenu*      mFile = NULL;
    QMenu*      mMode = NULL;
    QAction*    aOpenGerber = NULL;
    QAction*    aModeManual = NULL;

    menu = new QMenuBar(parent);
    if(menu == NULL)
    {
        QMessageBox msgB(QMessageBox::Critical, "Critical error",
                         "Unable to init menubar");
        msgB.exec();
        return false;
    }

    mFile = new QMenu("File");
    aOpenGerber = new QAction("Open Gerber file", mFile);
    mFile->addAction(aOpenGerber);

    mMode = new QMenu("Mode");
    aModeManual = new QAction("Manual mode", mMode);
    mMode->addAction(aModeManual);

    menu->addMenu(mFile);
    menu->addMenu(mMode);

    return true;
}
