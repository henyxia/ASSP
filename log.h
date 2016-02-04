// Protector
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes
#include <QDockWidget>
#include <QTextEdit>

#include "output.h"

// Class
class logAAA : public QDockWidget
{
    // Con/Des structor
    public:
    log();
    ~log();

    // Public
	void create(void);
	output* out;
};

#endif
