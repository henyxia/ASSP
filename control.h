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
	void	setPortName		(QString);
	void	setPortSpeed	(int);
	void	setPositionX	(qint16);
	void	setPositionY	(qint16);
	void	setPositionZ	(qint16);
	void	setTargetZ		(qint16);
	void	setSpeedTimeout	(qint8);
	void	setMicroStep	(qint8);
	void	setPumpState	(bool);
	void	setVersion		(qint8, qint8);

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
