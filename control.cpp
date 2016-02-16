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
	QWidget*		wLay9 = new QWidget;
	QVBoxLayout*	mainLayout = new QVBoxLayout;
	QHBoxLayout*	lay1 = new QHBoxLayout;
	QHBoxLayout*	lay2 = new QHBoxLayout;
	QHBoxLayout*	lay3 = new QHBoxLayout;
	QHBoxLayout*	lay4 = new QHBoxLayout;
	QHBoxLayout*	lay5 = new QHBoxLayout;
	QHBoxLayout*	lay6 = new QHBoxLayout;
	QHBoxLayout*	lay7 = new QHBoxLayout;
	QHBoxLayout*	lay8 = new QHBoxLayout;
	QHBoxLayout*	lay9 = new QHBoxLayout;

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
	lay3->addWidget(l3lab1);
	lay3->addWidget(xPos);
	wLay3->setLayout(lay3);
	mainLayout->addWidget(wLay3);

	// Final Rendering
	mainLayout->setAlignment(Qt::AlignTop);
	contentContainer->setLayout(mainLayout);
	this->setMinimumWidth(150);
	this->setMaximumWidth(150);
	this->setWidget(contentContainer);
	this->show();
}
