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
