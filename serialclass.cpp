#include "serialclass.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include "globals.h"

QT_USE_NAMESPACE

serialclass::serialclass()
{
}

serialclass::~serialclass()
{
}

int serialclass::listAvailableInterfaces()
{
    int av = 0;
    char data[3];

    // Creating portinfo
    QSerialPortInfo lpi[256];
    int lpii = 0;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        av++;
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
        output->printMessage(logClass::INFO, s);
        lpi[lpii] = info;
        lpii++;
    }

    output->printMessage(logClass::INFO, "Interfaces revealed : "+QString::number(av)+"\n");

    QSerialPort *port = new QSerialPort(lpi[0]);
    if(!port->open(QIODevice::ReadWrite))
    {
        output->printMessage(logClass::INFO, "Error while opening serial port\n");
        return -1;
    };

        port->setBaudRate(QSerialPort::Baud9600);
        //while(port->bytesAvailable() <= 0);
        QByteArray readData = port->readAll();
        while (port->waitForReadyRead(5000))
            readData.append(port->readAll());
        port->read(data, 3);
        output->printMessage(logClass::INFO, "HELLO ? : ");
        output->printMessage(logClass::INFO, data);
        output->printMessage(logClass::INFO, "\n");

    return av;
}
