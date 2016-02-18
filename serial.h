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
    int				listAvailableInterfaces();
	int				tryToConnect(int);
    QSerialPortInfo	lpi[256];
    int				lpii;
	qint16			getBaudRate();
	qint32			requestGet(quint8);
	void			requestSet(QByteArray, int);

private:
	int	checkAllowedVersion(qint8, qint8);
	QSerialPort*	pi;
};

#endif
