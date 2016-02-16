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
