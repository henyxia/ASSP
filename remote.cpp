// Include
#include "remote.h"

remote::remote()
{
	s = NULL;
}

remote::~remote()
{
}

bool remote::create()
{
	s = new serial();
	return !(s == NULL);
}

int remote::listAvailableInterfaces()
{
	return s->listAvailableInterfaces();
}

int remote::establishConnection()
{
	int ret;

	for(int i=0; i<s->lpii; i++)
	{
		ret = s->tryToConnect(i);
		if(ret == 0)
			return i;
	}

	return -1;
}

QString remote::getPortName(int conn)
{
	return s->lpi[conn].portName();
}

qint16 remote::getPortSpeed()
{
	return s->getBaudRate();
}

qint16 remote::getVersion()
{
	QByteArray	versionQuery(1, (char)0x0F);
	return s->requestGet(versionQuery[0]);
}

qint8 remote::getPumpState()
{
	QByteArray	versionQuery(1, (char)0x0A);
	return s->requestGet(versionQuery[0]);
}

qint16 remote::getPositionX()
{
	QByteArray	versionQuery(1, (char)0x08);
	return s->requestGet(versionQuery[0]);
}

void remote::setPositionX(qint16 pos)
{
	QByteArray	destQ(3, (char)0x00);
	destQ[1] = (char) ((pos & 0xFF00) >> 8);
	destQ[2] = (char) (pos & 0x00FF);
	s->requestSet(destQ, 3);
}
