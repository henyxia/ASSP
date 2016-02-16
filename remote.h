// Protector
#ifndef __REMOTE_H__
#define __REMOTE_H__

// Defines
#define	CMD_OK					0x00
#define	CMD_NOT_KNOWN			0x01
#define CMD_DEST_UNREACHABLE	0x02
#define	CMD_LOCK_MIN_X1			0x03
#define CMD_LOCK_MAX_X1			0x04
#define CMD_LOCK_MIN_X2			0x05
#define CMD_LOCK_MAX_X2			0x06
#define CMD_LOCK_MIN_Y			0x07
#define CMD_LOCK_MAX_Y			0x08
#define CMD_LOCK_Z				0x09
#define WAIT_FOR_NEXT_FRAME		0x0A

// Include
#include "serial.h"

class remote
{
public:
	remote();
	~remote();
	bool	create();
	int		establishConnection();
	int		listAvailableInterfaces();
	qint16	getPositionX();
	QString	getPortName(int);
	qint16	getPortSpeed();
	qint8	getPumpState();
	qint16	getVersion();
	void	setPositionX(qint16);

private:
	serial*	s;
};
#endif
