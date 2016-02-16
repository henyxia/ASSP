// Include
#include "control.h"
#include <QLabel>
#include <QPushButton>

// Class
control::control()
{
}

control::~control()
{
}

void control::create()
{
	// Vars
	QWidget*		contentContainer = new QWidget;
	QWidget*		wLay1 = new QWidget;
	QWidget*		wLay2 = new QWidget;
	QWidget*		wLay3 = new QWidget;
	QWidget*		wLay4 = new QWidget;
	QWidget*		wLay5 = new QWidget;
	QWidget*		wLay6 = new QWidget;
	QWidget*		wLay7 = new QWidget;
	QWidget*		wLay8 = new QWidget;
	QVBoxLayout*	mainLayout = new QVBoxLayout;
	QHBoxLayout*	lay1 = new QHBoxLayout;
	QHBoxLayout*	lay2 = new QHBoxLayout;
	QHBoxLayout*	lay3 = new QHBoxLayout;
	QHBoxLayout*	lay4 = new QHBoxLayout;
	QHBoxLayout*	lay5 = new QHBoxLayout;
	QHBoxLayout*	lay6 = new QHBoxLayout;
	QHBoxLayout*	lay7 = new QHBoxLayout;
	QHBoxLayout*	lay8 = new QHBoxLayout;

	// Layer 1
	QPushButton *bConnect = new QPushButton("Connect");
	QPushButton *bRefresh = new QPushButton("Refresh");
	lay1->addWidget(bConnect);
	lay1->addWidget(bRefresh);
	wLay1->setLayout(lay1);
	mainLayout->addWidget(wLay1);

	// Layer 2
	QLabel* l2lab1 = new QLabel("Port");
	portName = new QLineEdit;
	portName->setReadOnly(true);
	portName->setPlaceholderText("NA");
	portSpeed = new QLineEdit;
	portSpeed->setReadOnly(true);
	portSpeed->setPlaceholderText("NA");
	lay2->addWidget(l2lab1);
	lay2->addWidget(portName);
	lay2->addWidget(portSpeed);
	wLay2->setLayout(lay2);
	mainLayout->addWidget(wLay2);

	// Layer 3
	QLabel* l3lab1 = new QLabel("X");
	xPos = new QLineEdit;
	xPos->setReadOnly(true);
	xPos->setPlaceholderText("NA");
	xTarget = new QLineEdit;
	xTarget->setReadOnly(true);
	xTarget->setPlaceholderText("NA");
	xMS = new QLineEdit;
	xMS->setReadOnly(true);
	xMS->setPlaceholderText("NA");
	xTimeout = new QLineEdit;
	xTimeout->setReadOnly(true);
	xTimeout->setPlaceholderText("NA");
	lay3->addWidget(l3lab1);
	lay3->addWidget(xPos);
	lay3->addWidget(xTarget);
	lay3->addWidget(xMS);
	lay3->addWidget(xTimeout);
	wLay3->setLayout(lay3);
	mainLayout->addWidget(wLay3);

	// Layer 4
	QLabel* l4lab1 = new QLabel("Y");
	yPos = new QLineEdit;
	yPos->setReadOnly(true);
	yPos->setPlaceholderText("NA");
	yTarget = new QLineEdit;
	yTarget->setReadOnly(true);
	yTarget->setPlaceholderText("NA");
	yMS = new QLineEdit;
	yMS->setReadOnly(true);
	yMS->setPlaceholderText("NA");
	yTimeout = new QLineEdit;
	yTimeout->setReadOnly(true);
	yTimeout->setPlaceholderText("NA");
	lay4->addWidget(l4lab1);
	lay4->addWidget(yPos);
	lay4->addWidget(yTarget);
	lay4->addWidget(yMS);
	lay4->addWidget(yTimeout);
	wLay4->setLayout(lay4);
	mainLayout->addWidget(wLay4);

	// Layer 5
	QLabel* l5lab1 = new QLabel("Z");
	zPos = new QLineEdit;
	zPos->setReadOnly(true);
	zPos->setPlaceholderText("NA");
	zTarget = new QLineEdit;
	zTarget->setReadOnly(true);
	zTarget->setPlaceholderText("NA");
	zMS = new QLineEdit;
	zMS->setReadOnly(true);
	zMS->setPlaceholderText("NA");
	zTimeout = new QLineEdit;
	zTimeout->setReadOnly(true);
	zTimeout->setPlaceholderText("NA");
	lay5->addWidget(l5lab1);
	lay5->addWidget(zPos);
	lay5->addWidget(zTarget);
	lay5->addWidget(zMS);
	lay5->addWidget(zTimeout);
	wLay5->setLayout(lay5);
	mainLayout->addWidget(wLay5);

	// Layer 6
	QLabel* l6lab1 = new QLabel("Pump State");
	pumpState = new QLineEdit;
	pumpState->setReadOnly(true);
	pumpState->setPlaceholderText("NA");
	lay6->addWidget(l6lab1);
	lay6->addWidget(pumpState);
	wLay6->setLayout(lay6);
	mainLayout->addWidget(wLay6);

	// Layer 7
	QLabel* l7lab1 = new QLabel("Locks");
	lay7->addWidget(l7lab1);
	wLay7->setLayout(lay7);
	mainLayout->addWidget(wLay7);

	// Layer 8
	QLabel* l8lab1 = new QLabel("Version");
	version = new QLineEdit;
	version->setReadOnly(true);
	version->setPlaceholderText("NA");
	lay8->addWidget(l8lab1);
	lay8->addWidget(version);
	wLay8->setLayout(lay8);
	mainLayout->addWidget(wLay8);

	// Final Rendering
	mainLayout->setAlignment(Qt::AlignTop);
	contentContainer->setLayout(mainLayout);
	this->setMinimumWidth(250);
	this->setMaximumWidth(250);
	this->setWidget(contentContainer);
	this->show();
}

