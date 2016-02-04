#include "output.h"

output::output()
{
    outputStream = NULL;
}

logClass::~logClass()
{
}

void logClass::addOutput(QTextEdit *out)
{
    outputStream = out;
}

void logClass::printMessage(Severity, QString msg)
{
    outputStream->moveCursor(QTextCursor::End);
    outputStream->insertPlainText(msg);
    outputStream->moveCursor(QTextCursor::End);
}
