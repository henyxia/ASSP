// Protector
#ifndef __SERIALCLASS_H__
#define __SERIALCLASS_H__

// Include
#include <QtSerialPort/QSerialPortInfo>

// Class
class serial
{
public:
    serial();
    ~serial();
    int	listAvailableInterfaces();
	int	tryToConnect(int);
    int	lpii;
private:
	int	checkAllowedVersion(qint8, qint8);
    QSerialPortInfo lpi[256];
	QSerialPort*	pi;
};

#endif
