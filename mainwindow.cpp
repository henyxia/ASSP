// Includes
#include "mainwindow.h"
#include <QMessageBox>
#include <QObject>

MainWindow::MainWindow()
{
	l = NULL;
	c = NULL;
	r = NULL;
	v = NULL;
}

MainWindow::~MainWindow()
{
}

bool MainWindow::create()
{
    mainWin = new QMainWindow();
	if(mainWin == NULL)
	{
        QMessageBox msgB(QMessageBox::Critical, "Critical error",
                         "Unable to init view");
        msgB.exec();
        return false;
    }

    v = new view();
    if(v == NULL)
    {
        QMessageBox msgB(QMessageBox::Critical, "Critical error",
                         "Unable to init view");
        msgB.exec();
        return false;
    }

	// Log initialization
	l = new log();
	if(l == NULL)
	{
		QMessageBox msgB(QMessageBox::Critical, "Critical error",
			"Unable to init log");
        msgB.exec();
        return false;
	}
	l->create();

	// Render
    mainWin->setCentralWidget(v);
    mainWin->addDockWidget(Qt::BottomDockWidgetArea, l);
	l->out->printMessage(output::VALI, "ASSP Render Finished\n");

	// Try to establish the remote connection
	r = new remote();
	r->create();
	if(r == NULL)
		l->out->printMessage(output::ERRO,
				"Unable to create the remote object");
	else
	{
		int ret = r->listAvailableInterfaces();
        QString s = QObject::tr("Remote connection initialized with ") +
			QString::number(ret) + QObject::tr(" connection(s)\n");
		l->out->printMessage(output::INFO, s);
		r->establishConnection();
	}

	// Creating the control panel
	c = new control();
	if(c == NULL)
	{
		QMessageBox msgB(QMessageBox::Critical, "Critical error",
			"Unable to the control");
        msgB.exec();
        return false;
	}
	c->create();
	mainWin->addDockWidget(Qt::BottomDockWidgetArea, c);

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
