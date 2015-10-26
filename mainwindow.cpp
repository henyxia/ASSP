// Includes
#include "mainwindow.h"
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
    output = NULL;
}

MainWindow::~MainWindow()
{
}

bool MainWindow::create()
{
    bool ret;

    mainWin = new QMainWindow();

    output = new logClass();

    ret = initLog();
    if(!ret)
    {
        QMessageBox msgB(QMessageBox::Critical, "Critical error",
                         "Unable to init log");
        msgB.exec();
        return false;
    }

    mainWin->addDockWidget(Qt::BottomDockWidgetArea, dockLog);
    return true;
}

void MainWindow::show()
{
    mainWin->show();
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
    output->addOutput(outputLog);
    dockLog->setWidget(outputLog);

    if(dockLog == NULL)
    {
        QMessageBox msgB(QMessageBox::NoIcon, "Critical error",
                         "Unable to create log");
        msgB.exec();
        return false;
    }

    output->printMessage(logClass::INFO, "ASSP Starting");

    return true;
}
