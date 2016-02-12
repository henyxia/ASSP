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
    int listAvailableInterfaces();
private:
    QSerialPortInfo lpi[256];
};

#endif
