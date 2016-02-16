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

qint16 remote::getPortSpeed(int conn)
{
	return s->getBaudRate();
}
