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

	// Render
    mainWin->setCentralWidget(v);
    mainWin->addDockWidget(Qt::BottomDockWidgetArea, l);
	mainWin->addDockWidget(Qt::RightDockWidgetArea, c);
	l->out->printMessage(output::VALI, "ASSP Render Finished\n");

	// Try to establish the remote connection
	r = new remote();
	r->create();
	if(r == NULL)
	{
		l->out->printMessage(output::ERRO,
				"Unable to create the remote object");
		return false;
	}
	else
	{
		int ret = r->listAvailableInterfaces();
        QString s = QObject::tr("Remote connection initialized with ") +
			QString::number(ret) + QObject::tr(" connection(s)\n");
		l->out->printMessage(output::INFO, s);
		ret = r->establishConnection();
		if(ret<0)
		{
			l->out->printMessage(output::INFO, "No connection established\n");
			l->out->printMessage(output::INFO, QString(
						QObject::tr(" -> Return code ") + QString::number(ret)
						+ "\n"));
			return true;
		}
		l->out->printMessage(output::VALI, QString(
					QObject::tr("Connect established with serial connection ")
					+ QString::number(ret) + "\n"));
		refreshControlPanel(ret);
	}
    return true;
}

void MainWindow::show()
{
    mainWin->showMaximized();
}

void MainWindow::refreshControlPanel(int conn)
{
	qint8	dq8;
	qint16	dq16;
	QString	dqs;

	// Port Name
	dqs = r->getPortName(conn);
	if(dqs.size() < 0)
	{
		l->out->printMessage(output::ERRO, "Unable to the port name");
		return;
	}
	c->setPortName(dqs);

	// Port Speed
	dq16 = r->getPortSpeed(conn);
	if(dq16 <= 0)
	{
		l->out->printMessage(output::ERRO, "Unable to the port speed");
		return;
	}
	c->setPortSpeed(dq16);
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
