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
    int	lpii;
	int	tryToConnect(int);
private:
    QSerialPortInfo lpi[256];
	QSerialPort*	pi;
};

#endif
