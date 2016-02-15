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
	/*
	QPushButton *button1 = new QPushButton("One");
	QLabel lab("Test");
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(button1);
	*/
	QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

	this->setMinimumWidth(150);
	this->setMaximumWidth(150);
	this->setLayout(layout);
	this->show();
}
