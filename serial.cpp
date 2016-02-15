// Includes
#include "serial.h"
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QObject>

// Conditionnal include
#ifdef Q_OS_WIN
#include <windows.h> // for sleep
#endif

// Qt Namespace
QT_USE_NAMESPACE

// Platform independent sleep
void qSleep(int ms)
{
#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
}

serial::serial()
{
}

serial::~serial()
{
}

int serial::listAvailableInterfaces()
{
    // Creating portinfo
    lpii = 0;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        /*
        QString s = QObject::tr("Port: ") + info.portName() + "\n"
                    + QObject::tr("Location: ") + info.systemLocation() + "\n"
                    + QObject::tr("Description: ") + info.description() + "\n"
                    + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                    + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                    + QObject::tr("Vendor Identifier: ")
                    + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Product Identifier: ")
                    + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";
                    */
        lpi[lpii] = info;
        lpii++;
    }

    //output->printMessage(logClass::INFO, "Interfaces revealed : "+QString::number(av)+"\n");
/*
    QSerialPort *port = new QSerialPort(lpi[0]);
    if(!port->open(QIODevice::ReadWrite))
    {
        //output->printMessage(logClass::INFO, "Error while opening serial port\n");
        return -1;
    };

        port->setBaudRate(QSerialPort::Baud9600);
        //while(port->bytesAvailable() <= 0);
        QByteArray readData = port->readAll();
        while (port->waitForReadyRead(5000))
            readData.append(port->readAll());
        port->read(data, 3);
        //output->printMessage(logClass::INFO, "HELLO ? : ");
        //output->printMessage(logClass::INFO, data);
        //output->printMessage(logClass::INFO, "\n");
*/
    return lpii;
}

int serial::tryToConnect(int spi)
{
	int			ret;
	QByteArray	versionQuery(1, (char)0x0F);
    QByteArray	raw;
	qint8		major;
	qint8		minor;

    pi = new QSerialPort(lpi[spi]);

    if(!pi->open(QIODevice::ReadWrite))
        return -1;
	qSleep(2000);
    pi->write(versionQuery);

    if(pi->waitForReadyRead(100))
	{
        raw = pi->readAll();
		minor = raw[0] >> 4;
		major = raw[1];
		ret = checkAllowedVersion(major, minor);
		if(ret != 0)
			return -1;
	    //QString s = QObject::tr("Connected to MEGA ver ") +
		//	QString::number(major) + QObject::tr(".") + QString::number(minor);
		//QMessageBox msgB(QMessageBox::Critical, "Working !", s);
		//msgB.exec();
	}
	else
	{
		/*
		QMessageBox msgB(QMessageBox::Critical, "Critical error",
			"Unable to read data");
		msgB.exec();
		*/
		return -2;
	}

    return 0;
}

int serial::checkAllowedVersion(qint8 maj, qint8 min)
{
	// Basic checking
	if(maj == 0 && min == 1)
		return 0;
	return -1;
}
