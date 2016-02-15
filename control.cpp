// Include
#include "control.h"
#include <QLabel>

// Class
control::control()
{
}

control::~control()
{
}

void control::create()
{
	QLabel lab("Test");
	mainLayout = new QVBoxLayout();
	mainLayout->addWidget(&lab);
	this->setLayout(mainLayout);
}
