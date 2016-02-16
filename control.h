// Protector
#ifndef __CONTROL_H__
#define __CONTROL_H__

// Includes
#include <QDockWidget>
#include <QLineEdit>
#include <QVBoxLayout>

class control : public QDockWidget
{
public:
	control();
	~control();
	void	create();

private:
	QLineEdit*	portName;
	QLineEdit*	portSpeed;
	QLineEdit*	xPos;
	QLineEdit*	yPos;
	QLineEdit*	zPos;
	QLineEdit*	zTarget;
	QLineEdit*	speedTimeout;
	QLineEdit*	ms;
	QLineEdit*	pumpState;
	QLineEdit*	version;
};

#endif
