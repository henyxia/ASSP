// Includes
#include "mainwindow.h"
#include <QMessageBox>
#include <QObject>

MainWindow::MainWindow()
{
	l = NULL;
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
    if(viewObject == NULL)
    {
        QMessageBox msgB(QMessageBox::Critical, "Critical error",
                         "Unable to init view");
        msgB.exec();
        return false;
    }

    mainWin->setCentralWidget(viewObject);
    mainWin->addDockWidget(Qt::BottomDockWidgetArea, dockLog);

    //serials = new serialclass();
    //FIXME
    // Check return
    //serials->listAvailableInterfaces();
    //FIXME
    // Check return

    //if(!initMenuBar(viewObject))
        //return false;

    return true;
}

void MainWindow::show()
{
    mainWin->showMaximized();
}
/*
bool MainWindow::initControls()
{
	//dockControls = new QDockWidget("Controls");
}
*/
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
    //outputLog->setEnabled(false);
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

void MainWindow::startManualMode()
{
    QMessageBox msgB(QMessageBox::NoIcon, "Something",
                     "Happened");
    msgB.exec();
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
    connect(
            aModeManual,
            SIGNAL(triggered()),
            this,
            SLOT(startManualMode()));

    menu->addMenu(mFile);
    menu->addMenu(mMode);

    return true;
}
