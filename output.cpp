#include "output.h"

output::output()
{
    outputStream = NULL;
}

output::~output()
{
}

void output::create(void)
{
    this->setEnabled(false);
    this->setMinimumHeight(100);
    this->setMaximumHeight(100);
}

void output::printMessage(Severity, QString msg)
{
    this->moveCursor(QTextCursor::End);
    this->insertPlainText(msg);
    this->moveCursor(QTextCursor::End);
}
