// Includes
#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
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
// Globals
logClass* output = NULL;

// Main
int main(int argc, char *argv[])
{
    // Starting
    QApplication app(argc, argv);

    // Creating the log channel
    output = new logClass();

    // Displaying splashcreen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash"));
    splash->show();
    Qt::Alignment botLeft = Qt::AlignLeft | Qt::AlignBottom;

    // Creating the main window
    splash->showMessage(QObject::tr("Creating the main window..."), botLeft, Qt::white);
    MainWindow mainWin;
    qSleep(1000);
    splash->showMessage(QObject::tr("Dressing the main window..."), botLeft, Qt::white);
    mainWin.create();
    qSleep(1000);

    splash->showMessage(QObject::tr("Establishing connections..."), botLeft, Qt::white);
    //establishConnections();
    qSleep(3000);

    mainWin.show();
    output->printMessage(logClass::VALI, "ASSP Successfully started\n");
    //splash->finish(&mainWin);
    delete splash;

    //LoadingWindow w;
    //w.show();

    return app.exec();
}
