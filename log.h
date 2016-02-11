// Protector
#ifndef LOG_H
#define LOG_H

// Includes
#include <QDockWidget>
#include <QTextEdit>

#include "output.h"

// Class
class log : public QDockWidget
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
