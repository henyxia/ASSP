#include "serial.h"
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QObject>

QT_USE_NAMESPACE

#ifdef Q_OS_WIN
#include <windows.h> // for sleep
#endif

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
	//QByteArray*	versionQuery = new QByteArray(1, (char)0x0F);
	QByteArray	versionQuery(1, (char)0x0F);
    QByteArray	raw;
	qint8		major;
	qint8		minor;

    pi = new QSerialPort(lpi[spi]);

    if(!pi->open(QIODevice::ReadWrite))
        return -1;
	qSleep(1500);
    pi->write(versionQuery);

    if(pi->waitForReadyRead(10000))
	{
        raw = pi->readAll();
		minor = raw[0] >> 4;
		//if(pi->waitForReadyRead(10000))
		//{
        //raw = pi->read(1);
		major = raw[1];
		//QString response(raw);
	    QString s = QObject::tr("Connected to MEGA ver ") +
			QString::number(major) + QObject::tr(".") + QString::number(minor);
		QMessageBox msgB(QMessageBox::Critical, "Working !", s);
		msgB.exec();
		//}
		//else
		//{
		//    QString s = QObject::tr("Uncomplete version data (minor:") +
		//		QString::number(minor) + QObject::tr(")");
		//	QMessageBox msgB(QMessageBox::Critical, "Warning !", s);
		//	msgB.exec();
		//
		//}
	}
	else
	{
		QMessageBox msgB(QMessageBox::Critical, "Critical error",
				"Unable to read data");
		msgB.exec();

	}
/*
    QString s = QObject::tr("LEN[") + QString::number(read) + "]" + QObject::tr("DATA[")
            + data + QObject::tr("DATA[");*/


    return 0;

}
