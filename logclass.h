// Protector
#ifndef LOGCLASS_H
#define LOGCLASS_H

// Includes
#include <QTextEdit>

// Class
class logClass
{
    // Con/Des structor
    public:
    logClass();
    ~logClass();

    // Public
    typedef enum severity
    {
        INFO = 0,
        WARN,
        VALI,
        ERRO
    }Severity;
    void    addOutput(QTextEdit*);
    void    printMessage(Severity, QString);

    // Private
    QTextEdit*  outputStream;
};

#endif