void control::setPortName(QString pn)
{
	portName->setPlaceholderText(pn);
}

void control::setPortSpeed(int sp)
{
	portSpeed->setPlaceholderText(QString(QString::number(sp) + QObject::tr(" BPS")));
}

void control::setPositionX(qint16 pos)
{
	xPos->setPlaceholderText(QString::number(pos));
}

void control::setPositionY(qint16 pos)
{
	yPos->setPlaceholderText(QString::number(pos));
}

void control::setPositionZ(qint16 pos)
{
	zPos->setPlaceholderText(QString::number(pos));
}

void control::setPositionR(qint16 pos)
{
	rPos->setPlaceholderText(QString::number(pos));
}

void control::setTargetX(qint16 pos)
{
	xTarget->setPlaceholderText(QString::number(pos));
}

void control::setTargetY(qint16 pos)
{
	yTarget->setPlaceholderText(QString::number(pos));
}

void control::setTargetZ(qint16 pos)
{
	zTarget->setPlaceholderText(QString::number(pos));
}

void control::setTargetR(qint16 pos)
{
	rTarget->setPlaceholderText(QString::number(pos));
}

void control::setSpeedX(qint8 sp)
{
	xMS->setPlaceholderText(QString(QString::number(sp) + QObject::tr(" ms")));
}

void control::setSpeedY(qint8 sp)
{
	yMS->setPlaceholderText(QString(QString::number(sp) + QObject::tr(" ms")));
}

void control::setSpeedZ(qint8 sp)
{
	zMS->setPlaceholderText(QString(QString::number(sp) + QObject::tr(" ms")));
}

void control::setSpeedR(qint8 sp)
{
	rMS->setPlaceholderText(QString(QString::number(sp) + QObject::tr(" ms")));
}

void control::setMSX(qint8 microS)
{
	xMS->setPlaceholderText(QString(QObject::tr("1/") + QString::number(microS)));
}

void control::setMSY(qint8 microS)
{
	yMS->setPlaceholderText(QString(QObject::tr("1/") + QString::number(microS)));
}

void control::setMSZ(qint8 microS)
{
	zMS->setPlaceholderText(QString(QObject::tr("1/") + QString::number(microS)));
}

void control::setMSR(qint8 microS)
{
	rMS->setPlaceholderText(QString(QObject::tr("1/") + QString::number(microS)));
}

void control::setPumpState(bool st)
{
	pumpState->setPlaceholderText(st ? "On" : "Off");
}

void control::setVersion(qint8 major, qint8 minor)
{
	version->setPlaceholderText(QString(QString::number(major) + QObject::tr(".") + QString::number(minor)));
}
