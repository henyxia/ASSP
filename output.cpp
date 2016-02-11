#include "output.h"

output::output()
{
    outputStream = NULL;
}

output::~output()
{
}

void output::addOutput(QTextEdit *out)
{
    outputStream = out;
}

void output::printMessage(Severity, QString msg)
{
    outputStream->moveCursor(QTextCursor::End);
    outputStream->insertPlainText(msg);
    outputStream->moveCursor(QTextCursor::End);
}
