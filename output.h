// Protector
#ifndef OUTPUT_H
#define OUTPUT_H

// Includes
#include <QTextEdit>

// Class
class output: public QTextEdit
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
