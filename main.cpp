#include "loadingwindow.h"
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

int main(int argc, char *argv[])
{
    // Starting
    QApplication app(argc, argv);

    // Displaying splashcreen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash"));
    splash->show();

    Qt::Alignment botLeft = Qt::AlignLeft | Qt::AlignBottom;
    splash->showMessage(QObject::tr("Setting up the main window..."),
                               botLeft, Qt::white);
    //MainWindow mainWin;
    splash->showMessage(QObject::tr("Loading modules..."),
                               botLeft, Qt::white);
    //loadModules();
    qSleep(3000);

    splash->showMessage(QObject::tr("Establishing connections..."),
                               botLeft, Qt::white);
    //establishConnections();
    qSleep(3000);

    //mainWin.show();
    //splash->finish(&mainWin);
    delete splash;

    //LoadingWindow w;
    //w.show();

    return app.exec();
}
