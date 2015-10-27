#include "serialclass.h"
#include <QtSerialPort/QSerialPortInfo>
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

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        av++;
        QString s = QObject::tr("Port: ") + info.portName() + "\n"
                    + QObject::tr("Location: ") + info.systemLocation() + "\n"
                    + QObject::tr("Description: ") + info.description() + "\n"
                    + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                    + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                    + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";

        output->printMessage(logClass::INFO, s);
    }
    output->printMessage(logClass::INFO, "Interfaces revealed : "+QString::number(av)+"\n");
    return av;
}
