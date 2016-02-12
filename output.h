// Protector
#ifndef __OUTPUT_H__
#define __OUTPUT_H__

// Includes
#include <QTextEdit>

// Class
class output: public QTextEdit
{
    // Con/Des structor
    public:
    output();
    ~output();

    // Public
    typedef enum severity
    {
        INFO = 0,
        WARN,
        VALI,
        ERRO
    }Severity;
    void    create(void);
    void    printMessage(Severity, QString);

    // Private
    QTextEdit*  outputStream;
};

#endif
