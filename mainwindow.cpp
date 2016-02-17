// Includes
#include "mainwindow.h"
#include <QMessageBox>
#include <QDialogButtonBox>
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

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
	if(event->type() == QEvent::MouseButtonDblClick)
	{
		QDialog dlg;
        QVBoxLayout la(&dlg);
		//TODO
		// Add number only input
        QLineEdit ed;
        la.addWidget(&ed);
        QDialogButtonBox bb;
		bb.addButton(tr("OK"), QDialogButtonBox::AcceptRole);
        la.addWidget(&bb);

		// Connecting
		connect(&bb, SIGNAL(accepted()), &dlg, SLOT(accept()));

        dlg.setLayout(&la);
        if(dlg.exec() == QDialog::Accepted)
		{
			if(obj == c->xTarget)
				r->setPositionX(ed.text().toInt());
			else if(obj == c->yTarget)
				r->setPositionY(ed.text().toInt());
			else if(obj == c->zTarget)
				r->setPositionZ(ed.text().toInt());
			else if(obj == c->rTarget)
				r->setPositionR(ed.text().toInt());
		}
	    return true;
	}

    // Standard event processing
    return QObject::eventFilter(obj, event);
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
		}
		else
		{
			l->out->printMessage(output::VALI, QString(
				QObject::tr("Connect established with serial connection ")
				+ QString::number(ret) + "\n"));
			refreshControlPanel(ret);
		}
	}

	// Establishing connections
	c->xTarget->installEventFilter(this);
	c->yTarget->installEventFilter(this);
	c->zTarget->installEventFilter(this);
	//TODO
	//c->rTarget->installEventFilter(this);

    return true;
}

void MainWindow::changeTarget(void)
{
	int ret = c->xTarget->text().toInt();
	l->out->printMessage(output::VALI, QString(
		QObject::tr("Setting new X Target ")
		+ QString::number(ret) + "\n"));
	r->setPositionX(c->xTarget->text().toInt());
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
		l->out->printMessage(output::ERRO, "Unable to get the port name");
		return;
	}
	c->setPortName(dqs);

	// Port Speed
	dq16 = r->getPortSpeed();
	if(dq16 <= 0)
	{
		l->out->printMessage(output::ERRO, "Unable to get the port speed\n");
		return;
	}
	c->setPortSpeed(dq16);

	// X Pos
	dq16 = r->getPositionX();
	if(dq16 < 0)
	{
		l->out->printMessage(output::ERRO, "Unable to get X position\n");
		return;
	}
	c->setPositionX(dq16 >> 8);

	// Y Pos
	//dq16 = r->getPositionY();

	// Z Pos
	//dq16 = r->getPositionZ();

	// Z Target
	//dq16 = r->getTargetZ();
	
	// Speed Timeout (ToDo XYZR)
	//dq8 = r->getSpeedTimeout();

	// Pump
	dq8 = r->getPumpState();
	if(dq8 < 0)
	{
		l->out->printMessage(output::ERRO, "Unable to get the pump state\n");
		return;
	}
	c->setPumpState((dq8 & 0x10) == 0x10);
	
	// Locks
	//dq8 = r->getLockState();

	// Version
	dq16 = r->getVersion();
	if(dq16 <= 0)
	{
		l->out->printMessage(output::ERRO, "Unable to get the running version");
		return;
	}
	c->setVersion(dq16 & 0x00FF, (dq16 & 0x0F00)>>8);

	//TEMP
	r->setPositionX(1000);
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
