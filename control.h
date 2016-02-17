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
	void		create();
	void		setPortName		(QString);
	void		setPortSpeed	(int);
	void		setPositionX	(qint16);
	void		setPositionY	(qint16);
	void		setPositionZ	(qint16);
	void		setPositionR	(qint16);
	void		setTargetX		(qint16);
	void		setTargetY		(qint16);
	void		setTargetZ		(qint16);
	void		setTargetR		(qint16);
	void		setSpeedX		(qint8);
	void		setSpeedY		(qint8);
	void		setSpeedZ		(qint8);
	void		setSpeedR		(qint8);
	void		setMSX			(qint8);
	void		setMSY			(qint8);
	void		setMSZ			(qint8);
	void		setMSR			(qint8);
	void		setPumpState	(bool);
	void		setVersion		(qint8, qint8);
	QLineEdit*	xTarget;
	QLineEdit*	yTarget;
	QLineEdit*	zTarget;
	QLineEdit*	rTarget;

private:
	qint8		pov(qint8);
	QLineEdit*	portName;
	QLineEdit*	portSpeed;
	QLineEdit*	xPos;
	QLineEdit*	yPos;
	QLineEdit*	zPos;
	QLineEdit*	rPos;
	QLineEdit*	xMS;
	QLineEdit*	yMS;
	QLineEdit*	zMS;
	QLineEdit*	rMS;
	QLineEdit*	xTimeout;
	QLineEdit*	yTimeout;
	QLineEdit*	zTimeout;
	QLineEdit*	rTimeout;
	QLineEdit*	pumpState;
	QLineEdit*	version;
};

#endif
