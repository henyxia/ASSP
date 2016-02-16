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
	void	setPositionR	(qint16);
	void	setTargetX		(qint16);
	void	setTargetY		(qint16);
	void	setTargetZ		(qint16);
	void	setTargetR		(qint16);
	void	setSpeedX		(qint8);
	void	setSpeedY		(qint8);
	void	setSpeedZ		(qint8);
	void	setSpeedR		(qint8);
	void	setMSX			(qint8);
	void	setMSY			(qint8);
	void	setMSZ			(qint8);
	void	setMSR			(qint8);
	void	setPumpState	(bool);
	void	setVersion		(qint8, qint8);

private:
	QLineEdit*	portName;
	QLineEdit*	portSpeed;
	QLineEdit*	xPos;
	QLineEdit*	xTarget;
	QLineEdit*	xMS;
	QLineEdit*	xTimeout;
	QLineEdit*	yPos;
	QLineEdit*	yTarget;
	QLineEdit*	yMS;
	QLineEdit*	yTimeout;
	QLineEdit*	zPos;
	QLineEdit*	zTarget;
	QLineEdit*	zMS;
	QLineEdit*	zTimeout;
	QLineEdit*	rPos;
	QLineEdit*	rTarget;
	QLineEdit*	rMS;
	QLineEdit*	rTimeout;
	QLineEdit*	pumpState;
	QLineEdit*	version;
};

#endif
